#include <stdio.h>

int main()
{
    int n, i;
    scanf("%d", &n);
    if (n == 2) { printf("1\n1"); return 0; }
    else if (n == 3) { printf("2\n1 3"); return 0; }
    else if (n == 4) { printf("4\n3 1 4 2"); return 0; }
    printf("%d\n", n);
    for (i = n / 5 * 5; i < n; i += 2)
        printf("%d ", i + 1);
    for (i = 0; i < n / 5; ++i)
        printf("%d %d %d %d %d ", i * 5 + 1, i * 5 + 3, i * 5 + 5, i * 5 + 2, i * 5 + 4);
    for (i = n / 5 * 5 + 1; i < n; i += 2)
        printf("%d ", i + 1);
    return 0;
}