#include <stdio.h>

int abs(int x) { return x > 0 ? x : -x; }
int max(int a, int b) { return a > b ? a : b; }
int max4(int a, int b, int c, int d) { return max(max(a, b), max(c, d)); }
int main()
{
    int n, ai, p1, pn, i;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &ai);
        if (ai == 1) p1 = i; else if (ai == n) pn = i;
    }
    printf("%d\n", max4(
        abs(n - 1 - p1), abs(n - 1 - pn),
        abs(p1), abs(pn)
    ));
    return 0;
}