#include <cstdio>

int t, a, b;

inline double answer(int a, int b)
{
    if (b == 0) return 1.0;
    if (a == 0) return 0.5;
    long long area_tot = 2LL * a * b;
    if (a >= 4 * b) return (double)(area_tot - 2LL * b * b) / area_tot;
    else return (0.5 * a * ((double)b + b + 0.25 * a)) / area_tot;
}

int main()
{
    scanf("%d", &t);

    do {
        scanf("%d%d", &a, &b);
        printf("%.12lf\n", answer(a, b));
    } while (--t);

    return 0;
}