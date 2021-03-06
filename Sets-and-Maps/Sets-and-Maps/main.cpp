#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <iomanip>

// Used for Part1
// Display the word and count from the 
// std::map<std::string, int>

void display_words(const std::map<std::string, int> &words) {
    std::cout << std::setw(12) << std::left << "\nWord"
        << std::setw(7) << std::right << "Count" << std::endl;
    std::cout << "===============================================" << std::endl;
    for (auto pair : words)
        std::cout << std::setw(12) << std::left << pair.first
        << std::setw(7) << std::right << pair.second << std::endl;
}

// Used for Part2
// Display the word and occurences from the 
// std::map<std::string, std::set<int>>

void display_words(const std::map<std::string, std::set<int>> &words) {
    std::cout << std::setw(12) << std::left << "\nWord"
        << "Occurrences" << std::endl;
    std::cout << "===============================================" << std::endl;
    for (auto pair : words) {
        std::cout << std::setw(12) << std::left << pair.first
            << std::left << "[ ";
        for (auto i : pair.second)
            std::cout << i << " ";
        std::cout << "]" << std::endl;
    }
}

// This function removes periods, commas, semicolons and colon in 
// a string and returns the clean version
std::string clean_string(const std::string &s) {
    std::string result;
    for (char c : s) {
        if (c == '.' || c == ',' || c == ';' || c == ':')
            continue;
        else
            result += c;
    }
    return result;
}

// Part1 process the file and builds a map of words and the 
// number of times they occur in the file

void part1() {
    std::map<std::string, int> words;
    std::string line;
    std::string word;
    std::ifstream in_file{"./WizardOfOz.txt"};
    if (in_file) {
        // You implement this code
        while (std::getline(in_file, line)) {
            std::stringstream string_stream(line);

            while (string_stream >> word) {
                word = clean_string(word);
                words[word]++;
            }
        }

        in_file.close();
        display_words(words);
    } else {
        std::cerr << "Error opening input file" << std::endl;
    }
}

// Part2 process the file and builds a map of words and a 
// set of line numbers in which the word appears
void part2() {
    std::map<std::string, std::set<int>> words;
    std::string line;
    std::string word;
    std::ifstream in_file{"./WizardOfOz.txt"};
    if (in_file) {
        // You implement this code
        int line_num{0};
        while (std::getline(in_file, line)) {
            line_num++;
            std::stringstream string_stream(line);
            while (string_stream >> word) {
                word = clean_string(word);
                words[word].insert(line_num);
            }
        }

        in_file.close();
        display_words(words);
    } else {
        std::cerr << "Error opening input file" << std::endl;
    }
}

void display_menu() {
    int selection;

    std::cout << "\n===============================================================" << std::endl;
    std::cout << "Wizard of Oz (first few paragraphs) Reader" << std::endl << std::endl;
    std::cout << "1 -- Display the words and their occurances (part 1)" << std::endl;
    std::cout << "2 -- Display the words, and the lines they appear on (part 2)" << std::endl;
    std::cout << "3 -- Quit" << std::endl;
}

int main() {

    int selection{};

    do {
        display_menu();

        std::cout << "What would you like to do?: ";
        std::cin >> selection;
        std::cout << std::endl;

        if (selection == 1) {
            part1();
        }
        else if (selection == 2) {
            part2();
        }
        else if (selection == 3) {
            std::cout << "Goodbye!" << std::endl;
        }
        else {
            std::cout << "Invalid Option" << std::endl;
        }
    } while (selection != 3);
    return 0;
}

