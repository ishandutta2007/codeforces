#include <stdio.h>
#define MAXN 1096
#define min(_a, _b) ((_a) < (_b) ? (_a) : (_b))

int main()
{
    int n, i, t, d[MAXN], ans = 0;
    scanf("%d", &n); getchar();
    for (i = 0; i < n; ++i) d[i] = getchar() - '0';
    getchar();
    for (i = 0; i < n; ++i) {
        t = getchar() - '0';
        ans += min((t - d[i] + 20) % 10, (d[i] - t + 20) % 10);
    }
    printf("%d\n", ans);
    return 0;
}