#include <cstdio>
typedef long long int64;
static const int MAXM = 2e5 + 7;
#define LL_FMT "%I64d"
template <typename T> inline T max(const T a, const T b) { return a > b ? a : b; }

int m, k;
int64 n, x, s;
int64 a[MAXM], b[MAXM];
int c[MAXM], max_c[MAXM]; int64 d[MAXM];

int main()
{
    scanf(LL_FMT "%d%d" LL_FMT LL_FMT, &n, &m, &k, &x, &s);
    for (int i = 0; i < m; ++i) scanf(LL_FMT, &a[i]);
    for (int i = 0; i < m; ++i) scanf(LL_FMT, &b[i]);
    for (int i = 0; i < k; ++i) scanf("%d", &c[i]);
    for (int i = 0; i < k; ++i) scanf(LL_FMT, &d[i]);
    max_c[0] = c[0];
    for (int i = 1; i < k; ++i) max_c[i] = max(max_c[i - 1], c[i]);

    int64 ans = x * n, cur;
    for (int i = 0; i < m; ++i) if (b[i] <= s) {
        // Use the i-th spell of first type
        int lo = -1, hi = k, mid;
        while (lo < hi - 1) {
            mid = (lo + hi) >> 1;
            if (b[i] + d[mid] <= s) lo = mid; else hi = mid;
        }
        cur = a[i] * n;
        if (lo != -1) cur -= a[i] * max_c[lo];
        if (ans > cur) ans = cur;
    }
    // Only one spell of second type
    for (int i = 0; i < k; ++i) if (d[i] <= s) {
        cur = x * (n - c[i]);
        if (ans > cur) ans = cur;
    }

    printf(LL_FMT "\n", ans);
    return 0;
}