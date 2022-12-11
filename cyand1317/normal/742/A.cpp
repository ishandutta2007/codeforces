#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    // (`)
    if (n == 0) puts("1"); else printf("%c\n", "6842"[n % 4]);
    return 0;
}