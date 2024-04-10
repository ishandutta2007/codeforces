#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;

int n, m, a[max_n], cnt[max_n], dp[max_n][5][3];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ++cnt[a[i]];
    }
    dp[1][0][0] = 0;
    for (int x = 1; x <= m; ++x) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int c = 0; c <= 2 && j + c < 5; ++c) {
                    if (i + c <= cnt[x] && j + c <= cnt[x + 1] && c <= cnt[x + 2]) {
                        dp[x + 1][j + c][c] = max(dp[x + 1][j + c][c], dp[x][i][j] + c + (cnt[x] - i - c) / 3);
                    }
                }
            }
        }
    }
    printf("%d\n", dp[m + 1][0][0]);
    return 0;
}