#include <cstdio>
typedef long long int64;

int main()
{
    int64 n, k;
    scanf("%I64d%I64d", &n, &k);

    int64 r = n / 2 / (k + 1);
    printf("%I64d %I64d %I64d\n", r, r * k, n - r * (k + 1));

    return 0;
}