#include <stdio.h>

int main()
{
    int a, b, c, x, y, z;
    scanf("%d%d%d%d%d%d", &a, &b, &c, &x, &y, &z);
    x -= a; y -= b; z -= c;
    int pos = 0, neg = 0;
    if (x > 0) pos += x; else neg -= x / 2;
    if (y > 0) pos += y; else neg -= y / 2;
    if (z > 0) pos += z; else neg -= z / 2;
    puts(neg >= pos ? "Yes" : "No");
    return 0;
}