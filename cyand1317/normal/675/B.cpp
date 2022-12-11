#include <cstdio>

int n, a, b, c, d;

int main()
{
    scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);

    long long ans = 0;
    int p, q, y, z;
    for (p = 1; p <= n; ++p) {
        q = p + b - c;
        z = q + a - d;
        y = z + c - b;
        if (q >= 1 && q <= n && z >= 1 && z <= n && y >= 1 && y <= n)
            ++ans;
    }
    printf("%I64d\n", (long long)ans * n);

    return 0;
}