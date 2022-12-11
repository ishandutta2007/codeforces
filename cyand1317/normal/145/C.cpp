#include <cstdio>
#include <map>
typedef long long int64;
static const int MAXN = 1e5 + 6;
static const int LNTOT = 1033;
static const int MODULUS = 1e9 + 7;
#define _ % MODULUS

int k, n, a_i;
std::map<int, int> _lnid;
int lntot = 0;
int lnct[LNTOT] = { 0 };
int f[2][LNTOT] = {{ 0 }}, cur = 0;

int lnid(int x) {
    for (int y = x; y; y /= 10)
        if (y % 10 != 4 && y % 10 != 7) return 0;
    return (_lnid[x] == 0 ? (_lnid[x] = ++lntot) : _lnid[x]);
}

int fact[MAXN], fact_inv[MAXN];
inline int fpow(int base, int exp) {
    int64 ans = 1;
    for (; exp; exp >>= 1) {
        if (exp & 1) ans = ans * base _;
        base = (int64)base * base _;
    }
    return (int)ans;
}
inline void init_factorials() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i)
        fact[i] = (int64)fact[i - 1] * i _;
    fact_inv[MAXN - 1] = fpow(fact[MAXN - 1], MODULUS - 2);
    for (int i = MAXN - 2; i >= 0; --i)
        fact_inv[i] = (int64)fact_inv[i + 1] * (i + 1) _;
}
inline int nCr(int n, int m) {
    if (n < m) return 0;
    return (int)((int64)fact[n] * fact_inv[m]_ * fact_inv[n - m]_);
}

int main()
{
    init_factorials();

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a_i);
        ++lnct[lnid(a_i)];
    }

    cur = 0;
    f[cur][0] = 1;
    for (int i = 1; i <= lntot; ++i) {
        cur ^= 1;
        f[cur][0] = 1;
        for (int j = 1; j <= i; ++j)
            f[cur][j] = ((int64)f[cur ^ 1][j - 1] * lnct[i] + f[cur ^ 1][j])_;
    }

    int64 ans = 0;
    for (int i = 0; i <= lntot && i <= k; ++i)
        ans = (ans + (int64)f[cur][i] * nCr(lnct[0], k - i))_;
    printf("%I64d\n", ans);

    return 0;
}