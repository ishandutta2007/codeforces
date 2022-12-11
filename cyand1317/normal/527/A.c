#include <stdio.h>

int main()
{
    long long a, b, ans = 0;
    scanf("%lld%lld", &a, &b);
    do {
        ans += a / b;
        long long t = b;
        b = a % b;
        a = t;
    } while (b);
    printf("%lld\n", ans);
    return 0;
}