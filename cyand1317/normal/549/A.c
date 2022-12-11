#include <stdio.h>
#define MAXN 52

int main()
{
    int n, m, i, j;
    char p[MAXN][MAXN];
    scanf("%d%d\n", &n, &m);
    for (i = 0; i < n; ++i)
        for (j = 0; j <= m; ++j) p[i][j] = getchar();
    int c[128], ans = 0;
    for (i = 0; i < n - 1; ++i)
        for (j = 0; j < m - 1; ++j) {
            c['f'] = c['a'] = c['c'] = c['e'] = 0;
            ++c[p[i][j]]; ++c[p[i][j + 1]];
            ++c[p[i + 1][j]]; ++c[p[i + 1][j + 1]];
            if (c['f'] && c['a'] && c['c'] && c['e']) ++ans;
        }
    printf("%d\n", ans);
    return 0;
}