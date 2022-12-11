#include <stdio.h>
#define MAXN 100005

int n;
int a[MAXN];

int main()
{
    int i, j, ans = 0;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (i = 0; i < n; i = j) {
        j = i + 1;
        while (j < n && a[j] >= a[j - 1]) ++j;
        if (ans < j - i) ans = j - i;
    }
    printf("%d\n", ans);
    return 0;
}