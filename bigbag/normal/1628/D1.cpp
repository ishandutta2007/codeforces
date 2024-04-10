/**
 *  created: 22/01/2022, 17:25:14
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 2022, mod = 1000000007;
const int r2 = (mod + 1) / 2;

int t, n, m, k, dp[max_n][max_n];

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        for (int i = 1; i <= n; ++i) {
            dp[i][i] = mul(k, i);
            dp[i][0] = 0;
            for (int j = 1; j < i; ++j) {
                dp[i][j] = mul(dp[i - 1][j - 1] + dp[i - 1][j], r2);
            }
        }
        cout << dp[n][m] << "\n";
    }
    return 0;
}