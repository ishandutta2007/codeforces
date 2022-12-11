#include <stdio.h>

int n, m;

int main()
{
    scanf("%d%d", &n, &m);

    int i = 0;
    if (n % m == 0) {
        for (; i < m; ++i) printf("%d%c", n / m, i == n - 1 ? '\n' : ' ');
    } else {
        for (; i < n % m; ++i) printf("%d ", n / m + 1);
        for (; i < m; ++i) printf("%d%c", n / m, i == n - 1 ? '\n' : ' ');
    }

    return 0;
}