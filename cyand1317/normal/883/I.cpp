#include <cstdio>
#include <algorithm>
typedef long long int64;
static const int64 INF64 = 1LL << 61;
static const int MAXN = 3e5 + 4;
static const int MAXV = 1e9 + 9;

static int n, k;
static int a[MAXN];

namespace sgt {
// Single value modification, range maximum query
// Can be replaced with BIT > <

const int MAXN = ::MAXN * 2;
int sz;
struct node { int l, r, lch, rch; int64 max; } t[MAXN];

inline int build(int L, int R) {
    int idx = sz++;
    t[idx].l = L; t[idx].r = R;
    t[idx].max = -INF64;
    if (L == R) {
        t[idx].lch = t[idx].rch = -1;
    } else {
        int M = (L + R) >> 1;
        t[idx].lch = build(L, M);
        t[idx].rch = build(M + 1, R);
    }
    return idx;
}
inline void rebuild(int L, int R) { sz = 0; build(L, R); }

int QL, QR, QV;

inline void modify(int idx) {
    if (t[idx].lch == -1) { t[idx].max = QV; return; }
    if (t[t[idx].lch].r >= QL) modify(t[idx].lch);
    else modify(t[idx].rch);
    t[idx].max = std::max(t[t[idx].lch].max, t[t[idx].rch].max);
}
inline void modify(int P, int V) { QL = P, QV = V; modify(0); }

inline int64 query(int idx) {
    if (t[idx].l >= QL && t[idx].r <= QR) return t[idx].max;
    int64 ans = -INF64;
    if (t[t[idx].lch].r >= QL) ans = std::max(ans, query(t[idx].lch));
    if (t[t[idx].rch].l <= QR) ans = std::max(ans, query(t[idx].rch));
    return ans;
}
inline int64 query(int L, int R) { QL = L, QR = R; return query(0); }

}

inline bool check(int gap)
{
    sgt::rebuild(-1, n - 1);
    sgt::modify(-1, 1);
    for (int i = k - 1; i < n; ++i) {
        int p = std::lower_bound(a, a + i + 1, a[i] - gap) - &a[0];
        if (p - 1 <= i - k && sgt::query(p - 1, i - k) > 0) {
            sgt::modify(i, 1);
        } else {
            sgt::modify(i, 0);
        }
    }
    return sgt::query(n - 1, n - 1) > 0;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    std::sort(a, a + n);
    a[n] = 0;

    int lo = -1, hi = MAXV, mid;
    while (lo < hi - 1) {
        mid = (lo + hi) >> 1;
        if (check(mid)) hi = mid; else lo = mid;
    }

    printf("%d\n", hi);

    return 0;
}