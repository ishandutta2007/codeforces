#include <cstdio>
#include <cstring>

int n, m, k;

double fac[1 << 20];

double com(int n, int k)
{
    if (k < 0)
        return 0;
    // printf("COM %d %d :: %lf %lf %lf\n", n, k, fac[n], fac[k], fac[n - k]);
    return 1.0 / (fac[k] * fac[n - k]);
}

double cat(int n)
{
    return com(n * 2, n) / (n + 1);
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);

    fac[0] = 1.0;
    for (int i = 1; i < 300000; ++i)
        fac[i] = fac[i - 1] * i;
    double all = com(n + m, n);
    double good;

    if (n == 0)
    {
        printf("%d\n", k >= m);
        return 0;
    }
    if (m == 0)
    {
        printf("1\n");
        return 0;
    }

    if (k == 0 && n == m)
    {
        printf("%.10lf\n", 1.0 / (n + 1));
        return 0;
    }
    else if (k + n < m)
    {
        printf("0\n");
        return 0;
    }
    else
    {
        good = all - com(n + m, m - k - 1);
        double ans = 1.0;
        for (int i = 0; i <= k; ++i)
        {
            ans = ans / (n + i + 1) * (m - i);
        }
        printf("%.10lf\n", 1.0 - ans);
    }
    return 0;
}