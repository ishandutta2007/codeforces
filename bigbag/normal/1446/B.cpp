#include <bits/stdc++.h>

using namespace std;

const int max_n = 5055, inf = 1000111222;

int n, m, dp[max_n][max_n];
string a, b;

void upd(int &x, int y) {
    x = max(x, y);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> a >> b;
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            upd(ans, dp[i][j]);
            if (i < n && j < m && a[i] == b[j]) {
                upd(dp[i + 1][j + 1], dp[i][j] + 4 - 2);
            }
            if (i < n) {
                upd(dp[i + 1][j], dp[i][j] - 1);
            }
            if (j < m) {
                upd(dp[i][j + 1], dp[i][j] - 1);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}