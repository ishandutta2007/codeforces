#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#ifdef LOCAL
    #define LLD_SPEC "%lld"
#else
    #define LLD_SPEC "%I64d"
#endif

int main() {
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = 0;
        for (int j = 0; j < 3; ++j) {
            dp[i][0] = max(dp[i][0], dp[i - 1][j]);
        }
        for (int jp = 0; jp < 3; ++jp) {
            for (int jn = 1; jn < 3; ++jn) {
                if (jp != jn && (jn & a[i - 1]) == jn) {
                    dp[i][jn] = max(dp[i][jn], dp[i - 1][jp] + 1);
                }
            }
        }
    }

    int result = 0;
    result = max(result, dp[n][0]);
    result = max(result, dp[n][1]);
    result = max(result, dp[n][2]);

    printf("%d\n", n - result);

    return 0;
}