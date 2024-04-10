#include <cstdio>

const double eps = 1e-7;

int main()
{
    int t, T;
    double a, b;
    scanf("%d", &T);
    for (t = 0; t < T; ++t)
    {
        scanf("%lf %lf", &a, &b);
        if (b < eps)
        {
            printf("1.0000\n");
            continue;
        }
        if (a < eps)
        {
            printf("0.5000000\n");
            continue;
        }
        if (a / 4 < b + eps)
        {
            printf("%.10lf\n", (a * b + a * a / 4 / 2) / (a * b * 2.0));
        }
        else
        {
            printf("%.10lf\n", (a * b * 2.0 - b * b * 4 / 2) / (a * b * 2.0));
        }
    }
    return 0;
}