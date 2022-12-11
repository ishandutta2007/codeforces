#include <cstdio>
#include <algorithm>

static const int MAXN = 1e5 + 4;

static int n, a[MAXN];
static int s, f;
static int u[MAXN * 2];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    scanf("%d%d", &s, &f);
    --s, --f;

    u[0] = 0;
    for (int i = 0; i < n * 2; ++i) u[i + 1] = u[i] + a[i % n];

    int ans = -1, best = -1;
    for (int i = 0; i < n; ++i) {
        int num = u[f + i] - u[s + i];
        if (best < num) { best = num; ans = n + 1; }
        if (best == num && ans > (n - i) % n + 1) ans = (n - i) % n + 1;
    }

    printf("%d\n", ans);
    return 0;
}