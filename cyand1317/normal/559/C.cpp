#include <cstdio>
#include <algorithm>
#include <utility>
typedef long long int64;
static const int MAXN = 2004;
static const int MAXW = 1e5 + 15;
static const int MODULUS = 1e9 + 7;
#define _ % MODULUS
template <typename T> inline int __(const T x) { return (x _ + MODULUS)_; }

inline int fpow(int base, int exp) {
    int64 ans = 1;
    for (; exp; exp >>= 1) {
        if (exp & 1) ans = ans * base _;
        base = (int64)base * base _;
    }
    return (int)ans;
}
inline int inv(int x) { return fpow(x, MODULUS - 2); }
int fact[MAXW * 2], fact_inv[MAXW * 2];
inline int nCr(int n, int m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return (int64)fact[n] * fact_inv[n - m]_ * fact_inv[m]_;
}
inline int ways(int dr, int dc) { return nCr(dr + dc, dr); }

int h, w, n;
std::pair<int, int> p[MAXN];
int f[MAXN] = { 0 };

int main()
{
    scanf("%d%d%d", &h, &w, &n);
    fact[0] = fact_inv[0] = 1;
    for (int i = 1; i <= h + w + 10; ++i) {
        fact[i] = (int64)fact[i - 1] * i _;
        fact_inv[i] = inv(fact[i]);
    }
    for (int i = 0; i < n; ++i) scanf("%d%d", &p[i].first, &p[i].second);
    p[n++] = std::make_pair(h, w);
    std::sort(p, p + n);    // mdzz... (o

    for (int i = 0; i < n; ++i) {
        f[i] = ways(p[i].first - 1, p[i].second - 1);
        for (int j = 0; j < i; ++j)
            if (p[j].first <= p[i].first && p[j].second <= p[i].second)
                f[i] = __((int64)f[i] - (int64)f[j] * ways(p[i].first - p[j].first, p[i].second - p[j].second));
    }

    printf("%d\n", f[n - 1]);
    return 0;
}