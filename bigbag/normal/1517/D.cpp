/**
 *  created: 23/04/2021, 18:02:51
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 555, max_k = 12, inf = 1000111222;

int n, m, k, a[max_n][max_n], b[max_n][max_n];
int dp[max_n][max_n][max_k];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j + 1 < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &b[i][j]);
        }
    }
    for (int c = 1; c <= k / 2; ++c) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dp[i][j][c] = inf;
                if (j + 1 < m) {
                    dp[i][j][c] = min(dp[i][j][c], dp[i][j + 1][c - 1] + a[i][j]);
                }
                if (j > 0) {
                    dp[i][j][c] = min(dp[i][j][c], dp[i][j - 1][c - 1] + a[i][j - 1]);
                }

                if (i + 1 < n) {
                    dp[i][j][c] = min(dp[i][j][c], dp[i + 1][j][c - 1] + b[i][j]);
                }
                if (i > 0) {
                    dp[i][j][c] = min(dp[i][j][c], dp[i - 1][j][c - 1] + b[i - 1][j]);
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int ans = -1;
            if (k % 2 == 0) {
                ans = 2 * dp[i][j][k / 2];
            }
            printf("%d ", ans);
        }
        puts("");
    }
    return 0;
}