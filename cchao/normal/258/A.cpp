#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    bool fg = false;
    for(int i = 0; i < s.size() - 1; ++i) {
        if(s[i] == '0' && !fg) {
            fg = true;
        }
        else putchar(s[i]);
    }
    if(fg) putchar(s[s.size()-1]);
    puts("");

    return 0;
}