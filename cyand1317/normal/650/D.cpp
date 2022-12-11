#include <cstdio>
#include <algorithm>
#include <utility>
static const int INF = 0x7fffffff;
static const int MAXN = 400006;
static const int MAXM = 400006;

int n, m;
int h[MAXN * 2];
int a[MAXM], b[MAXM];

int p[MAXN], q[MAXN];
int lis_l[MAXN], lis_r[MAXN];
int max_l[MAXM], max_r[MAXM];
bool on_global_lis[MAXN] = { false };
int lis_l_cnt[MAXN] = { 0 };

template <typename T> inline void discretize(int n, T *a) {
    static std::pair<T, int> p[MAXN * 2];
    for (int i = 0; i < n; ++i) p[i] = std::make_pair(a[i], i);
    std::sort(p, p + n);
    int rk = 0;
    for (int i = 0; i < n; ++i) {
        if (i && p[i].first != p[i - 1].first) ++rk;
        a[p[i].second] = rk;
    }
}

inline void calc_lis(int n, int *a, int *f) {
    static int awf[MAXN * 2];
    int lis = 1, lo, hi, mid;
    f[0] = 1;
    awf[0] = -1;
    awf[1] = a[0];
    for (int i = 1; i < n; ++i)
        if (a[i] > awf[lis]) {
            f[i] = ++lis;
            awf[lis] = a[i];
        } else {
            lo = 0, hi = lis;
            while (lo < hi - 1) {
                mid = (lo + hi) >> 1;
                if (a[i] > awf[mid]) lo = mid; else hi = mid;
            }
            f[i] = lo + 1;
            awf[lo + 1] = a[i];
        }
}

inline bool h_cmp(const int lhs, const int rhs) { return h[lhs] == h[rhs] ? lhs > rhs : h[lhs] < h[rhs]; }
inline bool b_cmp(const int lhs, const int rhs) { return b[lhs] < b[rhs]; }

namespace sgt {
static const int MAXN = ::MAXN * 2;

int sz = 0;
int l[MAXN], r[MAXN], lch[MAXN], rch[MAXN], val[MAXN];

int build(int L, int R) {
    int idx = sz++;
    l[idx] = L, r[idx] = R; val[idx] = 0;
    if (L == R) lch[idx] = rch[idx] = -1;
    else {
        int M = (L + R) >> 1;
        lch[idx] = build(L, M);
        rch[idx] = build(M + 1, R);
    }
    return idx;
}

inline void refill(int V = 0) { std::fill(val, val + sz, V); }

int ql, qr, qv;
inline int query(int idx) {
    if (l[idx] >= ql && r[idx] <= qr) return val[idx];
    int ans = -INF;
    if (r[lch[idx]] >= ql) ans = std::max(ans, query(lch[idx]));
    if (l[rch[idx]] <= qr) ans = std::max(ans, query(rch[idx]));
    return ans;
}
inline int query(int L, int R) { if (L > R) return 0; ql = L, qr = R; return query(0); }
inline void modify(int idx) {
    if (lch[idx] == -1) { val[idx] = std::max(val[idx], qv); return; }
    if (r[lch[idx]] >= ql) modify(lch[idx]); else modify(rch[idx]);
    val[idx] = std::max(val[lch[idx]], val[rch[idx]]);
}
inline void modify(int P, int V) { ql = P, qv = V; modify(0); }

}

void update_seq_max(int *lis, int *mx, bool is_reversed)
{
    sgt::refill();
    for (int i = 0, j = 0; i < m; ++i) {
        while (j < n && (is_reversed ? h[p[j]] > b[q[i]] : h[p[j]] < b[q[i]])) {
            sgt::modify(p[j], lis[p[j]]);
            ++j;
        }
        mx[q[i]] = is_reversed ? sgt::query(a[q[i]] + 1, n - 1) : sgt::query(0, a[q[i]] - 1);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &h[i]);
    for (int i = 0; i < m; ++i) scanf("%d%d", &a[i], &b[i]), --a[i];
    for (int i = 0; i < m; ++i) h[i + n] = b[i];
    discretize(n + m, h);
    for (int i = 0; i < m; ++i) b[i] = h[i + n];

    for (int i = 0; i < n; ++i) h[i + n] = n - h[n - 1 - i];
    calc_lis(n, h, lis_l);
    calc_lis(n, h + n, lis_r);
    std::reverse(lis_r, lis_r + n);

    for (int i = 0; i < n; ++i) p[i] = i;
    for (int i = 0; i < m; ++i) q[i] = i;
    std::sort(p, p + n, h_cmp);
    std::sort(q, q + m, b_cmp);
    sgt::build(0, n - 1);
    update_seq_max(lis_l, max_l, false);
    std::reverse(p, p + n);
    std::reverse(q, q + m);
    update_seq_max(lis_r, max_r, true);

    int global_lis = 0;
    for (int i = 0; i < n; ++i) global_lis = std::max(global_lis, lis_l[i]);
    sgt::refill(-INF);
    // Array p is already what we want: indices of elements, sorted by heights descending and then indices ascending
    for (int i = 0; i < n; ++i) {
        if (lis_l[p[i]] == global_lis || sgt::query(p[i] + 1, n - 1) == -(lis_l[p[i]] + 1)) {
            on_global_lis[p[i]] = true;
            sgt::modify(p[i], -lis_l[p[i]]);
        }
    }
    for (int i = 0; i < n; ++i) if (on_global_lis[i]) lis_l_cnt[lis_l[i]]++;

    for (int i = 0; i < m; ++i) {
        int lower = global_lis - ((on_global_lis[a[i]] && lis_l_cnt[lis_l[a[i]]] == 1) ? 1 : 0);
        int upper = 1 + max_l[i] + max_r[i];
        printf("%d\n", std::max(lower, upper));
    }

    return 0;
}