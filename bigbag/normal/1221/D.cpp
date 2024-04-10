#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333;
const long long inf = 1000111222000111222LL;
const int max_op = 3;

int q, n, a[max_n], b[max_n];
long long dp[max_n][max_op];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &q);
    a[0] = -11;
    while (q--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &a[i], &b[i]);
            for (int j = 0; j < max_op; ++j) {
                dp[i][j] = inf;
                for (int pr = 0; pr < max_op; ++pr) {
                    if (a[i - 1] + pr != a[i] + j) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][pr]);
                    }
                }
                dp[i][j] += 1LL * j * b[i];
            }
        }
        printf("%I64d\n", *min_element(dp[n], dp[n] + max_op));
    }
    return 0;
}