#include <stdio.h>
#define MAXN 512

int n, m;
char a[MAXN][MAXN];
int count[4][MAXN][MAXN];
#define rowonecnt count[0]
#define rowsegcnt count[1]
#define colonecnt count[2]
#define colsegcnt count[3]

int main()
{
    scanf("%d%d", &n, &m); getchar();
    int i, j;
    for (i = 0; i < n; ++i)
        for (j = 0; j <= m; ++j) a[i][j] = (getchar() == '.');
    // Precalculate
    for (i = 0; i < n; ++i) {
        rowonecnt[i][0] = rowsegcnt[i][0] = a[i][0];
        for (j = 1; j < m; ++j) {
            rowonecnt[i][j] = rowonecnt[i][j - 1] + a[i][j];
            rowsegcnt[i][j] = rowsegcnt[i][j - 1] + (a[i][j] && !a[i][j - 1]);
        }
    }
    for (j = 0; j < m; ++j) {
        colonecnt[0][j] = colsegcnt[0][j] = a[0][j];
        for (i = 1; i < n; ++i) {
            colonecnt[i][j] = colonecnt[i - 1][j] + a[i][j];
            colsegcnt[i][j] = colsegcnt[i - 1][j] + (a[i][j] && !a[i - 1][j]);
        }
    }
    // Read queries
    int q, r1, c1, r2, c2, ans;
    scanf("%d", &q);
    do {
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        --r1, --c1, --r2, --c2; ans = 0;
        for (i = r1; i <= r2; ++i)
            ans += (rowonecnt[i][c2] - (c1 ? rowonecnt[i][c1 - 1] : 0)) - (rowsegcnt[i][c2] - rowsegcnt[i][c1] + a[i][c1]);
        for (j = c1; j <= c2; ++j)
            ans += (colonecnt[r2][j] - (r1 ? colonecnt[r1 - 1][j] : 0)) - (colsegcnt[r2][j] - colsegcnt[r1][j] + a[r1][j]);
        printf("%d\n", ans);
    } while (--q);
    return 0;
}