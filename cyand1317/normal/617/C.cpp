#include <cstdio>
#include <algorithm>
#include <utility>
typedef long long int64;
static const int MAXN = 2004;

int n, x1, y1, x2, y2;
std::pair<int64, int64> p[MAXN];
int64 sqr(int64 x) { return x * x; }
int64 r_max[MAXN];

int main()
{
    scanf("%d%d%d%d%d", &n, &x1, &y1, &x2, &y2);
    int xi, yi;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &xi, &yi);
        p[i].first = sqr(xi - x1) + sqr(yi - y1);
        p[i].second = sqr(xi - x2) + sqr(yi - y2);
    }
    std::sort(p, p + n);

    r_max[n] = 0;
    for (int i = n - 1; i >= 0; --i)
        r_max[i] = std::max(r_max[i + 1], p[i].second);

    int64 ans = r_max[0];
    for (int i = 0; i < n; ++i)
        ans = std::min(ans, p[i].first + r_max[i + 1]);

    printf("%I64d\n", ans);
    return 0;
}