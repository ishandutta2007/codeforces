#include <stdio.h>
int main() {
    long long a, b, ans;
    scanf("%lld %lld", &a, &b);
    ans = a*(a+1)/2;
    ans %= 1000000007;
    ans *= b;
    ans %= 1000000007;
    ans += a;
    ans %= 1000000007;
    ans *= (b*(b-1)/2)%1000000007;
    ans %= 1000000007;
    printf("%lld", ans);
    return 0;
}