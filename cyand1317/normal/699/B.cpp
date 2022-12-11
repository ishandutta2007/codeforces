#include <cstdio>
static const int MAXN = 1024;

int n, m, wallblock_ct = 0;
char g[MAXN][MAXN];
int row_wbc[MAXN] = { 0 }, col_wbc[MAXN] = { 0 };

int main()
{
    scanf("%d%d", &n, &m); getchar();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= m; ++j) {
            g[i][j] = getchar();
            if (g[i][j] == '*') {
                ++wallblock_ct;
                ++row_wbc[i];
                ++col_wbc[j];
            }
        }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (row_wbc[i] + col_wbc[j] - (g[i][j] == '*') == wallblock_ct) {
                printf("YES\n%d %d\n", i + 1, j + 1);
                return 0;
            }
        }

    puts("NO");
    return 0;
}