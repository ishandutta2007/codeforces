#include <stdio.h>
#define MAXN 15
#define INF 0x7fffffff

int main()
{
    int n, l, r, x;
    int i, j, c[MAXN];
    scanf("%d%d%d%d", &n, &l, &r, &x);
    for (i = 0; i < n; ++i) scanf("%d", &c[i]);

    int min, max, sum, ct, ans = 0;
    // Brute force.
    for (i = 0; i < (1 << n); ++i) {
        min = INF, max = sum = ct = 0;
        for (j = 0; j < n; ++j) if ((i >> j) & 1) {
            ++ct;
            sum += c[j];
            if (min > c[j]) min = c[j];
            if (max < c[j]) max = c[j];
        }
        if (ct >= 2 && sum >= l && sum <= r && max - min >= x) ++ans;
    }
    printf("%d\n", ans);
    return 0;
}