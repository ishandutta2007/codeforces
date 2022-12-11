#include <stdio.h>
typedef long long int64;

int64 n;
int64 m, k;

int main()
{
    scanf("%I64d", &n);
    int64 parity = (1LL << __builtin_ctz(n));
    n >>= __builtin_ctz(n);

    if (n == 1) {
        if (parity < 4) { puts("-1"); return 0; }
        n = parity;
        m = n / 4 * 3;
        k = n / 4 * 5;
    } else {
        n >>= 1;
        m = (n + 1) * n * 2;
        k = m + 1;
        m *= parity; k *= parity;
    }
    printf("%I64d %I64d\n", m, k);

    return 0;
}