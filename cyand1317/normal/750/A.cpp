#include <cstdio>

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    k = 240 - k;
    int ans = n;
    for (int i = 0; i <= n; ++i) {
        if (i * (i + 1) / 2 * 5 > k) { ans = i - 1; break; }
    }
    printf("%d\n", ans);
    return 0;
}