#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, a[max_n];
pair<int, long long> dp[max_n][2];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        dp[0][0] = {0, 0};
        dp[0][1] = {0, 0};
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            for (int tp = 0; tp < 2; ++tp) {
                dp[i][tp] = dp[i - 1][tp];
                if (tp == (a[i] > 0)) {
                    auto p = dp[i - 1][tp ^ 1];
                    ++p.first;
                    p.second += a[i];
                    dp[i][tp] = max(dp[i - 1][tp], p);
                }
            }
        }
        printf("%I64d\n", max(dp[n][0], dp[n][1]).second);
    }
    return 0;
}