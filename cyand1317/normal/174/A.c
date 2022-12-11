#include <stdio.h>
#define MAXN 105

int n, b;
int a[MAXN], max_a = 0, sum_a = 0;

int main()
{
    int i;
    scanf("%d%d", &n, &b);
    for (i = 0 ; i < n; ++i) {
        scanf("%d", &a[i]);
        if (max_a < a[i]) max_a = a[i];
        sum_a += a[i];
    }

    if (b < max_a * n - sum_a) puts("-1");
    else {
        double extra = (double)(b - (max_a * n - sum_a)) / n;
        for (i = 0; i < n; ++i)
            printf("%.9lf\n", extra + (max_a - a[i]));
    }

    return 0;
}