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

string n, mx[11][11], mn[11][11];

bool ok(string s) {
    int a = 0, b = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '4') {
            ++a;
        } else if (s[i] == '7') {
            ++b;
        } else {
            return false;
        }
    }
    return a == b;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    if (ok(n)) {
        cout << n << endl;
        return 0;
    }
    if (n.length() % 2 == 0) {
        string a;
        int len = n.length() / 2;
        for (int i = 0; i < len; ++i) {
            a += '7';
        }
        for (int i = 0; i < len; ++i) {
            a += '4';
        }
        if (n <= a) {
            for (int i = 0; i < 11; ++i) {
                for (int j = 0; j < 11; ++j) {
                    for (int k = 0; k < j; ++k) {
                        mx[i][j] += '7';
                        mn[i][j] += '4';
                    }
                    for (int k = 0; k < i; ++k) {
                        mn[i][j] += '7';
                        mx[i][j] += '4';
                    }
                }
            }
            string res;
            int x = len, y = len;
            for (int i = 0; i < n.length(); ++i) {
                if (x > 0) {
                    string q = res;
                    q += '4';
                    q += mx[x - 1][y];
                    if (n <= q) {
                        res += '4';
                        --x;
                    } else {
                        res += '7';
                        --y;
                    }
                } else {
                    --y;
                    res += '7';
                }
            }
            cout << res << endl;
        } else {
            for (int i = 0; i <= len; ++i) {
                cout << 4;
            }
            for (int i = 0; i <= len; ++i) {
                cout << 7;
            }
        }
    } else {
        int len = n.length() / 2 + 1;
        for (int i = 0; i < len; ++i) {
            cout << 4;
        }
        for (int i = 0; i < len; ++i) {
            cout << 7;
        }
        cout << endl;
    }
    return 0;
}