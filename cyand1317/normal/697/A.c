#include <stdio.h>

int t, s, x;

unsigned char barks()
{
    if (x < t || x == t + 1) return 0;
    if (x == t) return 1;
    return ((x - t) % s == 0 || (x - t) % s == 1);
}

int main()
{
    scanf("%d%d%d", &t, &s, &x);
    puts(barks() ? "YES" : "NO");
    return 0;
}