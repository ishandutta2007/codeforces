#include <stdio.h>
#define MAXN 512

int n, k;
int a[MAXN][MAXN];

int main()
{
    scanf("%d%d", &n, &k);
    int i, j, x = 0;
    for (i = 0; i < n; ++i)
        for (j = 0; j < k - 1; ++j) a[i][j] = ++x;
    for (i = 0; i < n; ++i)
        for (j = k - 1; j < n; ++j) a[i][j] = ++x;
    int ans = 0;
    for (i = 0; i < n; ++i) ans += a[i][k - 1];
    printf("%d\n", ans);
    for (i = 0; i < n; ++i) {
        printf("%d", a[i][0]);
        for (j = 1; j < n; ++j) printf(" %d", a[i][j]);
        putchar('\n');
    }
    return 0;
}