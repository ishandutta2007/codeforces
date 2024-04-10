#include <cstdio>
#include <cstring>
typedef long long int64;
static const int MAXN = 18;
template <typename T>
inline void upd_max(T &var, const T val) { if (var < val) var = val; }

int n, m, k;
int satis[MAXN];
int bonus[MAXN][MAXN] = {{ 0 }};

int64 f[1 << MAXN][MAXN];

int64 calc_dp(int mask, int u)
{
    if (f[mask][u] >= 0) return f[mask][u];
    int64 ans = 0;
    for (int i = 0; i < n; ++i) if (i != u && (mask & (1 << i)))
        upd_max(ans, calc_dp(mask ^ (1 << u), i) + bonus[i][u]);
    return (f[mask][u] = ans + satis[u]);
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &satis[i]);
    int xi, yi;
    while (k--) {
        scanf("%d%d", &xi, &yi);
        scanf("%d", &bonus[xi - 1][yi - 1]);
    }

    memset(f, -1, sizeof f);
    for (int i = 0; i < n; ++i) f[1 << i][i] = satis[i];
    int64 ans = 0;
    for (int i = 0; i < (1 << n); ++i)
        if (__builtin_popcount(i) == m)
            for (int j = 0; j < n; ++j) if (i & (1 << j))
                upd_max(ans, calc_dp(i, j));
    printf("%I64d\n", ans);
    return 0;
}