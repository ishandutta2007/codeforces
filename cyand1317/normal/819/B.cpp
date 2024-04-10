#include <cstdio>
#include <algorithm>
typedef long long int64;
static const int MAXN = 1e6 + 4;
static const int64 INF = 1LL << 61;

int n;
int p[MAXN];
int64 f[MAXN * 2] = { 0 };
int64 g[MAXN * 2] = { 0 };
int64 h[MAXN * 2];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &p[i]), --p[i];

    for (int i = 0; i < n; ++i) {
        int p1 = n - i,
            p2 = p1 + p[i] + 1,
            p3 = p1 + n;
        f[p1] += p[i] + 1; g[p1] -= 1;
        g[p2] += 2;
        f[p3] -= n - p[i] - 1; g[p3] -= 1;
    }

    int64 val = 0, slope = 0;
    for (int i = 0; i < n * 2; ++i) {
        slope += g[i];
        val += (f[i] + slope);
        h[i] = val;
    }

    std::pair<int64, int> ans(INF, -1);
    for (int i = 0; i < n; ++i) ans = std::min(ans, std::make_pair(h[i] + h[i + n], i));
    printf("%I64d %d\n", ans.first, ans.second);

    return 0;
}