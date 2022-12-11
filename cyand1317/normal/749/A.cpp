#include <cstdio>

int n;

int main()
{
    scanf("%d", &n);
    printf("%d\n", n / 2);
    while (n > 3) { printf("2 "); n -= 2; }
    if (n > 0) printf("%d\n", n); else putchar('\n');
    return 0;
}