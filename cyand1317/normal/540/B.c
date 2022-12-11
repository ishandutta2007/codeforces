#include <stdio.h>
#define MAXN 1096

int main()
{
    int n, k, p, x, y, a[MAXN];
    int i;
    scanf("%d%d%d%d%d", &n, &k, &p, &x, &y);
    for (i = 0; i < k; ++i) scanf("%d", &a[i]);

    int sum = 0, ct = 0, ans_1 = 0, ans_median = 0;
    for (i = 0; i < k; ++i) {
        sum += a[i];
        if (a[i] >= y) ++ct;
    }
    if (ct < (n + 1) / 2) ans_median += (n + 1) / 2 - ct;
    ans_1 = n - k - ans_median;

    if (ans_1 < 0 || sum + ans_median * y + ans_1 * 1 > x) {
        printf("-1\n");
    } else {
        while (ans_1--) printf("1 ");
        while (ans_median--) printf("%d ", y);
        putchar('\n');
    }
    return 0;
}