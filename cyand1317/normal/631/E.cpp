#include <cstdio>
#include <algorithm>
typedef long long int64;
static const int MAXN = 200004;
static const int64 INF = 1LL << 61;

int n, a[MAXN];
int64 s[MAXN];

namespace env {

int sz;
int64 x[MAXN], y[MAXN];

inline void clear() { sz = 0; }

inline int64 cross(int64 x1, int64 y1, int64 x2, int64 y2, int64 x3, int64 y3) {
    return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}

inline void add(int64 nx, int64 ny) {
    while (sz > 1 && cross(x[sz - 2], y[sz - 2], x[sz - 1], y[sz - 1], nx, ny) >= 0) --sz;
    x[sz] = nx, y[sz] = ny; ++sz;
    //for (int i = 0; i < sz; ++i) printf("(%lld,%lld)%c", x[i], y[i], i == sz - 1 ? '\n' : ' ');
}

inline int64 query(int64 slope) {
    if (sz == 1) return x[0] * slope + y[0];
    int lo = -1, hi = sz - 1, mid;
    while (lo < hi - 1) {
        mid = (lo + hi) >> 1;
        if (x[mid] * slope + y[mid] <= x[mid + 1] * slope + y[mid + 1]) lo = mid;
        else hi = mid;
    }
    return x[hi] * slope + y[hi];
    /*int64 ans = -INF;
    for (int i = 0; i < sz; ++i) ans = std::max(ans, x[i] * slope + y[i]);
    return ans;*/
}

}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);

    int64 sum = 0, delta = 0;
    s[0] = 0;
    for (int i = 1; i <= n; ++i) {
        sum += (int64)a[i] * i;
        s[i] = s[i - 1] + a[i];
    }

    env::clear();
    for (int i = 1; i <= n; ++i) {
        env::add(i, -s[i - 1]);
        delta = std::max(delta, env::query(a[i]) + s[i - 1] - (int64)a[i] * i);
    }

    env::clear();
    for (int i = n; i >= 1; --i) {
        env::add(-i, -s[i]);
        delta = std::max(delta, env::query(-a[i]) + s[i] - (int64)a[i] * i);
    }

    printf("%I64d\n", sum + delta);
    return 0;
}