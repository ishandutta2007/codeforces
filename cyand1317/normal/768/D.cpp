#include <cstdio>
#include <algorithm>
static const int MAXK = 1e3 + 4;
static const int MAXD = 8e3 + 4;
static const double EPS = 5e-8;

int k, q, p;
double f[MAXD][MAXK] = {{ 0 }};
double ans[MAXD] = { 0 };

int main()
{
    scanf("%d%d", &k, &q);

    f[0][0] = 1; ans[0] = 0;
    for (int i = 0; i < MAXD - 1; ++i) {
        for (int j = 0; j < k; ++j) {
            f[i + 1][j] += f[i][j] * j / k;
            f[i + 1][j + 1] += f[i][j] * (k - j) / k;
        }
        f[i + 1][k] += f[i][k];
        //printf("%d: %.4lf\n", i + 1, f[i + 1][k]);
        ans[i + 1] = f[i + 1][k];
    }

    for (int i = 0; i < q; ++i) {
        scanf("%d", &p);
        printf("%ld\n", std::lower_bound(ans, ans + MAXD, ((double)p - EPS) / 2000.0) - &ans[0]);
    }

    return 0;
}