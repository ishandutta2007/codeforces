#include <cstdio>
typedef long long int64;
#define int int64   // (_)
static const int MAXN = 1005;
static const int MAXD = 11;
static const int MAX_MODULUS = 1e9 + 7;
template <typename T> inline T min(const T a, const T b) { return a < b ? a : b; }

int n, d, mod;
#define _ % mod
#define __ %= mod

inline int fpow(int base, int exp) {
    int64 ans = 1;
    for (; exp; exp >>= 1) { if (exp & 1) (ans *= base)__; base = (int64)base * base _; }
    return ans;
}
inline int _inv(const int x) { return fpow(x, mod - 2); }

int inv[MAXD];
inline void calc_inversions() { for (int i = 1; i < MAXD; ++i) inv[i] = _inv(i); }
inline int binom_2(const int x) { return (int64)x * (x - 1)_ * inv[2]_; }

// f[# of vertices][degree of root][max. subtree size of root's children]
int f[MAXN][MAXD][MAXN] = {{{ 0 }}};

signed main()
{
    scanf("%I64d%I64d%I64d", &n, &d, &mod);
    if (n <= 2) { puts("1"); return 0; }

    calc_inversions();
    for (int i = 0; i <= n; ++i) f[0][0][i] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= d; ++j)
            for (int k = 1; k <= min(i, (n + 1) / 2); ++k) {
                int binom_begin = (k == 1 ? 1 : f[k - 1][d - 1][k - 1]);
                int binom_val = 1;
                for (int t = 0; t <= i / k && t <= j; ++t) {
                    f[i][j][k] = ((int64)f[i][j][k] + binom_val * f[i - k * t][j - t][min(i - k * t, k - 1)])_;
                    binom_val = (int64)binom_val * (binom_begin + t)_ * inv[t + 1]_;
                }
            }

    int ans = (f[n - 1][d][(n - 1) / 2] + ((n & 1) ? 0 : binom_2(f[n / 2 - 1][d - 1][(n - 1) / 2] + 1)))_;
    printf("%I64d\n", ans);
    return 0;
}