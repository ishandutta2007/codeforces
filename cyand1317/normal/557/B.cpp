#include <cstdio>
#include <algorithm>
static const int MAXN = 100003;

int main()
{
    int n, w;
    int a[MAXN * 2];
    scanf("%d%d", &n, &w);
    for (int i = 0; i < n + n; ++i) scanf("%d", &a[i]);
    std::sort(a, a + n + n);

    double ans = (double)w / (3 * n);
    if (ans > (double)a[n] / 2) ans = (double)a[n] / 2;
    if (ans > a[0]) ans = a[0];
    printf("%.8lf\n", ans * n * 3.0);
    return 0;
}