#include <cstdio>
static const int INF = 0x7fffffff;
static const int MAXN = 1e5 + 4;
static const int MAXX = 1e6 + 3;

static const int OP_POP = 0;
static const int OP_PUSH = 1;
int n, p[MAXN], t[MAXN], x[MAXN], idx_with_p[MAXN];
template <typename T> inline T max(const T a, const T b) { return a > b ? a : b; }

namespace sgt_ops {

static const int MAXN = 262144 + 10;
static const int LOGN = 20;

int n;
int val[MAXN], tag[MAXN];

inline void build(int _n) {
    n = 1 << (8 * sizeof(int) - __builtin_clz(_n));
    for (int i = 0; i < n * 2; ++i) val[i] = 0;
}

inline void push(int idx) {
    if (idx >= n || tag[idx] == 0) return;
    val[idx * 2] += tag[idx]; tag[idx * 2] += tag[idx];
    val[idx * 2 + 1] += tag[idx]; tag[idx * 2 + 1] += tag[idx];
    tag[idx] = 0;
}
inline void update(int idx) { val[idx] = max(val[idx * 2], val[idx * 2 + 1]) + tag[idx]; }

inline void add(int l, int r, int inc) {
    l += n, r += n;
    int _l = l, _r = r;
    ++r;
    for (; l < r; l >>= 1, r >>= 1) {
        if (l & 1) val[l] += inc, tag[l++] += inc;
        if (r & 1) val[--r] += inc, tag[r] += inc;
    }
    for (_l >>= 1; _l >= 1; _l >>= 1) update(_l);
    for (_r >>= 1; _r >= 1; _r >>= 1) update(_r);
}

inline int query(int l, int r) {
    if (l > r) return -INF;
    l += n, r += n;
    for (int i = LOGN - 1; i >= 0; --i) {
        if ((l >> i) >= 1) push(l >> i);
        if ((r >> i) >= 1) push(r >> i);
    }
    ++r;
    int ans = -INF;
    for (; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ans = max(ans, val[l++]);
        if (r & 1) ans = max(ans, val[--r]);
    }
    return ans;
}

}

int main()
{
    scanf("%d", &n);
    sgt_ops::build(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &p[i], &t[i]); p[i] = n - p[i];
        idx_with_p[p[i]] = i;
        if (t[i] == OP_PUSH) scanf("%d", &x[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (t[i] == OP_PUSH) {
            sgt_ops::add(p[i], n - 1, +1);
        } else {    // t[i] == OP_POP
            sgt_ops::add(p[i], n - 1, -1);
        }
        int lo = -1, hi = n, mid;
        while (lo < hi - 1) {
            mid = (lo + hi) >> 1;
            if (sgt_ops::query(0, mid) > 0) hi = mid; else lo = mid;
        }
        printf("%d\n", hi == n ? -1 : x[idx_with_p[hi]]);
    }
    return 0;
}