#include <cstdio>
#include <algorithm>
#include <utility>
typedef long long int64;
typedef std::pair<int, int> event;

static const int MAXN = 200006;
static int MODULUS = 1e9 + 7;
#define _ % MODULUS
int64 fact[MAXN], fact_inv[MAXN];
inline int64 fpow(int64 b, int e) {
    int64 ans = 1;
    for (; e; e >>= 1) { if (e & 1) ans = (ans * b)_; b = (b * b)_; }
    return ans;
}
inline void nyanpasu(int n) {
    fact[0] = fact_inv[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = (fact[i - 1] * i)_;
        fact_inv[i] = fpow(fact[i], MODULUS - 2);
    }
}
inline int64 nCr(int n, int m) {
    if (n < m) return 0;
    else return fact[n] * fact_inv[m]_ * fact_inv[n - m]_;
}

int n, k;
event e[MAXN * 2];

int main()
{
    scanf("%d%d", &n, &k);
    nyanpasu(n);
    for (int i = 0; i < n; ++i) {
        e[i + i].second = +1;
        scanf("%d", &e[i + i].first);
        e[i + i + 1].second = -1;
        scanf("%d", &e[i + i + 1].first); ++e[i + i + 1].first;
    }
    std::sort(e, e + n + n);
    int cur_layers = 1;
    int64 ans = 0;
    for (int i = 1; i < n + n; ++i) {
        ans = (ans + nCr(cur_layers, k) * (e[i].first - e[i - 1].first))_;
        cur_layers += e[i].second;
    }
    printf("%I64d\n", ans);
    return 0;
}