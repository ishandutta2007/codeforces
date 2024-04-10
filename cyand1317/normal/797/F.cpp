#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
typedef long long int64;
static const int MAXN = 5004;
static const int64 INF = 1LL << 61;

int n, m;
int mouse[MAXN];
std::pair<int, int> hole[MAXN];

int64 pfx[MAXN], f[MAXN];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &mouse[i]);
    for (int i = 0; i < m; ++i) scanf("%d%d", &hole[i].first, &hole[i].second);
    std::sort(mouse, mouse + n);
    std::sort(hole, hole + m);

    for (int i = 0; i < n; ++i) f[i] = INF;
    for (int i = 0; i < m; ++i) {
        pfx[0] = 0;
        for (int j = 0; j < n; ++j) pfx[j + 1] = pfx[j] + std::abs(mouse[j] - hole[i].first);
        int rem = hole[i].second;
        for (int sz = 1; rem > 0; ) {
            for (int j = n - sz; j >= 0; --j)
                f[j + sz - 1] = std::min(f[j + sz - 1], pfx[j + sz] - pfx[j] + (j == 0 ? 0 : f[j - 1]));
            rem -= sz;
            sz = std::min(sz << 1, rem);
        }
    }

    printf("%I64d\n", f[n - 1] >= INF / 2 ? -1LL : f[n - 1]);
    return 0;
}