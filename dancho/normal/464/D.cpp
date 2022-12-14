#include <cstdio>
#include <cstring>

int n, k;

double dp[2][1024];

int main()
{
    memset(dp, 0, sizeof(dp));
    int pr, cr;
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; ++i)
    {
        pr = (i & 1);
        cr = 1 - pr;
        for (int j = 1; j <= 1000; ++j)
        {
            dp[cr][j] = 1.0 / k / (j + 1) * (dp[pr][j] * j + j * (j + 1) / 2 + dp[pr][j + 1] + j) + (double) (k - 1) / k * dp[pr][j];
        }
    }
    printf("%.10lf\n", dp[cr][1] * k);

    return 0;
}