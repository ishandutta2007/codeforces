#include <stdio.h>

int main()
{
    int n, m;
    long long ans = 0;
    scanf("%d%d", &n, &m);
    ans += (long long)(n / 5) * (m / 5);
    for (int i = 1; i < 5; ++i) {
        ans += (long long)(n / 5 + (n % 5 >= i)) * (m / 5 + (m % 5 >= (5 - i)));
    }
    printf("%I64d\n", ans);
    return 0;
}