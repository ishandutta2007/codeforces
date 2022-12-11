#include <cstdio>
#include <algorithm>
typedef long long int64;
static const int MAXN = 2e5 + 3;

int n;
int64 x[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &x[i]);
        x[i] <<= 1;
    }
    std::sort(x, x + n);

    int lo = -1, hi = 2e9 + 15, mid;
    int p;
    while (lo < hi - 1) {
        mid = (lo + hi) >> 1;
        p = std::upper_bound(x, x + n, x[0] + mid * 2) - &x[0];
        if (p < n) p = std::upper_bound(x + p, x + n, x[p] + mid * 2) - &x[0];
        if (p < n) p = std::upper_bound(x + p, x + n, x[p] + mid * 2) - &x[0];
        if (p < n) lo = mid; else hi = mid;
    }

    printf("%.6lf\n", (double)hi / 2);
    printf("%.6lf ", (double)(x[0] + hi) / 2);
    p = std::upper_bound(x, x + n, x[0] + hi * 2) - &x[0];
    printf("%.6lf ", (double)(x[p] + hi) / 2);
    if (p < n) p = std::upper_bound(x + p, x + n, x[p] + hi * 2) - &x[0];
    if (p >= n) p = n / 2;  // :P
    printf("%.6lf\n", (double)(x[p] + hi) / 2);

    return 0;
}