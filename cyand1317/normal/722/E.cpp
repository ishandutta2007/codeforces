#include <cstdio>
#include <algorithm>
#include <utility>
typedef long long int64;
static const int MAXN = 100004;
static const int MAXK = 2003;
static const int MAXD = 24; // log2(s)
static const int MODULUS = 1e9 + 7;
#define _ % MODULUS

int64 fact[MAXN * 2], fact_inv[MAXN * 2];
inline int64 fpow(int64 base, int exp) {
    int64 ans = 1;
    for (; exp; exp >>= 1) {
        if (exp & 1) ans = ans * base _; base = base * base _;
    }
    return ans;
}
inline int64 inv(int64 x) { return fpow(x, MODULUS - 2); }
inline int64 ways(int dr, int dc) { return fact[dr + dc] * fact_inv[dr]_ * fact_inv[dc]_; }

int n, m, k, s;
std::pair<int, int> p[MAXN];
#define row  first
#define col  second
int64 f[MAXD][MAXN] = {{ 0 }};

int main()
{
    scanf("%d%d%d%d", &n, &m, &k, &s);
    for (int i = 0; i < k; ++i) scanf("%d%d", &p[i].row, &p[i].col);
    p[k++] = std::make_pair(1, 1);
    p[k++] = std::make_pair(n, m);
    std::sort(p, p + k);
    fact[0] = fact_inv[0] = 1;
    for (int i = 1; i < MAXN * 2; ++i) {
        fact[i] = fact[i - 1] * i _;
        fact_inv[i] = inv(fact[i]);
    }

    f[0][0] = 1;
    for (int i = 1; i < MAXD; ++i) {
        for (int u = 0; u < k; ++u)
            for (int v = 0; v < u; ++v) if (p[v].row <= p[u].row && p[v].col <= p[u].col) {
                f[i][u] = (f[i][u] + ways(p[u].row - p[v].row, p[u].col - p[v].col) * (f[i - 1][v] - f[i][v]))_;
            }
    }

    int64 ans = 1, deno = inv(ways(n - 1, m - 1));
    for (int i = 1; i < MAXD; ++i, s = (s + 1) >> 1) {
        ans = (ans + (int64)(s - 1) * f[i][k - 1]_ * deno)_;
    }
    ans = (ans _ + MODULUS)_;
    printf("%I64d\n", ans);

    return 0;
}