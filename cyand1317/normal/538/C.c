#include <stdio.h>
#include <stdlib.h>
#define MAXM 100096
#define max(_a, _b) ((_a) > (_b) ? (_a) : (_b))

int main()
{
    int n, m, i;
    int d[MAXM], h[MAXM];
    scanf("%d%d", &n, &m);
    for (i = 0; i < m; ++i) scanf("%d%d", &d[i], &h[i]);

    int impossible = 0, maxh = -1;
    for (i = 1; i < m; ++i)
        if (abs(d[i] - d[i - 1]) < abs(h[i] - h[i - 1])) {
            impossible = 1; break;
        } else {
            int t = abs(d[i] - d[i - 1]) - abs(h[i] - h[i - 1]),
                dh = max(h[i], h[i - 1]);
            maxh = max(maxh, dh + t / 2);
        }
    if (impossible) puts("IMPOSSIBLE");
    else {
        // Tricky samples T^T
        maxh = max(maxh, h[0] + d[0] - 1);
        maxh = max(maxh, h[m - 1] + n - d[m - 1]);
        printf("%d\n", maxh);
    }
    return 0;
}