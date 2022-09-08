#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111111, inf = 111111111;

int n, f[max_n];
string s;
char c[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < max_n; ++i) {
        f[i] = 0;
        c[i] = 'Q';
    }
    int len = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (len == 0) {
            len = s.length();
        }
        for (int j = 0; j < len; ++j) {
            if (s[j] != '?') {
                if (f[j] == 0) {
                    c[j] = s[j];
                    f[j] = 1;
                } else {
                    if (s[j] != c[j]) {
                        c[j] = '?';
                    }
                }
            }
        }
    }
    for (int i = 0; i < len; ++i) {
        if (c[i] != 'Q') {
            cout << c[i];
        } else {
            cout << 'a';
        }
    }
    return 0;
}