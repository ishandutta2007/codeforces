#include <cstdio>
#include <utility>
static const int MAXN = 3e5 + 4;
static const int LOGN = 23;
static const int MAXQ = 3e5 + 3;

int n, q, a[MAXN];

namespace psgt {
// Single value modification, range k-th query

static const int MAXN = ::MAXN * (::LOGN + 2);

int sz = 0;
struct node { int l, r, lch, rch; int sum; } t[MAXN];

inline int build(int L, int R) {
    int idx = sz++;
    t[idx].l = L, t[idx].r = R;
    t[idx].sum = 0;
    if (L == R) {
        t[idx].lch = t[idx].rch = -1;
    } else {
        int M = (L + R) >> 1;
        t[idx].lch = build(L, M);
        t[idx].rch = build(M + 1, R);
    }
    return idx;
}

inline int copy(int idx) {
    t[sz] = t[idx];
    return sz++;
}

int QP, QV;

inline int modify(int idx) {
    idx = copy(idx);
    t[idx].sum += QV;
    if (t[idx].lch != -1) {
        if (QP <= t[t[idx].lch].r) t[idx].lch = modify(t[idx].lch);
        else t[idx].rch = modify(t[idx].rch);
    }
    return idx;
}
inline int modify(int root, int P, int V) { QP = P, QV = V; return modify(root); }

inline std::pair<int, int> query_kth(int lrt, int rrt, int k) {
    while (t[lrt].lch != -1) {
        int lsz = t[t[rrt].lch].sum - t[t[lrt].lch].sum;
        if (lsz > k) {
            lrt = t[lrt].lch;
            rrt = t[rrt].lch;
        } else {
            lrt = t[lrt].rch;
            rrt = t[rrt].rch;
            k -= lsz;
        }
    }
    return std::make_pair(t[lrt].l, t[rrt].sum - t[lrt].sum);
}

}

int rt[MAXN];

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]), --a[i];

    rt[0] = psgt::build(0, n - 1);
    for (int i = 0; i < n; ++i) {
        rt[i + 1] = psgt::modify(rt[i], a[i], +1);
    }

    int l, r, k;
    for (int i = 0; i < q; ++i) {
        scanf("%d%d%d", &l, &r, &k); --l;
        int ans = -1;
        int step = (r - l) / k + 1;
        for (int p = 0; p < r - l; p += step) {
            std::pair<int, int> result = psgt::query_kth(rt[l], rt[r], p);
            if (result.second > (r - l) / k) { ans = result.first + 1; break; }
        }
        printf("%d\n", ans);
    }

    return 0;
}