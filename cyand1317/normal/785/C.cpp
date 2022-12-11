#include <cstdio>
typedef long long int64;

int main()
{
    int64 n, m;
    scanf("%I64d%I64d", &n, &m);

    int64 lo = -2, hi = 2e9, mid;
    while (lo < hi - 1) {
        mid = (lo + hi) >> 1;
        if (mid * (mid + 1) / 2 + m < n) lo = mid; else hi = mid;
    }

    if (hi < 0) printf("%I64d\n", n); else printf("%I64d\n", hi + m);
    return 0;
}