// ascii.hpp
// This file contains the letter class and the letter map that define which character corrseponds to which ascii art character
#ifndef ASCII_H
#define ASCII_H

#include <map>
#include <vector>
#include <string_view>
#include <string>

class Letter {
public:
    Letter(std::string_view l) : width_(0) {
        auto b = l.begin();
        for(auto it = b; it != l.end(); ++it) {
            if(*it == '\n') {
                auto w = it - b;
                if(w > width_) width_ = w;
                svs.emplace_back(b, w);
                b = it + 1;
            }
        }
        auto w = l.end() - b;
        if(w > width_) width_ = w;
        svs.emplace_back(b, w);
    }

    unsigned width() const { return width_; }
    unsigned height() const { return svs.size(); }

    std::string operator()(unsigned line) const {
        if(line >= svs.size()) return std::string(width_, ' ');
        return std::string(svs[line]) + std::string(width_ - svs[line].size(), ' ');
    }

private:
    std::vector<std::string_view> svs;
    unsigned width_;
};

extern unsigned gradientIndex;
void generate_ascii_art(const std::string& text, const std::vector<std::string>& colors);


inline std::map<char, Letter> letters = {
    {'a', Letter(R"(
░█████╗░
██╔══██╗
███████║
██╔══██║
██║░░██║
╚═╝░░╚═╝
)")},
    {'b', Letter(R"(
██████╗░
██╔══██╗
██████╦╝
██╔══██╗
██████╦╝
╚═════╝░
)")},
    {'c', Letter(R"(
░█████╗░
██╔══██╗
██║░░╚═╝
██║░░██╗
╚█████╔╝
░╚════╝░
)")},
    {'d', Letter(R"(
██████╗░
██╔══██╗
██║░░██║
██║░░██║
██████╔╝
╚═════╝░
)")},
    {'e', Letter(R"(
███████╗
██╔════╝
█████╗░░
██╔══╝░░
███████╗
╚══════╝
)")},
    {'f', Letter(R"(
███████╗
██╔════╝
█████╗░░
██╔══╝░░
██║░░░░░
╚═╝░░░░░
)")},
    {'g', Letter(R"(
░██████╗░
██╔════╝░
██║░░██╗░
██║░░╚██╗
╚██████╔╝
░╚═════╝░
)")},
    {'h', Letter(R"(
██╗░░██╗
██║░░██║
███████║
██╔══██║
██║░░██║
╚═╝░░╚═╝
)")},
    {'i', Letter(R"(
██╗
██║
██║
██║
██║
╚═╝
)")},
    {'j', Letter(R"(
░░░░░██╗
░░░░░██║
░░░░░██║
██╗░░██║
╚█████╔╝
░╚════╝░
)")},
    {'k', Letter(R"(
██╗░░██╗
██║░██╔╝
█████═╝░
██╔═██╗░
██║░╚██╗
╚═╝░░╚═╝
)")},
    {'l', Letter(R"(
██╗░░░░░
██║░░░░░
██║░░░░░
██║░░░░░
███████╗
╚══════╝
)")},
    {'m', Letter(R"(
███╗░░░███╗
████╗░████║
██╔████╔██║
██║╚██╔╝██║
██║░╚═╝░██║
╚═╝░░░░░╚═╝
)")},
    {'n', Letter(R"(
███╗░░██╗
████╗░██║
██╔██╗██║
██║╚████║
██║░╚███║
╚═╝░░╚══╝
)")},
    {'o', Letter(R"(
░█████╗░
██╔══██╗
██║░░██║
██║░░██║
╚█████╔╝
░╚════╝░
)")},
    {'p', Letter(R"(
██████╗░
██╔══██╗
██████╔╝
██╔═══╝░
██║░░░░░
╚═╝░░░░░
)")},
    {'q', Letter(R"(
░██████╗░
██╔═══██╗
██║██╗██║
╚██████╔╝
░╚═██╔═╝░
░░░╚═╝░░░
)")},
    {'r', Letter(R"(
██████╗░
██╔══██╗
██████╔╝
██╔══██╗
██║░░██║
╚═╝░░╚═╝
)")},
    {'s', Letter(R"(
░██████╗
██╔════╝
╚█████╗░
░╚═══██╗
██████╔╝
╚═════╝░
)")},
    {'t', Letter(R"(
████████╗
╚══██╔══╝
░░░██║░░░
░░░██║░░░
░░░██║░░░
░░░╚═╝░░░
)")},
    {'u', Letter(R"(
██╗░░░██╗
██║░░░██║
██║░░░██║
██║░░░██║
╚██████╔╝
░╚═════╝░
)")},
    {'v', Letter(R"(
██╗░░░██╗
██║░░░██║
╚██╗░██╔╝
░╚████╔╝░
░░╚██╔╝░░
░░░╚═╝░░░
)")},
    {'w', Letter(R"(
░██╗░░░░░░░██╗
░██║░░██╗░░██║
░╚██╗████╗██╔╝
░░████╔═████║░
░░╚██╔╝░╚██╔╝░
░░░╚═╝░░░╚═╝░░
)")},
    {'x', Letter(R"(
██╗░░██╗
╚██╗██╔╝
░╚███╔╝░
░██╔██╗░
██╔╝╚██╗
╚═╝░░╚═╝
)")},
    {'y', Letter(R"(
██╗░░░██╗
╚██╗░██╔╝
░╚████╔╝░
░░╚██╔╝░░
░░░██║░░░
░░░╚═╝░░░
)")},
    {'z', Letter(R"(
███████╗
╚════██║
░░███╔═╝
██╔══╝░░
███████╗
╚══════╝
)")},
    {'0', Letter(R"(
░█████╗░
██╔══██╗
██║░░██║
██║░░██║
╚█████╔╝
░╚════╝░
)")},
    {'1', Letter(R"(
░░███╗░░
░████║░░
██╔██║░░
╚═╝██║░░
███████╗
╚══════╝
)")},
    {'2', Letter(R"(
██████╗░
╚════██╗
░░███╔═╝
██╔══╝░░
███████╗
╚══════╝
)")},
    {'3', Letter(R"(
██████╗░
╚════██╗
░█████╔╝
░╚═══██╗
██████╔╝
╚═════╝░
)")},
    {'4', Letter(R"(
░░██╗██╗
░██╔╝██║
██╔╝░██║
███████║
╚════██║
░░░░░╚═╝
)")},
    {'5', Letter(R"(
███████╗
██╔════╝
██████╗░
╚════██╗
██████╔╝
╚═════╝░
)")},
    {'6', Letter(R"(
░█████╗░
██╔═══╝░
██████╗░
██╔══██╗
╚█████╔╝
░╚════╝░
)")},
    {'7', Letter(R"(
███████╗
╚════██║
░░░░██╔╝
░░░██╔╝░
░░██╔╝░░
░░╚═╝░░░
)")},
    {'8', Letter(R"(
░█████╗░
██╔══██╗
╚█████╔╝
██╔══██╗
╚█████╔╝
░╚════╝░
)")},
    {'9', Letter(R"(
░█████╗░
██╔══██╗
╚██████║
░╚═══██║
░█████╔╝
░╚════╝░
)")},
    {'!', Letter(R"(
██╗
██║
██║
╚═╝
██╗
╚═╝
)")},
    {'"', Letter(R"(
██╗██╗
╚█║╚█║
░╚╝░╚╝
░░░░░░
░░░░░░
░░░░░░
)")},
    {'#', Letter(R"(
░░░██╗░██╗░
██████████╗
╚═██╔═██╔═╝
██████████╗
╚██╔═██╔══╝
░╚═╝░╚═╝░░░
)")},
    {'$', Letter(R"(
░███████╗
██╔██╔══╝
╚██████╗░
░╚═██╔██╗
███████╔╝
╚══════╝░
)")},
    {'%', Letter(R"(
██╗░██╗
╚═╝██╔╝
░░██╔╝░
░██╔╝░░
██╔╝██╗
╚═╝░╚═╝
)")},
    {'\'', Letter(R"(
██╗
╚█║
░╚╝
░░░
░░░
░░░
)")},
    {'(', Letter(R"(
░░██╗
░██╔╝
██╔╝░
╚██╗░
░╚██╗
░░╚═╝
)")},
    {')', Letter(R"(
██╗░░
╚██╗░
░╚██╗
░██╔╝
██╔╝░
╚═╝░░
)")},
    {'+', Letter(R"(
░░░░░░░
░░██╗░░
██████╗
╚═██╔═╝
░░╚═╝░░
░░░░░░░
)")},
    {',', Letter(R"(
░░░
░░░
░░░
██╗
╚█║
░╚╝
)")},
    {'-', Letter(R"(
░░░░░░
░░░░░░
█████╗
╚════╝
░░░░░░
░░░░░░
)")},
    {'.', Letter(R"(
░░░
░░░
░░░
░░░
██╗
╚═╝
)")},
    {'/', Letter(R"(
░░░░██╗
░░░██╔╝
░░██╔╝░
░██╔╝░░
██╔╝░░░
╚═╝░░░░
)")},
};


#endif // ASCII_H

