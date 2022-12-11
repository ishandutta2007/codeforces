#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
typedef long long int64;
static const int MAXN = 302;
static const int MODULUS = 1e9 + 7;
#define _  %  MODULUS
#define __ %= MODULUS

typedef std::vector<int> factorization;

int64 fact[MAXN], fact_inv[MAXN];
int64 part[MAXN][MAXN] = {{ 0 }};

inline int64 qpow(int64 base, int exp) {
    int64 ans = 1;
    for (; exp; exp >>= 1, (base *= base)__) if (exp & 1) (ans *= base)__;
    return ans;
}
void prepare_magic()
{
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) fact[i] = fact[i - 1] * i _;
    fact_inv[MAXN - 1] = qpow(fact[MAXN - 1], MODULUS - 2);
    for (int i = MAXN - 2; i >= 0; --i) fact_inv[i] = fact_inv[i + 1] * (i + 1)_;

    part[1][1] = 1;
    for (int i = 2; i < MAXN; ++i)
        for (int j = 1; j <= i; ++j)
            part[i][j] = (part[i - 1][j - 1] + part[i - 1][j] * (i - 1 + j))_;
}

inline int64 binom(int n, int m)
{
    if (n < m || m < 0) return 0;
    return fact[n] * fact_inv[m]_ * fact_inv[n - m]_;
}

int n, a[MAXN];
factorization b[MAXN];

std::map<factorization, int> ct;
std::vector<int> c;

int64 f[MAXN] = { 0 };
int64 g[MAXN];

int main()
{
    prepare_magic();

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        for (int j = 2; j * j <= a[i]; ++j) if (a[i] % j == 0) {
            bool parity = false;
            do { a[i] /= j; parity ^= 1; } while (a[i] % j == 0);
            if (parity) b[i].push_back(j);
        }
        if (a[i] > 1) b[i].push_back(a[i]);
        ++ct[b[i]];
    }
    for (auto p : ct) c.push_back(p.second);

    int accum = c.front();
    c.erase(c.begin());
    f[accum - 1] = fact[accum];
    for (int u : c) {
        memset(g, 0, sizeof g);
        for (int i = 0; i < accum; ++i)
            for (int j = 1; j <= u; ++j)
                for (int k = 0; k <= i && k <= j; ++k)
                    (g[i - k + (u - j)] += f[i] * part[u][j]_ * binom(j, k)_ * binom(i, k)_ * fact[k]_ * binom(accum - i + 1, j - k)_ * fact[j - k]_)__;
        memcpy(f, g, sizeof g);
        accum += u;
    }
    printf("%I64d\n", f[0]);

    return 0;
}