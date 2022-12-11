#include <cstdio>
#include <cmath>
typedef long long int64;
template <typename T> inline T min(const T a, const T b) { return a < b ? a : b; }

int n, m, k;

inline bool check(int frodo)
{
    int left = min(k - 1, frodo - 1),
        right = min(n - k, frodo - 1);
    int64 tot = (int64)frodo * (1 + left + right) - ((int64)left * (left + 1) / 2 + (int64)right * (right + 1) / 2);
    return tot <= m;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    m -= n;
    int lo = 0, hi = m + 1, mid;
    while (lo < hi - 1) {
        mid = (lo + hi) >> 1;
        if (check(mid)) lo = mid; else hi = mid;
    }
    printf("%d\n", lo + 1);
    return 0;
}