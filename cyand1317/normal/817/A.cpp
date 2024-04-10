#include <cstdio>

int x1, y1, x2, y2;
int dx, dy;

int main()
{
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &dx, &dy);

    int mx = x1 - x2, my = y1 - y2;
    if (mx % dx != 0 || my % dy != 0) { puts("NO"); return 0; }
    if (((mx / dx) ^ (my / dy)) & 1) { puts("NO"); return 0; }
    puts("YES"); return 0;
}