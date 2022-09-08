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

const int max_n = 11, inf = 1011111111;

int n = 4;
string s[max_n];

bool ok() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            string a = "", b = "";
            for (int k = 0; k < 3; ++k) {
                a += s[i][j + k];
                b += s[j + k][i];
            }
            if (a == "xxx" || b == "xxx") {
                return true;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            string a = "";
            for (int k = 0; k < 3 && i + k < n && j + k < n; ++k) {
                a += s[i + k][j + k];
            }
            if (a == "xxx") {
                return true;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            string a = "";
            for (int k = 0; k < 3 && i + k < n && j - k >= 0; ++k) {
                a += s[i + k][j - k];
            }
            if (a == "xxx") {
                return true;
            }
        }
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == '.') {
                s[i][j] = 'x';
                if (ok()) {
                    cout << "YES" << endl;
                    return 0;
                }
                s[i][j] = '.';
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}