#include <cstdio>
static const int MAXN = 1e5 + 4;

int n;
double p[MAXN], f[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%lf", &p[i]);

    f[0] = 0;
    for (int i = 1; i < n; ++i) f[i] = (f[i - 1] + p[i - 1]) * p[i];

    double ans = 0;
    for (int i = 0; i < n; ++i) ans += f[i] * 2 + p[i];
    printf("%.8lf\n", ans);

    return 0;
}