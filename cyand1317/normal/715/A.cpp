#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    puts("2");
    for (long long i = 2; i <= n; ++i) {
        printf("%I64d\n", i * (i + 1) * (i + 1) + 1 - i);
    }

    return 0;
}