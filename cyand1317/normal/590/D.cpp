#include <cstdio>
#include <cstring>
static const int MAXN = 152;
static const int MAXS = MAXN * MAXN / 2;
template <typename T> inline T min(const T a, const T b) { return a < b ? a : b; }
template <typename T> inline T max(const T a, const T b) { return a > b ? a : b; }
template <typename T> inline void update_min(T &var, const T val) { var = min(var, val); }

int n, k, s, q[MAXN];
int f[2][MAXN][MAXS];

int main()
{
    scanf("%d%d%d", &n, &k, &s);
    for (int i = 0; i < n; ++i) scanf("%d", &q[i]);
    k = min(k, n);

    memset(f, 0x3f, sizeof f);
    int cur = 0, next = 1;
    f[cur][0][0] = 0;
    f[cur][1][0] = q[0];

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j <= i + 1; ++j)
            for (int u = 0; u <= i * (i + 1) / 2; ++u) {
                update_min(f[next][j][u], f[cur][j][u]);
                update_min(f[next][j + 1][u + i + 1], f[cur][j][u] + q[i + 1]);
            }
        cur ^= 1; next ^= 1;
    }

    int allowed_idcsum = min(s + (k * (k - 1) / 2), n * (n - 1) / 2);
    int ans = 0x7fffffff;
    for (int i = 0; i <= allowed_idcsum; ++i) update_min(ans, f[cur][k][i]);
    printf("%d\n", ans);

    return 0;
}