#include <cstdio>

int k, n;

int main()
{
    scanf("%d%d", &k, &n); k %= 10;
    int ans = 1, x = k;
    while (x != n && x != 0) { x = (x + k) % 10; ++ans; }
    printf("%d\n", ans);
    return 0;
}