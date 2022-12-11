#include <cstdio>
#include <algorithm>
static const int MAXN = 100008;

long long n, h, k;
long long a[MAXN];

inline long long div_ceil(long long num, long long deno) {
    return num / deno + !!(num % deno);
}

int main()
{
    scanf("%I64d%I64d%I64d", &n, &h, &k);
    for (int i = 0; i < n; ++i) scanf("%I64d", &a[i]);

    long long ans = 0, height = 0;
    for (int i = 0; i < n; ) {
        int t = div_ceil(std::max(0LL, a[i] - (h - height)), k);
        ans += t;
        height = std::max(0LL, height - t * k);
        while (i < n && height + a[i] <= h) {
            height += a[i];
            ++i;
        }
    }

    ans += div_ceil(height, k);
    printf("%I64d\n", ans);
    return 0;
}