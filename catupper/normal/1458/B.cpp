#include <algorithm>
#include <iostream>

using namespace std;
typedef long long Int;
const Int INF = 1LL << 60;
Int dp[101][10001];

int main()
{
    int n, ai, bi;
    int asum = 0;
    scanf("%d", &n);
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 10001; j++)
            dp[i][j] = -INF;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &ai, &bi);
        asum += bi;
        for (int j = i; j >= 1; j--) {
            for (int a = ai; a < 10001; a++) {
                dp[j][a] = max(dp[j][a], dp[j - 1][a - ai] + bi);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        double ans = 0;
        for (int a = 0; a < 10001; a++) {
            ans = max(ans, min(double(a), double(asum + dp[i][a]) / 2));
        }
        printf("%.10lf ", ans);
    }
    puts("");
}