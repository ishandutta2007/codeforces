#include <cstdio>
#include <cmath>
#include <cstring>

double e = 1e-8;

int n, k;
double eps;
int d[128];

double m;
double dp[128][128];

double getDP(int p, int c)
{
    if (dp[p][c] == dp[p][c])
        return dp[p][c];
    if (c >= k)
        return 0;
    if (p == n)
        return 1;
    if ((double) d[p] <= m * m)
    {
        dp[p][c] = getDP(p + 1, c + 1);
    }
    else
    {
        double pr = exp(1.0 - (double) d[p] / m / m);
        dp[p][c] = getDP(p + 1, c + 1) * pr + getDP(p + 1, c) * (1.0 - pr);
    }
    return dp[p][c];
}

int main()
{
    int x0, y0;
    int x, y;

    scanf("%d %d", &n, &k);
    scanf("%lf", &eps);
    eps /= 1000;
    scanf("%d %d", &x0, &y0);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d", &x, &y);
        d[i] = (x - x0) * (x - x0) + (y - y0) * (y - y0);
    }

    double l, r;
    l = 0.0; r = 1000000;
    for (int iter = 0; iter < 100; ++iter)
    {
        m = (l + r) / 2;
        memset(dp, -1, sizeof(dp));

        if (getDP(0, 0) > eps)
            l = m;
        else
            r = m;
    }
    printf("%.10lf\n", l);
    return 0;
}