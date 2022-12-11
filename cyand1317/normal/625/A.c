#include <stdio.h>

int main()
{
    long long n, a, b, c;
    scanf("%I64d%I64d%I64d%I64d", &n, &a, &b, &c);
    long long ans = 0, cur;
    // Case #1 Buy plastic bottles
    cur = n / a;
    if (cur > ans) ans = cur;
    // Case #2 Buy glass bottles, then plastic bottles
    if (n >= b) {
        cur = (n - b) / (b - c) + 1;
        cur += (n - (b - c) * cur) / a;
        if (cur > ans) ans = cur;
    }
    // Case #3 Buy glass bottles, then glass bottles as many as possible
    if (n >= b) {
        cur = (n - b) / (b - c) + 1;
        cur += (n - (b - c) * cur) / b;
        if (cur > ans) ans = cur;
    }
    printf("%I64d\n", ans);
    return 0;
}