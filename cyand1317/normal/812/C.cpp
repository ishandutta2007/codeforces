#include <cstdio>
#include <algorithm>
typedef long long int64;
static const int MAXN = 1e5 + 4;

int n, s;
int a[MAXN];
int64 b[MAXN];

inline int64 check(int k)
{
    for (int i = 0; i < n; ++i) b[i] = (int64)a[i] + (int64)k * (i + 1);
    std::sort(b, b + n);
    int64 ans = 0;
    for (int i = 0; i < k; ++i) ans += b[i];
    return ans;
}

int main()
{
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    int lo = 0, hi = n + 1, mid;
    while (lo < hi - 1) {
        mid = (lo + hi) >> 1;
        if (check(mid) <= s) lo = mid; else hi = mid;
    }

    printf("%d %I64d\n", lo, check(lo));
    return 0;
}