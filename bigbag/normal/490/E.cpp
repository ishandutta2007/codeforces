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

const int max_n = 101111, inf = 1111111111;

int n, dp[20];
string s[max_n];

void get_min(int num) {
    if (s[num][0] == '?') {
        s[num][0] = '1';
    }
    for (int i = 1; i < s[num].length(); ++i) {
        if (s[num][i] == '?') s[num][i] = '0';
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    get_min(0);
    for (int i = 1; i < n; ++i) {
        if (s[i - 1].length() > s[i].length()) {
            cout << "NO" << endl;
            return 0;
        } else if (s[i - 1].length() < s[i].length()) {
            get_min(i);
        } else {
            int len = s[i].length();
            for (int j = 0; j < 13; ++j) {
                dp[j] = 0;
            }
            for (int j = len - 1; j >= 0; --j) {
                if (s[i][j] == '?') {
                    if (dp[j + 1] == 1 || s[i - 1][j] < '9') {
                        dp[j] = 1;
                    }
                } else {
                    if (s[i][j] > s[i - 1][j]) {
                        dp[j] = 1;
                    }
                    if (s[i][j] == s[i - 1][j] && dp[j + 1] == 1) {
                        dp[j] = 1;
                    }
                }
            }
            if (dp[0] == 0) {
                cout << "NO" << endl;
                return 0;
            }
            int f = 0;
            for (int j = 0; j < len; ++j) {
                if (s[i][j] == '?') {
                    if (f == 1) {
                        s[i][j] = '0';
                    } else if (dp[j + 1]) {
                        s[i][j] = s[i - 1][j];
                    } else {
                        s[i][j] = s[i - 1][j] + 1;
                        f = 1;
                    }
                } else {
                    if (s[i][j] > s[i - 1][j]) f = 1;
                }
            }
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
        cout << s[i] << endl;
    }
    return 0;
}