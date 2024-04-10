#include <cstdio>
typedef long long int64;
static const int MAXK = 1003;
static const int MAXT = 103;
static const int MODULUS = 1e9 + 7;
#define _ % MODULUS
static const int MAXPWR = 4 * MAXK * MAXT;

inline int fpow(int64 base, int exp) {
    int64 ans = 1;
    for (; exp; exp >>= 1) {
        if (exp & 1) ans = ans * base _;
        base = base * base _;
    }
    return (int)ans;
}
inline int inv(int x) { return fpow(x, MODULUS - 2); }
int fact[MAXPWR], fact_inv[MAXPWR];
inline int nCr(int n, int m) {
    if (n < 0 || m < 0 || n - m < 0) return 0;
    return (int64)fact[n] * fact_inv[m]_ * fact_inv[n - m]_;
}

int a, b, k, t;

int main()
{
    scanf("%d%d%d%d", &a, &b, &k, &t);

    fact[0] = fact_inv[0] = fact[1] = fact_inv[1] = 1;
    int p = 2 * t, n = 2 * t;
    for (int i = 2; i < MAXPWR; ++i) {
        fact[i] = (int64)fact[i - 1] * i _;
        fact_inv[i] = inv(fact[i]);
    }

    int64 ans = 0;
    for (int i = 0; i <= 2 * t; ++i) {
        ans = (ans + (int64)nCr(p, i) * (nCr(p + 4 * k * t - (2 * k + 1) * i, p) - nCr(p + 2 * k * t + b - a - (2 * k + 1) * i, p))_ * (i % 2 == 0 ? 1 : -1))_;
    }
    printf("%I64d\n", (ans _ + MODULUS)_);

    return 0;
}