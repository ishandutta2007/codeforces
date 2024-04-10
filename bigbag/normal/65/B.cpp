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

const int max_n = 1111, inf = 111111111;

int n;
string s[max_n];

bool good(string s1, string s2) {
    for (int i = 0; i < 4; ++i) {
        if (s1[i] != s2[i]) {
            return s1[i] > s2[i];
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    if (s[0][0] == '1') {
        if (s[0][1] == '0') {
            if (s[0][2] == '0') {
                s[0][3] = '0';
            } else {
                s[0][2] = '0';
            }
        } else {
            s[0][1] = '0';
        }
    } else {
        s[0][0] = '1';
    }
    for (int i = 1; i < n; ++i) {
        string q = "9999";
        for (int j = 0; j < 4; ++j) {
            for (int x = 0; x <= 9; ++x) {
                string q2 = s[i];
                q2[j] = x + '0';
                if (good(q2, s[i - 1]) && good(q, q2)) {
                    q = q2;
                }
            }
        }
        s[i] = q;
        if (s[i] == "9999" || (s[i - 1] != s[i] && good(s[i - 1], s[i])) || good(s[i], "2012") || good(s[0], "2012")) {
            cout << "No solution" << endl;
            return 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << s[i] << endl;
    }
    return 0;
}