#include <bits/stdc++.h>

using namespace std;

const int max_n = 5055, inf = 1000111222;

int n, to, a[max_n], dp[max_n][max_n][2];

void upd(int i, int j, int tp, int x) {
    dp[i][j][tp] = min(dp[i][j][tp], x);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    to = (n + 1) / 2;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < max_n; ++i) {
        for (int j = 0; j < max_n; ++j) {
            dp[i][j][0] = inf;
            dp[i][j][1] = inf;
        }
    }
    dp[0][0][0] = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= to; ++j) {
            for (int tp = 0; tp < 2; ++tp) {
                if (dp[i][j][tp] == inf) {
                    continue;
                }

                int cur = a[i];
                if (tp) {
                    cur = min(cur, a[i - 1] - 1);
                }
                upd(i + 1, j, 0, dp[i][j][tp]);

                if (i < n) {
                    int first = cur - min(cur, a[i + 1] - 1);
                    int second = a[i + 2] - min(a[i + 2], a[i + 1] - 1);
                    upd(i + 2, j + 1, 1, dp[i][j][tp] + first + second);
                }

            }
        }
    }
    //cout << "#" << dp[2][1][1] <<
    for (int i = 1; i <= to; ++i) {
        printf("%d ", min(dp[n + 1][i][0], dp[n + 1][i][1]));
    }
    printf("\n");
    return 0;
}