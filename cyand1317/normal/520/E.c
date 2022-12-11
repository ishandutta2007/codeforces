#include <stdio.h>
#define MAXN 200004 // It has to be 2*10^5 instead of 1*10^5... Why??!
#define DIVISOR 1000000007

long long extgcd(long long a, long long b, long long *x, long long *y)
{
    if (b == 0) {
        *x = 1; *y = 0;
        return a;
    } else {
        long long r = extgcd(b, a % b, x, y);
        long long t = *x; *x = *y; *y = t - (a / b) * *y;
        return r;
    }
}

int main()
{
    int n, k, d[MAXN], i, l;
    scanf("%d%d\n", &n, &k);
    for (i = 0; i < n; i++) d[i] = getchar() - '0';

    // For detailed explanations see the editorial.
    // Preprocessing
    int sumd[MAXN] = { d[0] };
    for (i = 1; i < n; i++) sumd[i] = sumd[i - 1] + d[i];

    long long tenpow[MAXN] = { 1 };
    for (i = 1; i < n; i++) tenpow[i] = (tenpow[i - 1] * 10) % DIVISOR;

    long long fact[MAXN] = { 1 }, modinv[MAXN] = { 1 };
    for (i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % DIVISOR;
        long long x, y, g = extgcd(fact[i], DIVISOR, &x, &y);
        if (g == 1) modinv[i] = (x + DIVISOR) % DIVISOR;
        else { printf("This is impossible since DIVISOR is a prime.\n"); break; }
    }

    // Simple evaluation of the expression.
    long long ans = 0;
    // Divide ans by DIVISOR whenever possible.
#define combination(_n, _k) \
  (((fact[(_n)] * modinv[(_k)]) % DIVISOR * modinv[(_n) - (_k)]) % DIVISOR)
    for (l = 0; l < n - 1; l++) {
        ans += (tenpow[l] * combination(n - l - 2, k - 1) % DIVISOR) * sumd[n - l - 2];
        ans %= DIVISOR;
    }

    for (i = 0; i < n; i++) {
        ans += (d[i] * tenpow[n - i - 1] % DIVISOR) * combination(i, k);
        ans %= DIVISOR;
    }

    printf("%I64d\n", ans);
    return 0;
}