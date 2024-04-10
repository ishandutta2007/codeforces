#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

int dp[2][101][101];

auto solve() {
    int n, m, k;
    cin >> n >> m >> k;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        dp[0][i][1] = dp[1][i][1] = i - 1;
    }
    for (int j = 1; j <= m; j++) {
        dp[0][1][j] = dp[1][1][j] = j - 1;
    }
    dp[0][1][1] = dp[1][1][1] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            int lo = min(dp[0][i - 1][j] + j, dp[0][i][j - 1] + i);
            int hi = max(dp[1][i - 1][j] + j, dp[1][i][j - 1] + i);
            dp[0][i][j] = lo, dp[1][i][j] = hi;
        }
    }
    return dp[0][n][m] <= k && k <= dp[1][n][m] ? "YES" : "NO";
}

// *****

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        cout << solve() << endl;
    }
    return 0;
}