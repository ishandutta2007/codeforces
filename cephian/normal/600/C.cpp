#include <iostream>

using namespace std;

int let[26];

int main() {
    for(int i = 0; i < 26; ++i)
        let[i] = 0;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); ++i)
        ++let[s[i] - 'a'];

    int odd = 0;
    for(int i = 0; i < 26; ++i)
        if(let[i] & 1)
            ++odd;
    for(int i = 25, j = 0; i >=0 && j < odd/2; --i) {
        if(let[i] & 1) {
            --let[i];
            ++j;
        }
    }
    for(int i = 0, j = 0; i < 26 && j < odd/2; ++i) {
        if(let[i] & 1) {
            ++let[i];
            ++j;
        }
    }

    string ans = "";
    for(int i = 0; i < 26; ++i) {
        for(int j = 0; j < let[i]/2; ++j)
            ans += char('a' + i);
    }
        for(int i = 0; i < 26; ++i)
            if(let[i] & 1)
                    ans += char('a' + i);

    for(int i = 25; i >= 0; --i) {
        for(int j = 0; j < let[i]/2; ++j)
            ans += char('a' + i);
    }
    cout << ans << "\n";

    return 0;
}