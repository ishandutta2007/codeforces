#include <cstdio>
#include <algorithm>
static const int MAXN = 1e5 + 4;

int n, m;
int a[MAXN], b[MAXN];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i) scanf("%d", &b[i]);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int p = std::lower_bound(b, b + m, a[i]) - &b[0], q = p - 1;
        int min_dist = 2e9 + 10;
        if (p < m) min_dist = std::min(min_dist, b[p] - a[i]);
        if (q >= 0) min_dist = std::min(min_dist, a[i] - b[q]);
        ans = std::max(ans, min_dist);
    }

    printf("%d\n", ans);
    return 0;
}