#include <cstdio>
#include <algorithm>
static const int MAXN = 200004;

int n, m;
int l1[MAXN], r1[MAXN], l2[MAXN], r2[MAXN];

int main()
{
    scanf("%d", &n); for (int i = 0; i < n; ++i) scanf("%d%d", &l1[i], &r1[i]);
    scanf("%d", &m); for (int i = 0; i < m; ++i) scanf("%d%d", &l2[i], &r2[i]);
    int r1_min = *std::min_element(r1, r1 + n),
        l1_max = *std::max_element(l1, l1 + n),
        r2_min = *std::min_element(r2, r2 + m),
        l2_max = *std::max_element(l2, l2 + m);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        // Select chess class #i
        int cur = std::max(l1[i] - r2_min, l2_max - r1[i]);
        ans = std::max(ans, cur);
    }
    printf("%d\n", ans);
    return 0;
}