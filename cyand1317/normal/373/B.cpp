// 
#include <cstdio>
typedef long long int64;
static const int64 INF64 = 4e16 + 2;

int64 w, m, k;

inline int64 cost_upto(int64 x)
{
    int64 ans = 0;
    int64 tens = 1;
    int pows = 0;
    while (tens * 10 <= x) {
        ans += tens * 9 * (pows + 1);
        tens *= 10; ++pows;
    }
    ans += (x - tens + 1) * (pows + 1);
    return ans;
}

int main()
{
    scanf("%I64d%I64d%I64d", &w, &m, &k);

    int64 lo = -1, hi = INF64, mid;
    int64 decrement = cost_upto(m - 1);
    while (lo < hi - 1) {
        mid = (lo + hi) >> 1;
        if (cost_upto(m + mid) - decrement <= w / k) lo = mid; else hi = mid;
    }

    printf("%I64d\n", lo + 1);
    return 0;
}