#include <cstdio>

int n;

int main()
{
    scanf("%d", &n);
    if (n == 1) { puts("-1"); return 0; }

    for (int i = n + 1; i <= 3 * n; ++i) {
        if (i * n % (i - n) == 0) { printf("%d %d %d\n", n, i, i * n / (i - n)); return 0; }
    }

    puts("-1");
    return 0;
}