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

const int max_n = 111, inf = 111111111;

string s;
int n, k, dp[max_n][max_n][max_n], bon[max_n][max_n], pp[max_n][max_n][max_n];
char cc[max_n][max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s >> k >> n;
    for (int i = 0; i < n; ++i) {
        char c1, c2;
        int b;
        cin >> c1 >> c2 >> b;
        bon[c1 - 'a'][c2 - 'a'] = b;
    }
    int ans = 0;
    for (int i = 0; i + 1 < s.length(); ++i) {
        ans += bon[s[i] - 'a'][s[i + 1] - 'a'];
    }
    if (k == 0) {
        cout << ans << endl;
        return 0;
    }
    //dp[0][0] = 0;
    for (int i = 1; i < s.length(); ++i) {
        for (int j = 0; j <= min(k, i + 1); ++j) {
            for (char c = 'a'; c <= 'z'; ++c) {
                dp[i][j][c - 'a'] = -inf;
            }
        }
    }
    for (int i = 0; i + 1 < s.length(); ++i) {
        for (int j = 0; j <= min(k, i + 1); ++j) {
            for (char c = 'a'; c <= 'z'; ++c) {
                if (j != 0 || j == 0 && c == s[i]) {
                    for (char c2 = 'a'; c2 <= 'z'; ++c2) {
                        if (c2 == s[i + 1]) {
                            if (dp[i + 1][j][c2 - 'a'] < dp[i][j][c - 'a'] + bon[c - 'a'][c2 - 'a']) {
                                dp[i + 1][j][c2 - 'a'] = dp[i][j][c - 'a'] + bon[c - 'a'][c2 - 'a'];
                                pp[i + 1][j][c2 - 'a'] = j;
                                cc[i + 1][j][c2 - 'a'] = c;
                            }
                        } else {
                            if (dp[i + 1][j + 1][c2 - 'a'] < dp[i][j][c - 'a'] + bon[c - 'a'][c2 - 'a']) {
                                dp[i + 1][j + 1][c2 - 'a'] = dp[i][j][c - 'a'] + bon[c - 'a'][c2 - 'a'];
                                pp[i + 1][j + 1][c2 - 'a'] = j;
                                cc[i + 1][j + 1][c2 - 'a'] = c;
                            }
                        }
                    }
                }
            }
        }
    }
    /*for (int i = 0; i < 2; ++i) {
        for (int j = 0; j <= i + 1; ++j) {
            for (char c = 'a'; c <= 'z'; ++c) {
                cout << i + 1 << ' ' << j << ' ' << c << " - " << dp[i][j][c - 'a'] << endl;
            }
        }
    }*/
    for (int i = 1; i <= k; ++i) {
        for (char c = 'a'; c <= 'z'; ++c) {
            if (ans < dp[s.length() - 1][i][c - 'a']) {
                ans = dp[s.length() - 1][i][c - 'a'];
                //cout << i << ' ' << c << ' ' << dp[s.length() - 1][i][c - 'a'] << endl;
            }
        }
    }
    cout << ans << endl;
    /*int x = 2, len = s.length() - 1;
    char c = 'z';
    string res = "";
    while (x != 0) {
        cout << x << ' ' << c << "  " << dp[len][x][c - 'a'] << endl;
        res += c;
        int nx;
        char nc;
        nx = pp[len][x][c - 'a'];
        nc = cc[len][x][c - 'a'];
        --len;
        x = nx;
        c = nc;
    }
    reverse(res.begin(), res.end());
    cout << res << endl;*/
    return 0;
}