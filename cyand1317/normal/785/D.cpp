#include <cstdio>
#include <cstring>
typedef long long int64;
static const int MAXN = 200005;
static const int MODULUS = 1e9 + 7;
#define _ % MODULUS
#define __ %= MODULUS

int fact[MAXN], fact_inv[MAXN];
inline int fpow(int64 base, int exp) {
    int64 ans = 1;
    for (; exp; exp >>= 1) {
        if (exp & 1) (ans *= base)__; (base *= base)__;
    }
    return (int)ans;
}
inline void preprocess() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) fact[i] = (int64)fact[i - 1] * i _;
    fact_inv[MAXN - 1] = fpow(fact[MAXN - 1], MODULUS - 2);
    for (int i = MAXN - 2; i >= 0; --i) fact_inv[i] = (int64)fact_inv[i + 1] * (i + 1)_;
}
inline int binom(int n, int m) {
    if (n < m) return 0;
    return (int64)fact[n] * fact_inv[n - m]_ * fact_inv[m]_;
}

int n;
char s[MAXN];
int l_ct[MAXN], r_ct[MAXN];

int main()
{
    preprocess();
    gets(s); n = strlen(s);

    l_ct[0] = 0; for (int i = 0; i < n; ++i) l_ct[i + 1] = l_ct[i] + (s[i] == '(');
    r_ct[n] = 0; for (int i = n; i > 0; --i) r_ct[i - 1] = r_ct[i] + (s[i - 1] == ')');

    int64 ans = 0;
    for (int i = 0; i < n; ++i) if (s[i] == '(') {
        int left = l_ct[i], right = r_ct[i + 1];
        (ans += binom(left + right, left + 1))__;
    }

    printf("%I64d\n", ans);
    return 0;
}