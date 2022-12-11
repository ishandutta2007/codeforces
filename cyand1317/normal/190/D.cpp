#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
typedef long long int64;
static const int MAXN = 4e5 + 4;

int n, k;
int a[MAXN];
std::vector<int> occ[MAXN];
int rg[MAXN];

template <typename T> inline int discretize(int n, T *arr) {
    static std::pair<T, int> p[MAXN];
    for (int i = 0; i < n; ++i) p[i] = std::make_pair(arr[i], i);
    std::sort(p, p + n);
    int rk = 0;
    for (int i = 0; i < n; ++i) {
        if (i && p[i].first != p[i - 1].first) ++rk;
        arr[p[i].second] = rk;
    }
    return rk + 1;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int num_values = discretize(n, a);
    for (int i = 0; i < n; ++i) occ[a[i]].push_back(i);

    for (int i = 0; i < n; ++i) rg[i] = MAXN;
    for (int i = 0; i < num_values; ++i) {
        for (int j = 0; j <= (int)occ[i].size() - k; ++j)
            rg[occ[i][j]] = occ[i][j + k - 1];
    }

    int cur_rg = MAXN;
    int64 ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (cur_rg > rg[i]) cur_rg = rg[i];
        if (cur_rg != MAXN) ans += (n - cur_rg);
    }

    printf("%I64d\n", ans);
    return 0;
}