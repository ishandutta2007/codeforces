#include <cstdio>
#include <algorithm>
#include <utility>
typedef long long int64;
static const int MAXN = 1e6 + 5;

int n;
int a[MAXN];

struct fwk {
    int t[MAXN];
    inline void add(int pos, int inc = +1) {
        for (; pos < MAXN; pos += (pos & -pos)) t[pos] += inc;
    }
    inline int sum(int rg) {
        int ans = 0;
        for (; rg; rg -= (rg & -rg)) ans += t[rg];
        return ans;
    }
    inline int sum(int lf, int rg) { return sum(rg) - sum(lf - 1); }
} f = { 0 }, g = { 0 };

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    static std::pair<int, int> p[MAXN];
    for (int i = 0; i < n; ++i) p[i] = std::make_pair(a[i], i);
    std::sort(p, p + n);
    for (int i = 0; i < n; ++i) a[p[i].second] = i + 1;

    for (int i = 0; i < n; ++i) g.add(a[i], +1);
    int64 ans = 0;
    for (int i = 0; i < n; ++i) {
        g.add(a[i], -1);
        ans += (int64)f.sum(a[i] + 1, MAXN - 1) * g.sum(1, a[i] - 1);
        f.add(a[i], +1);
    }

    printf("%I64d\n", ans);
    return 0;
}