#include <stdio.h>
#define MAXN 1024

int main()
{
    int n, i, j, ans = 0;
    int a[MAXN];
    unsigned char collected[MAXN] = { 0 };

    scanf("%d", &n);
    for (i = 0; i < n; ++i) scanf("%d", &a[i]);
    i = j = 0;  // i - current position; j - pieces of information
    while (j < n) {
        for (i = 0; i < n; ++i) if (!collected[i] && a[i] <= j) {
            ++j;
            collected[i] = 1;
        }
        if (j == n) break;
        ++ans;
        for (i = n - 1; i >= 0; --i) if (!collected[i] && a[i] <= j) {
            ++j;
            collected[i] = 1;
        }
        if (j == n) break;
        ++ans;
    }
    printf("%d\n", ans);

    return 0;
}