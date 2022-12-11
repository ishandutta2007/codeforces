#include <cstdio>

int main()
{
    int n, ans = -1;

    scanf("%d", &n);

    for (int k = 1; k < 10; ++k)
        if (n % (((1 << k) - 1) << (k - 1)) == 0) ans = k;

    printf("%d\n", ((1 << ans) - 1) << (ans - 1));

    return 0;
}