#include <iostream>
#include <cstdio>
#include <vector>
#include <memory.h>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

void solve() {
    string s;
    cin >> s;
    
    int first = 0;
    for (char c = 'z'; c >= 'a'; c--) {
        for (int i = first; i < s.length(); i++) 
            if (s[i] == c) {
                printf("%c", c);
                first = i + 1;
            }
    }
    cout << endl;
}

int main() {
    solve();

    return 0;
}