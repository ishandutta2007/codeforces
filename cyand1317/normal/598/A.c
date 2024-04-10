#include <stdio.h>

int main()
{
    int t;
    long long n, ans, i;
    scanf("%d", &t);
    do {
        scanf("%I64d", &n);
        ans = n * (n + 1) / 2;
        i = 1;
        while (i <= n) ans -= (i += i);
        printf("%I64d\n", ans);
    } while (--t);
    return 0;
}