#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

string read(const string& s, size_t& offset) {
    string res;
    int b(0);
    while (offset < s.size() && (s[offset] != ' ' || b != 0)) {
        b ^= s[offset] == '"';
        res += s[offset];
        ++offset;
    }
    ++offset;
    return res;
}

int main() {
    string s;
    getline(cin, s);
    vector<string> v;
    size_t offset(0);
    while (offset < s.length()) {
        string sub = read(s, offset);
        if (sub.length()) {
            if (sub[0] == '"') sub = sub.substr(1, sub.length() - 2);
            v.push_back(sub);
        }
    }
    for (size_t i = 0; i < v.size(); ++i)
        puts(("<" + v[i] + ">").c_str());
    return 0;
}