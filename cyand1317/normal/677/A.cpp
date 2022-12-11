#include <cstdio>

int main()
{
    int n, h, h_i;
    int ans = 0;
    scanf("%d%d", &n, &h);
    do {
        scanf("%d", &h_i);
        ans += (h_i <= h ? 1 : 2);
    } while (--n);
    printf("%d\n", ans);
    return 0;
}