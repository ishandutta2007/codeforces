#include <stdio.h>

double fpow(double b, int e)
{
    double ans = 1;
    while (e) {
        if (e & 1) ans *= b;
        b *= b;
        e >>= 1;
    }
    return ans;
}

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    int i;
    double ans = 0;
    for (i = m; i > 0; --i) {
        ans += i * (fpow((double)i / m, n) - fpow((double)(i - 1) / m, n));
    }
    printf("%lf\n", ans);
    return 0;
}