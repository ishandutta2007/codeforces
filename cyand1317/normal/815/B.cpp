#include <cstdio>
typedef long long int64;
static const int MAXN = 200004;
static const int MODULUS = 1e9 + 7;
#define _  %  MODULUS
#define __ %= MODULUS

int n;
int a[MAXN], b[MAXN];

int64 fact[MAXN], fact_inv[MAXN];

inline int64 fpow(int64 base, int exp)
{
    int64 ans = 1;
    for (; exp; exp >>= 1, (base *= base)__) if (exp & 1) (ans *= base)__;
    return ans;
}

inline void preprocess()
{
    fact[0] = fact_inv[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = fact[i - 1] * i _;
        fact_inv[i] = fpow(fact[i], MODULUS - 2);
    }
}

inline int64 binom(int n, int m)
{
    if (n < m) return 0;
    return fact[n] * fact_inv[m]_ * fact_inv[n - m]_;
}

int main()
{
    preprocess();

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    int w = (n - 1) / 2;
    if (n % 4 == 1) {
        for (int i = 0; i < n; ++i)
            b[i] = i % 2 == 0 ? binom(w, i / 2) : 0;
    } else if (n % 4 == 2) {
        for (int i = 0; i < n; ++i)
            b[i] = binom(w, i / 2);
    } else if (n % 4 == 3) {
        b[0] = 1;
        for (int i = 1; i < n; ++i)
            b[i] = (b[i - 1] * (i % 2 == 0 ? -1 : +1) + binom(w, i / 2))_;
    } else {
        for (int i = 0; i < n; ++i)
            b[i] = binom(w, i / 2) * (i % 2 == 0 ? +1 : -1);
    }

    int64 ans = 0;
    for (int i = 0; i < n; ++i) (ans += (int64)a[i] * b[i])__;
    printf("%d\n", (int)(ans + MODULUS)_);

    return 0;
}