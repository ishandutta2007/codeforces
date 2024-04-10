#include <stdio.h>
#define MAXN 100003

int main()
{
    int a[MAXN], p[MAXN];
    int n, m, k, b, i;
    long long ans = 0;
    scanf("%d%d%d", &n, &m, &k);
    for (i = 0; i < n; ++i) { scanf("%d", &a[i]); --a[i]; p[a[i]] = i; }
    for (i = 0; i < m; ++i) {
        scanf("%d", &b); --b;
        // Launch it
        ans += (long long)(p[b] / k + 1);
        // Berdroid desktop kernel...
        if (p[b] > 0) {
            ++p[a[p[b] - 1]]; --p[b];
            int t = a[p[b]]; a[p[b]] = b; a[p[b] + 1] = t;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}