#include <stdio.h>

int a, b, c;

unsigned char inquire()
{
    if (a == b || c == 0) return (a == b);
    if ((b > a) ^ (c > 0)) return 0;
    return (b - a) % c == 0;
}

int main()
{
    scanf("%d%d%d", &a, &b, &c);
    puts(inquire() ? "YES" : "NO");
    return 0;
}