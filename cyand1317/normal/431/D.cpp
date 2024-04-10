#include <cstdio>
typedef unsigned long long uint64;
static const uint64 INF64U = 1ULL << 62;

uint64 binom[62][62];
inline void count_popcount_init() {
    binom[0][0] = 1;
    for (int i = 0; i < 62; ++i) {
        binom[i][0] = 1;
        for (int j = 1; j <= i; ++j) binom[i][j] = binom[i - 1][j] + binom[i - 1][j - 1];
    }
}
inline uint64 count_popcount_with(uint64 upbound, int k) {
    ++upbound;
    uint64 ans = 0;
    int c = 0;
    for (int i = 62; i >= 0; --i) if (upbound & (1ULL << i)) {
        ans += binom[i][k - c];
        if (++c > k) break;
    }
    return ans;
}

uint64 m; int k;

int main()
{
    count_popcount_init();

    scanf("%I64u%d", &m, &k);
    uint64 lo = 0, hi = 1e18 + 10, mid;
    while (lo < hi - 1) {
        mid = (lo + hi) >> 1;
        if (count_popcount_with(mid * 2, k) - count_popcount_with(mid, k) >= m) hi = mid; else lo = mid;
    }
    printf("%I64u\n", hi);

    return 0;
}