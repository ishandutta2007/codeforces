#include <stdio.h>
#define MAXN 11

int n;
double a[MAXN][MAXN] = {{ 0 }};

int main()
{
    int i, j, ans = 0;
    scanf("%d%lf", &n, &a[0][0]);
    for (i = 0; i < n; ++i) {
        for (j = 0; j <= i; ++j) if (a[i][j] >= 1) {
            a[i + 1][j] += (a[i][j] - 1) / 2;
            a[i + 1][j + 1] += (a[i][j] - 1) / 2;
            a[i][j] = 1;
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}