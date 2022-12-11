#include <cstdio>
#include <algorithm>
#include <utility>
typedef long long int64;
static const int MAXN = 100007;
static const int LOGN = 18;

int n;
int a[MAXN];
int64 sum[MAXN] = { 0 };

namespace rmq {

std::pair<int, int> f[MAXN][LOGN];

inline int log2(const int x) { return 8 * sizeof(int) - __builtin_clz(x - 1) - 1; }

void init()
{
    for (int i = 0; i < n; ++i) f[i][0] = std::make_pair(a[i], i);
    for (int i = 1; i < LOGN; ++i)
        for (int j = 0; j <= n - (1 << i); ++j)
            f[j][i] = std::max(f[j][i - 1], f[j + (1 << (i - 1))][i - 1]);
}

inline std::pair<int, int> query(int l, int r)
{
    int sz = log2(r - l + 1);
    return std::max(f[l][sz], f[r - (1 << sz) + 1][sz]);
}

}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d", &a[i]); --a[i];
    }
    rmq::init();

    int64 ans = 0;
    sum[n - 1] = 0;
    for (int i = n - 2; i >= 0; --i) {
        std::pair<int, int> p = rmq::query(i + 1, a[i]);
        sum[i] = sum[p.second] + (n - i - 1) - (a[i] - p.second);
        ans += sum[i];
    }

    printf("%I64d\n", ans);
    return 0;
}