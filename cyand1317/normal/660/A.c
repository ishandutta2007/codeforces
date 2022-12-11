#include <stdio.h>
#define MAXN 1005

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int n;
int a[MAXN];

int main()
{
    int ans = 0, i;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (i = 1; i < n; ++i) if (gcd(a[i - 1], a[i]) != 1) ++ans;
    printf("%d\n%d", ans, a[0]);
    for (i = 1; i < n; ++i) {
        if (gcd(a[i - 1], a[i]) != 1) printf(" 1");
        printf(" %d", a[i]);
    }
    return 0;
}