#include <cstdio>

int n, c, ti, last_ti = 0x80000000;
int ans = 0;

int main()
{
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &ti);
        if (ti - last_ti > c) ans = 1; else ++ans;
        last_ti = ti;
    }
    printf("%d\n", ans);
    return 0;
}