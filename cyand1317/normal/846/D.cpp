#include <cstdio>
static const int MAXN = 503;
static const int INF = 0x3fffffff;

int n, m, k, q;
int v[MAXN][MAXN];
int s[MAXN][MAXN];

inline bool check(int t)
{
    for (int i = 0; i <= n; ++i) s[i][0] = 0;
    for (int i = 0; i <= m; ++i) s[0][i] = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j] + (v[i][j] <= t);

    /*printf("=== Check %d ===\n", t);
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            printf("%d%c", s[i][j], j == m ? '\n' : ' ');
    for (int i = 0; i <= n - k; ++i)
        for (int j = 0; j <= m - k; ++j)
            printf("%d%c", s[i + k][j + k] - s[i][j + k] - s[i + k][j] + s[i][j], j == m - k ? '\n' : ' ');*/

    for (int i = 0; i <= n - k; ++i)
        for (int j = 0; j <= m - k; ++j)
            if (s[i + k][j + k] - s[i][j + k] - s[i + k][j] + s[i][j] == k * k)
                return false;

    return true;
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &k, &q);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            v[i][j] = INF;
    for (int i = 0, r, c, w; i < q; ++i) {
        scanf("%d%d%d", &r, &c, &w); --r, --c;
        v[r][c] = w;
    }

    int lo = -1, hi = INF, mid;
    while (lo < hi - 1) {
        mid = (lo + hi) >> 1;
        if (!check(mid)) hi = mid; else lo = mid;
    }

    printf("%d\n", hi == INF ? -1 : hi);
    return 0;
}