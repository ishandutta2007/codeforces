#include <stdio.h>

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int main()
{
    int n;
    int min1, min2, min3;
    int max1, max2, max3;
    scanf("%d%d%d%d%d%d%d", &n, &min1, &max1, &min2, &max2, &min3, &max3);
    int n1 = min1, n2 = min2, n3 = min3;
    int remain = n - n1 - n2 - n3;
    int t;
    t = min(remain, max1 - min1);
    remain -= t; n1 += t;
    t = min(remain, max2 - min2);
    remain -= t; n2 += t;
    t = min(remain, max3 - min3);
    remain -= t; n3 += t;
    printf("%d %d %d\n", n1, n2, n3);
    return 0;
}