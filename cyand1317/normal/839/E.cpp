#include <cstdio>
static const int MAXN = 42;
template <typename T> inline void upd_max(T &var, const T val) { if (var < val) var = val; }

int n, k;
int g[MAXN][MAXN];

int l[1 << (MAXN / 2)], r[1 << (MAXN / 2)];

inline void process(int sz, int offs, int *f)
{
    f[0] = 0;
    for (int mask = 1; mask < (1 << sz); ++mask)
        if (__builtin_popcount(mask) == 1) {
            f[mask] = 1;
        } else {
            f[mask] = 0;
            for (int u = 0; u < sz; ++u) if (mask & (1 << u)) {
                bool conn = true;
                for (int v = 0; v < sz; ++v) if (u != v && (mask & (1 << v))) {
                    if (!g[offs + u][offs + v]) { conn = false; break; }
                }
                upd_max(f[mask], f[mask ^ (1 << u)] + (int)conn);
            }
        }
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) scanf("%d", &g[i][j]);

    int lsz = n / 2, rsz = n - lsz;
    process(lsz, 0, l);
    process(rsz, lsz, r);

    int cliq = 0;
    for (int i = 0; i < (1 << lsz); ++i) if (l[i] == __builtin_popcount(i)) {
        int rmask = 0;
        for (int u = 0; u < rsz; ++u) {
            bool conn = true;
            for (int v = 0; v < lsz; ++v)
                if ((i & (1 << v)) && !g[lsz + u][v]) { conn = false; break; }
            if (conn) rmask |= (1 << u);
        }
        upd_max(cliq, l[i] + r[rmask]);
    }

    double ans = (double)k / cliq * k * (cliq - 1) / 2;
    printf("%.8lf\n", ans);

    return 0;
}