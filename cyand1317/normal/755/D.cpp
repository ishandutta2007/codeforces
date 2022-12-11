#include <cstdio>
typedef long long int64;
static const int MAXN = 1e6 + 4;

int n, k;
int64 ans;

namespace fwk {
    int f[MAXN] = { 0 };
    inline void add(int pos, int inc) { for (++pos; pos < MAXN; pos += (pos & -pos)) f[pos] += inc; }
    inline int64 sum(int rg) { int64 ans = 0; for (++rg; rg; rg -= (rg & -rg)) ans += f[rg]; return ans; }
    inline int64 sum(int lf, int rg) { return sum(rg) - sum(lf - 1); }
}

int main()
{
    scanf("%d%d", &n, &k);
    if (k > n / 2) k = n - k;

    ans = 1;
    int p = 0;
    for (int i = 0; i < n; ++i) {
        fwk::add(p, +1);
        if (p + k >= n) {
            ans += fwk::sum(p + 1, n - 1);
            ans += fwk::sum(0, p + k - n - 1) + 1;
        } else {
            ans += fwk::sum(p + 1, p + k - 1) + 1;
        }
        printf("%I64d%c", ans, i == n - 1 ? '\n' : ' ');
        p = (p + k) % n;
        fwk::add(p, +1);
    }

    return 0;
}