#include <cstdio>
#include <algorithm>
#include <utility>
typedef long long int64;
static const int MAXN = 100005;

int n;
std::pair<int, int> p[MAXN];

inline int64 calc_first_dimension()
{
    std::sort(p, p + n);
    int64 ans = 0;
    int64 sum_lin = 0, sum_sqr = 0;
    for (int i = 0; i < n; ++i) {
        ans += (int64)p[i].first * p[i].first * i - (int64)p[i].first * sum_lin * 2 + sum_sqr;
        sum_lin += p[i].first;
        sum_sqr += (int64)p[i].first * p[i].first;
    }
    return ans;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d%d", &p[i].first, &p[i].second);

    int64 ans = calc_first_dimension();
    for (int i = 0; i < n; ++i) std::swap(p[i].first, p[i].second);
    ans += calc_first_dimension();
    printf("%I64d\n", ans);

    return 0;
}