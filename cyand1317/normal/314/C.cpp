#include <cstdio>
static const int MAXN = 1e5 + 4;
static const int MAXA = 1e6 + 9;
static const int MODULUS = 1e9 + 7;
#define _ % MODULUS
#define __ %= MODULUS

int n, a[MAXN];

namespace fwk {
    int f[MAXA] = { 0 };
    inline void add(int pos, int inc = +1) {
        for (++pos; pos < MAXA; pos += (pos & -pos)) (f[pos] += inc)__;
    }
    inline int sum(int rg) {
        int ans = 0; for (++rg; rg; rg -= (rg & -rg)) (ans += f[rg])__; return ans;
    }
    inline int sum(int lf, int rg) {
        return (sum(rg) - sum(lf - 1) + MODULUS)_;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    for (int i = 0; i < n; ++i) {
        int s = fwk::sum(a[i]) + 1;
        fwk::add(a[i], (((long long)s * a[i]_ - fwk::sum(a[i], a[i]))_ + MODULUS)_);
    }

    printf("%d\n", fwk::sum(MAXA - 1));
    return 0;
}