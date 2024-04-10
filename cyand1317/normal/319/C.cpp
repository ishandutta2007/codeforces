#include <cstdio>
#include <algorithm>
#include <utility>
typedef long long int64;
static const int MAXN = 1e5 + 4;
static const int64 INF = 1LL << 62;

int n, a[MAXN], b[MAXN];

int64 f[MAXN];

struct hull {
    int sz;
    typedef std::pair<int64, int64> point;
#define x  first
#define y  second
    point p[MAXN];

    hull() : sz(0) { }
    inline double cross(point &o, point &p, point &q) {
        return (double)(p.x - o.x) * (q.y - o.y) - (double)(p.y - o.y) * (q.x - o.x);
    }
    inline void insert(int64 px, int64 py) {
        point r = point(px, py);
        while (sz >= 2 && cross(p[sz - 2], p[sz - 1], r) >= 1e-9) --sz;
        p[sz++] = r;
    }
    inline int64 query(int64 slope) {
        int lo = 0, hi = sz, mid;
        while (lo < hi - 1) {
            mid = (lo + hi) >> 1;
            if ((double)p[mid].y - (double)p[mid].x * slope <= (double)p[mid - 1].y - (double)p[mid - 1].x * slope)
                lo = mid;
            else hi = mid;
        }
        return p[lo].y - p[lo].x * slope;
    }
#undef x
#undef y
} h;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &b[i]);

    f[0] = 0;
    h.insert(b[0], 0);
    for (int i = 1; i < n; ++i) {
        f[i] = h.query(-a[i]);
        h.insert(b[i], f[i]);
    }
    printf("%I64d\n", f[n - 1]);

    return 0;
}