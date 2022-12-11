#include <cstdio>
#include <algorithm>

typedef long long int64;
static const int MAXN = 1e6 + 4;
static const int MODULUS = 1e9 + 7;
#define _  %  MODULUS
#define __ %= MODULUS

static int n, a[MAXN];
static int64 fact[MAXN], fact_inv[MAXN];

inline int64 qpow(int64 base, int exp)
{
    int64 ans = 1;
    for (; exp; exp >>= 1, (base *= base)__)
        if (exp & 1) (ans *= base)__;
    return ans;
}

inline int64 binom(int n, int r)
{
    if (n < r || r < 0) return 0;
    return fact[n] * fact_inv[r]_ * fact_inv[n - r]_;
}

int main()
{
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) fact[i] = fact[i - 1] * i _;
    fact_inv[MAXN - 1] = qpow(fact[MAXN - 1], MODULUS - 2);
    for (int i = MAXN - 2; i >= 0; --i) fact_inv[i] = fact_inv[i + 1] * (i + 1)_;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    std::sort(a, a + n);

    int64 ans = 0;
    for (int i = 0, j; i < n; i = j) {
        for (j = i; j < n && a[i] == a[j]; ++j) ;
        int less = i, equal = j - i, greater = n - j;
        if (greater > 0) {
            greater += equal - 1;
            // <greater> elements should be after element #i
            (ans += fact[greater] * fact[n - greater - 1]_ * binom(n, greater + 1)_ * a[i]_ * (j - i)_)__;
        }
    }

    printf("%I64d\n", ans);
    return 0;
}