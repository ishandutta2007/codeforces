#include <stdio.h>

int main()
{
    int a, b, t;
    scanf("%d%d", &a, &b);
    if (a < b) { t = a; a = b; b = t; }
    printf("%d %d\n", b, (a - b) / 2);
    return 0;
}