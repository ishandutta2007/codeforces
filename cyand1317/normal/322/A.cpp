#include <cstdio>

int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    printf("%d\n", n + m - 1);
    for (int i = 0; i < m; ++i) printf("1 %d\n", i + 1);
    for (int i = 1; i < n; ++i) printf("%d 1\n", i + 1);
    return 0;
}