#include <cstdio>
#include <algorithm>
#include <utility>
typedef long long int64;
static const int64 INF = 1LL << 62;
static const int MAXN = 5003;

int n, a[MAXN];
int64 s[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    s[0] = 0;
    for (int i = 0; i < n; ++i) s[i + 1] = s[i] + a[i];

    int64 ans = -INF;
    int ans_d1 = -1, ans_d2 = -1, ans_d3 = -1;
    for (int d2 = 0; d2 <= n; ++d2) {
        std::pair<int64, int> d1_best(-INF, -1);
        std::pair<int64, int> d3_best(-INF, -1);
        for (int d1 = 0; d1 <= d2; ++d1)
            d1_best = std::max(d1_best, { s[d1] - (s[d2] - s[d1]), d1 });
        for (int d3 = d2; d3 <= n; ++d3)
            d3_best = std::max(d3_best, { (s[d3] - s[d2]) - (s[n] - s[d3]), d3 });

        int64 cur = d1_best.first + d3_best.first;
        if (ans < cur) {
            ans = cur;
            ans_d1 = d1_best.second;
            ans_d2 = d2;
            ans_d3 = d3_best.second;
        }
    }

    printf("%d %d %d\n", ans_d1, ans_d2, ans_d3);
    return 0;
}