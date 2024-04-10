#include <cstdio>
static const int MAXN = 1e5 + 4;

int n;
int a[MAXN];
int ans = 1, cur;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    cur = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] <= a[i - 1]) cur = 1;
        else if (ans < ++cur) ans = cur;
    }

    printf("%d\n", ans);
    return 0;
}