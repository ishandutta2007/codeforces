#include <cstdio>

int main()
{
    int a, b, c, x, y, z, r=1;

    scanf("%d%d%d", &a, &b, &c);

    if ((a+c-b) & 1)
        r = 0;
    else {
        y = (a + c - b) / 2;
        x = a - y;
        z = c - y;
    }

    if (!r || y < 0 || x < 0 || z < 0)
        printf("Impossible\n");
    else
        printf("%d %d %d\n", x, z, y);

    return 0;
}