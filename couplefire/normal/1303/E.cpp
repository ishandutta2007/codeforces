#include <iostream>
#include <vector>
int t;
std::string a, b;
std::vector<std::vector<int>> dp;
void solve() {
    std::cin >> a >> b;
    int n = a.length(), m = b.length();
    for (int f = 0; f < m; ++f) {
        dp.assign(n + 1, std::vector<int>(f + 1, -1));
        dp[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= f; ++j) {
                if (dp[i][j] == -1)
                    continue;
                dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j] + (dp[i][j] < m - f && a[i] == b[dp[i][j] + f]));
                if (j < f && a[i] == b[j])
                    dp[i + 1][j + 1] = std::max(dp[i + 1][j + 1], dp[i][j]);
            }
        }
        if (dp[n][f] == m - f) {
            std::cout << "YES\n";
            return;
        }
    }
    std::cout << "NO\n";
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}