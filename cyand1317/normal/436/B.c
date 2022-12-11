#include <stdio.h>
#define MAXN 2000

#define IS_SPIDER(row, col, val) \
    ((row) >= 0 && (row) < n && (col) >= 0 && (col) < m \
        && p[(row)][(col)] == val)
int main()
{
    int n, m, i, j;
    scanf("%d%d%d\n", &n, &m, &i);
    char p[MAXN][MAXN];
    for (i = 0; i < n; i++) gets(p[i]);
    for (i = 0; i < m; i++) {
        int ans = 0;
        for (j = 0; j < n; j++) {
            ans += IS_SPIDER(j + j, i, 'U')
                + IS_SPIDER(j, i - j, 'R')
                + IS_SPIDER(j, i + j, 'L');
            // Omit all spiders moving down. Om Nom will not come across them.
        }
        printf("%d ", ans);
    }
    putchar('\n');
    return 0;
}