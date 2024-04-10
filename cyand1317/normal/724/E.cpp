#include <cstdio>
typedef long long int64;
static const int64 INF64 = (1LL << 61);
static const int MAXN = 10009;
template <typename T> inline T min(const T a, const T b) { return a < b ? a : b; }

int n, c, p[MAXN], s[MAXN];
int64 f[2][MAXN]; int cur = 0;

int main()
{
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; ++i) scanf("%d", &p[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &s[i]);

    for (int i = 0; i <= n + 1; ++i) f[0][i] = f[1][i] = INF64;
    f[cur][0] = 0;
    for (int i = 0; i < n; ++i) {
        cur ^= 1;
        f[cur][0] = f[cur ^ 1][0] + p[i];
        for (int j = 1; j <= i + 1; ++j)
            f[cur][j] = min(f[cur ^ 1][j - 1] + s[i], f[cur ^ 1][j] + p[i] + (int64)c * j);
        //for (int j = 0; j <= i + 1; ++j)
        //    printf("%lld%c", f[cur][j], j == i + 1 ? '\n' : ' ');
    }

    int64 ans = INF64;
    for (int i = 0; i <= n; ++i) ans = min(ans, f[cur][i]);
    printf("%I64d\n", ans);

    return 0;
}