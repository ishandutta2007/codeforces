#include <cstdio>
#include <algorithm>
static const int MAXN = 100006;

int n;
int a[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    std::sort(a, a + n);
    int ans = 1;
    for (int i = 0; i < n; ++i)
        if (a[i] >= ans) ++ans;
    printf("%d\n", ans);
    return 0;
}