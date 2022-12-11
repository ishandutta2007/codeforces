#include <cstdio>
#include <algorithm>
#include <utility>
typedef long long int64;
static const int MAXN = 1e5 + 7;
static const int MAXQ = 2e5 + 7;

int n, q, h[MAXN];
int op[MAXQ], arg2[MAXQ], arg2_r[MAXQ], arg2_ct; int64 arg1[MAXQ];

struct fwk {
    int64 f[MAXQ];
    fwk() { std::fill(f, f + MAXQ, 0); }
    inline void add(int pos, int inc) {
        for (++pos; pos < MAXQ; pos += (pos & -pos)) f[pos] += inc;
    }
    inline int64 sum(int rg) {
        int64 ret = 0; for (++rg; rg > 0; rg -= (rg & -rg)) ret += f[rg]; return ret;
    }
    inline int64 sum(int lf, int rg) { return sum(rg) - sum(lf - 1); }
} f_count, f_sum;

template <typename T> inline int discretize(int n, T *arr, T *real) {
    std::pair<T, int> p[MAXQ];
    for (int i = 0; i < n; ++i) p[i] = std::make_pair(arr[i], i);
    std::sort(p, p + n);
    int rk = 0; real[0] = p[0].first;
    for (int i = 0; i < n; ++i) {
        if (i && p[i].first != p[i - 1].first) real[++rk] = p[i].first;
        arr[p[i].second] = rk;
    }
    return rk + 1;
}

inline void change(int idx, int val) {
    f_count.add(h[idx], -1);
    f_sum.add(h[idx], -arg2_r[h[idx]]);
    h[idx] = val;
    f_count.add(h[idx], +1);
    f_sum.add(h[idx], +arg2_r[h[idx]]);
}

inline double query(int64 tot) {
    int lo = 0, hi = arg2_ct, mid;
    int64 tubes, hg, empty;
    while (lo < hi - 1) {
        mid = (lo + hi) >> 1;
        tubes = f_count.sum(mid);
        hg = f_sum.sum(mid);
        empty = (int64)arg2_r[mid] * tubes - hg;
        if (empty >= tot) hi = mid; else lo = mid;
    }
    tubes = f_count.sum(lo);
    hg = f_sum.sum(lo);
    return (double)(hg + tot) / tubes;
}

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) {
        op[i] = 1; arg1[i] = i + 1; scanf("%d", &arg2[i]);
    }
    for (int i = n; i < n + q; ++i) {
        scanf("%d%I64d", &op[i], &arg1[i]);
        if (op[i] == 1) scanf("%d", &arg2[i]); else arg2[i] = -1;
    }
    arg2_ct = discretize(q += n, arg2, arg2_r);

    for (int i = 0; i < n; ++i) h[i] = 0;
    f_count.add(0, n);
    f_sum.add(0, -n);
    for (int i = 0; i < q; ++i) {
        if (op[i] == 1) change(arg1[i] - 1, arg2[i]);
        else printf("%.6lf\n", query(arg1[i]));
    }

    return 0;
}