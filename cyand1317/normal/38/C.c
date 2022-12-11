#include <stdio.h>
#define MAXN 104

int n, l;
int a[MAXN];

int main()
{
    int i, j;
    scanf("%d%d", &n, &l);
    for (i = 0; i < n; ++i) scanf("%d", &a[i]);

    int ans = 0, cur;
    for (i = l; i <= 100; ++i) {
        cur = 0;
        for (j = 0; j < n; ++j) cur += a[j] / i;
        cur *= i;
        if (ans < cur) ans = cur;
    }
    printf("%d\n", ans);

    return 0;
}