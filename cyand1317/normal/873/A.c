#include <stdio.h>
#define MAXN    103

int n, k, x;
int a[MAXN];

int main()
{
    int i;
    int ans = 0;

    scanf("%d%d%d", &n, &k, &x);
    for (i = 0; i < n; ++i) scanf("%d", &a[i]);

    for (i = 0; i < n - k; ++i) ans += a[i];
    for (i = n - k; i < n; ++i) ans += x;
    printf("%d\n", ans);

    return 0;
}