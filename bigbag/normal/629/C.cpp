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

const int max_n = 2222, sd = 2022, mod = 1000000007;

int n, m, mn, dp[max_n][2 * max_n][2];
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> s;
    int bal = 0;
    for (int i = 0; i < m; ++i) {
        if (s[i] == '(') {
            ++bal;
        } else {
            --bal;
        }
        mn = min(mn, bal);
    }
    if (abs(bal) > n - m) {
        cout << 0 << endl;
        return 0;
    }
    dp[0][sd][0] = 1;
    for (int i = 0; i < n - m; ++i) {
        for (int x = 0; x <= i + sd; ++x) {
            for (int f = 0; f < 2; ++f) {
                if (dp[i][x][f] == 0) {
                    continue;
                }
                int nbal = x - sd;
                if (f == 1) {
                    nbal += bal;
                }
                for (int q = -1; q <= 1; q += 2) {
                    int y = nbal;
                    if (f == 0) {
                        if (y + q >= 0) {
                            dp[i + 1][y + q + sd][0] += dp[i][x][f];
                            dp[i + 1][y + q + sd][0] %= mod;
                        }
                        if (y + mn >= 0) {
                            if (y + bal + q >= 0) {
                                dp[i + 1][y + q + sd][1] += dp[i][x][f];
                                dp[i + 1][y + q + sd][1] %= mod;
                            }
                        }
                    } else {
                        y += q;
                        if (y >= 0) {
                            dp[i + 1][y + sd - bal][1] += dp[i][x][f];
                            dp[i + 1][y + sd - bal][1] %= mod;
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    ans += dp[n - m][-bal + sd][1];
    if (-bal + mn >= 0) {
        ans += dp[n - m][-bal + sd][0];
    }
    ans %= mod;
    cout << ans << endl;
    return 0;
}