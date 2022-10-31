#include <cstdio>

int main()
{
    int n, x;

    scanf("%d%d", &n, &x);

    int rje=0;
    for (int i=1; i<=n; i++)
        if (!(x % i) && x / i <= n)
            rje++;

    printf("%d\n", rje);

    return 0;
}