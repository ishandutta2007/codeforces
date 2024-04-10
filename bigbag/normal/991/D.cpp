#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int n, dp[max_n][2][2], a[2][max_n];
string s[2];

bool ok(int q, int nq) {
    return (q == 1 && nq == 0) || (q == 0);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s[0] >> s[1];
    n = s[0].length();
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = (s[i][j] == 'X');
        }
    }
    memset(dp, -1, sizeof(dp));
    dp[0][a[0][0]][a[1][0]] = 0;
    for (int i = 1; i < n; ++i) {
        for (int q = 0; q < 2; ++q) {
            for (int w = 0; w < 2; ++w) {
                for (int e = 0; e < 2; ++e) {
                    for (int r = 0; r < 2; ++r) {
                        if (q + w + e + r == 3 || q + w + e + r == 0) {
                            if (e + a[0][i] <= 1 && r + a[1][i] <= 1) {
                                for (int nq = 0; nq < 2; ++nq) {
                                    for (int nw = 0; nw < 2; ++nw) {
                                        if (ok(q, nq) && ok(w, nw) && dp[i - 1][nq][nw] != -1) {
                                            int one = (q + w + e + r == 3);
                                            dp[i][e | a[0][i]][r | a[1][i]] = max(dp[i][e][r], dp[i - 1][nq][nw] + one);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = -1;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            ans = max(ans, dp[n - 1][i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}