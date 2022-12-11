#include <stdio.h>
#define MAXN 100004

int main()
{
    int n, i;
    int a[MAXN], d[MAXN];
    scanf("%d", &n);
    for (i = 0; i < n; ++i) scanf("%d", &a[i]);

    int max = 0;
    for (i = n - 1; i >= 0; --i) {
        d[i] = a[i] > max ? 0 : max + 1 - a[i];
        if (max < a[i]) max = a[i];
    }
    printf("%d", d[0]);
    for (i = 1; i < n; ++i) printf(" %d", d[i]);
    putchar('\n');
    return 0;
}