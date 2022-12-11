#include <cstdio>
static const int MAXA = 1e6 + 5;

int n, k, a_i, min_a = MAXA;

namespace fwk {
    int f[MAXA * 2] = { 0 };
    inline void add(int pos) { for (++pos; pos < MAXA * 2; pos += (pos & -pos)) f[pos]++; }
    inline int sum(int rg) { int ans = 0; for (++rg; rg; rg -= (rg & -rg)) ans += f[rg]; return ans; }
    inline int sum(int lf, int rg) { return sum(rg) - sum(lf - 1); }
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a_i);
        fwk::add(a_i);
        if (min_a > a_i) min_a = a_i;
    }

    int ans = (k < min_a ? k : min_a);
    for (int i = k + 1; i <= min_a; ++i) {
        int count = 0;
        for (int j = 0; j < MAXA; j += i) count += fwk::sum(j, j + k);
        if (count == n) ans = i;
    }

    printf("%d\n", ans);
    return 0;
}