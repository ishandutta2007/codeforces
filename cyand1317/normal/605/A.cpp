#include <stdio.h>
#define MAXN 100004

int n;
int ai, p[MAXN] = { 0 };

int main()
{
    int i, j;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &ai);
        p[ai] = i;
    }

    int ans = 0;
    for (i = 1; i <= n;) {
        j = i;
        while (p[j] < p[j + 1]) ++j;
        if (j - i + 1 > ans) ans = j - i + 1;
        i = j + 1;
    }
    printf("%d\n", n - ans);
    return 0;
}