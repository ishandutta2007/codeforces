#include <cstdio>
typedef double int64;   // > <...
static const int MAXN = 100007;

int n, a[MAXN];

namespace fwk {
    int64 f[MAXN];
    inline void init() { for (int i = 0; i < MAXN; ++i) f[i] = 0; }
    inline void add(int pos, int inc) { for (; pos < MAXN; pos += (pos & -pos)) f[pos] += inc; }
    inline int64 sum(int rg) { int64 ans = 0; for (; rg; rg -= (rg & -rg)) ans += f[rg]; return ans; }
    inline int64 sum(int lf, int rg) { return sum(rg) - sum(lf - 1); }
}

template <int EXP> inline int64 sum(int k)
{
    switch (EXP) {
        case 1: return (int64)k * (k + 1) / 2;
        case 2: return (int64)k * (k + 1) * (k + k + 1) / 6;
        case 3: return (int64)k * k * (k + 1) * (k + 1) / 4;
        default: return -1; // Unneeded > <
    }
}

int64 global_inversions()
{
    fwk::init();
    int64 ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += fwk::sum(a[i] + 1, MAXN - 1);
        fwk::add(a[i], +1);
    }
    return ans;
}

int64 subsegment_inversions()
{
    fwk::init();
    int64 ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += fwk::sum(a[i] + 1, MAXN - 1) * (n - i);
        fwk::add(a[i], i + 1);
    }
    return ans;
}

signed main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    double ans = global_inversions();
    ans += (double)(-(sum<3>(n) - sum<2>(n) * (n + 2) + sum<1>(n) * (n + 1)) - subsegment_inversions() * 4) / (2LL * n * (n + 1));

    printf("%.12lf\n", ans);
    return 0;
}