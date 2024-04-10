#include <cstdio>
typedef long long int64;

int n; int64 k;

int main()
{
    scanf("%d%I64d", &n, &k);
    printf("%d\n", __builtin_ctzll(k) + 1);
    return 0;
}