#include <cstdio>

int x, y, a, b;

int main()
{
    scanf("%d%d%d%d", &x, &y, &a, &b);

    int ans = 0;
    for (int p = 0; p <= 100; ++p)
        for (int q = 0; q < p; ++q)
            if (p <= x && p >= a && q <= y && q >= b) ++ans;
    printf("%d\n", ans);
    for (int p = 0; p <= 100; ++p)
        for (int q = 0; q < p; ++q)
            if (p <= x && p >= a && q <= y && q >= b) printf("%d %d\n", p, q);

    return 0;
}