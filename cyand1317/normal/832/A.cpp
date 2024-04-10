#include <cstdio>
typedef long long int64;

int main()
{
    int64 n, k;
    scanf("%I64d%I64d", &n, &k);

    int64 t = n / k;
    puts((t & 1) ? "YES" : "NO");

    return 0;
}