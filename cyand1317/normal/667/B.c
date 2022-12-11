#include <stdio.h>
#define MAXN 100006

int n;

int main()
{
    scanf("%d", &n);
    long long sum = 0, max = 0, i;
    do {
        scanf("%I64d", &i);
        sum += i;
        if (max < i) max = i;
    } while (--n);
    printf("%I64d\n", max - (sum - max) + 1);
    return 0;
}