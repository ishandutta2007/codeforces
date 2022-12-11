#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    printf("%I64d\n", (long long)(n - 2) * (n - 2));
    return 0;
}