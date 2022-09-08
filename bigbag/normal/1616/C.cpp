/**
 *  created: 29/12/2021, 17:44:40
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 77, inf = 1000111222;

int t, n, a[max_n], dp[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        memset(dp, -1, sizeof(dp));
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                dp[i][j] = max(dp[i][j], 2);
                ans = max(ans, dp[i][j]);
                for (int k = j + 1; k < n; ++k) {
                    if ((a[j] - a[i]) * (k - j) == (a[k] - a[j]) * (j - i)) {
                        dp[j][k] = max(dp[j][k], dp[i][j] + 1);
                    }
                }
            }
        }
        cout << n - ans << "\n";
    }
    return 0;
}