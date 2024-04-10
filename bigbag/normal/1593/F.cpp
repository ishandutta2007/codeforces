/**
 *  created: 13/10/2021, 18:16:04
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 42, inf = 1000111222;

int t, n, a[2];
int dp[max_n][max_n][max_n][max_n];
int parent[max_n][max_n][max_n][max_n];
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> a[0] >> a[1] >> s;
        memset(dp, -1, sizeof(dp));
        dp[0][0][0][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int c0 = 0; c0 <= i; ++c0) {
                int r[2], nr[2];
                for (r[0] = 0; r[0] < a[0]; ++r[0]) {
                    for (r[1] = 0; r[1] < a[1]; ++r[1]) {
                        if (dp[i][c0][r[0]][r[1]] == -1) {
                            continue;
                        }
                        for (int tp = 0; tp < 2; ++tp) {
                            nr[0] = r[0];
                            nr[1] = r[1];
                            nr[tp] = (nr[tp] * 10 + s[i] - '0') % a[tp];
                            if (dp[i + 1][c0 + (tp == 0)][nr[0]][nr[1]] == -1) {
                                dp[i + 1][c0 + (tp == 0)][nr[0]][nr[1]] = tp;
                                parent[i + 1][c0 + (tp == 0)][nr[0]][nr[1]] = r[tp];
                            }
                        }
                    }
                }
            }
        }
        pair<int, int> best(inf, inf);
        for (int c0 = 1; c0 < n; ++c0) {
            if (dp[n][c0][0][0] != -1) {
                best = min(best, {abs(c0 - (n - c0)), c0});
            }
        }
        if (best.first == inf) {
            cout << "-1\n";
            continue;
        }
        int c0 = best.second, r[2];
        r[0] = r[1] = 0;
        string ans;
        for (int i = n; i; --i) {
            int tp = dp[i][c0][r[0]][r[1]];
            ans += "RB"[tp];
            r[tp] = parent[i][c0][r[0]][r[1]];
            c0 -= (tp == 0);
        }
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
    return 0;
}