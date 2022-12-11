#include <cstdio>
typedef long long int64;
template <typename T> inline T max(const T a, const T b) { return a > b ? a : b; }
template <typename T> inline T max(const T a, const T b, const T c) { return max(max(a, b), c); }
template <typename T> inline T min(const T a, const T b) { return a < b ? a : b; }

int64 b, d, s;

int64 check(int64 b, int64 d, int64 s)
{
    int64 days = max(b, d, s);
    int64 missed_b = days - b;
    int64 missed_d = days - d;
    int64 missed_s = days - s;
    if (missed_b < 0 || missed_d < 0 || missed_s < 0) return (1LL << 62);
    return missed_b + missed_d + missed_s;
}

int main()
{
    scanf("%I64d%I64d%I64d", &b, &d, &s);
    int64 ans = (1LL << 62);
    ans = min(ans, check(b, d, s));
    ans = min(ans, check(b + 1, d + 1, s));
    ans = min(ans, check(b + 1, d, s));
    ans = min(ans, check(b, d + 1, s + 1));
    ans = min(ans, check(b, d, s + 1));
    ans = min(ans, check(b + 1, d + 2, s + 1));
    ans = min(ans, check(b + 1, d, s + 1));
    printf("%I64d\n", ans);
    return 0;
}