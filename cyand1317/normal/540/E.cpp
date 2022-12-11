#include <cstdio>
#include <algorithm>
#include <utility>
typedef long long int64;
static const int MAXN = 2e5 + 4;

int n, ct;
int a[MAXN], b[MAXN];
int c[MAXN];

namespace fwk {

int f[MAXN] = { 0 };
inline void add(int pos, int inc = +1) {
    for (; pos < MAXN; pos += (pos & -pos)) f[pos] += inc;
}
inline int sum(int rg) {
    int ans = 0;
    for (; rg; rg -= (rg & -rg)) ans += f[rg];
    return ans;
}
inline int sum(int lf, int rg) { return sum(rg) - sum(lf - 1); }

}

template <typename T> inline int discretize(int n, T *a, int *b) {
    static std::pair<T, int> p[MAXN];
    for (int i = 0; i < n; ++i) p[i] = std::make_pair(a[i], i);
    std::sort(p, p + n);
    int rk = 0;
    for (int i = 0; i < n; ++i) {
        if (i != 0 && p[i].first != p[i - 1].first) ++rk;
        a[rk] = p[i].first;
        b[p[i].second] = rk;
    }
    return rk + 1;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n * 2; ++i) scanf("%d", &a[i]);
    ct = discretize(n * 2, a, b);

    for (int i = 0; i < ct; ++i) c[i] = i;
    for (int i = 0; i < n; ++i) std::swap(c[b[i * 2]], c[b[i * 2 + 1]]);

    int64 ans = 0;
    for (int i = 0; i < ct; ++i) {
        ans += fwk::sum(c[i] + 2, MAXN - 1);
        fwk::add(c[i] + 1);
    }
    for (int i = 0; i < ct; ++i) {
        if (a[c[i]] > a[i]) ans += (a[c[i]] - a[i] - (c[i] - i));
        else if (a[c[i]] < a[i]) ans += (a[i] - a[c[i]] - (i - c[i]));
    }

    printf("%I64d\n", ans);

    return 0;
}