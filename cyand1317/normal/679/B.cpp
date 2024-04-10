#include <cstdio>
#include <algorithm>
#include <utility>
typedef long long int64;

std::pair<int64, int64> inquire(int64 m, int64 blocks = 0, int64 volume = 0)
{
    if (m == 0) return std::make_pair(blocks, volume);
    int64 lo = 1, hi = 1e5 + 5, mid;
    while (lo < hi - 1) {
        mid = (lo + hi) >> 1;
        if (mid * mid * mid <= m) lo = mid; else hi = mid;
    }
    return std::max(
        inquire(m - lo * lo * lo, blocks + 1, volume + lo * lo * lo),
        inquire(lo * lo * lo - (lo - 1) * (lo - 1) * (lo - 1) - 1, blocks + 1, volume + (lo - 1) * (lo - 1) * (lo - 1))
    );
}

int main()
{
    int64 m;
    scanf("%I64d", &m);
    std::pair<int64, int64> ans = inquire(m);
    printf("%I64d %I64d\n", ans.first, ans.second);
    return 0;
}