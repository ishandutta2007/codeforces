#include <cstdio>
#include <algorithm>
#include <utility>
static const int MAXN = 1e5 + 4;
static const int MAXQ = 1e5 + 4;
static const int INF = 0x7fffffff;

int n, k, b[MAXN];
int q, op[MAXQ], pos[MAXQ][2], x[MAXQ];
int elmts, real[MAXQ * 2];
int rg_min[MAXQ * 2];

namespace sgt {

static const int MAXN = ::MAXQ * 4;
int sz;
int l[MAXN], r[MAXN], lch[MAXN], rch[MAXN], min[MAXN], tag[MAXN];
int *BSEQ;

inline void apply(int idx, int val) { min[idx] = tag[idx] = val; }
inline void push(int idx) {
    if (lch[idx] == -1 || tag[idx] == -1) return;
    apply(lch[idx], tag[idx]);
    apply(rch[idx], tag[idx]);
    tag[idx] = -1;
}
inline void update(int idx) { min[idx] = std::min(min[lch[idx]], min[rch[idx]]); }

inline int build(int L, int R) {
    int idx = sz++;
    l[idx] = L, r[idx] = R; tag[idx] = -1;
    if (L == R) {
        lch[idx] = rch[idx] = -1;
        min[idx] = BSEQ[L];
    } else {
        int M = (L + R) >> 1;
        lch[idx] = build(L, M);
        rch[idx] = build(M + 1, R);
        update(idx);
    }
    return idx;
}
inline void build(int N, int *seq) { sz = 0, BSEQ = seq; build(0, N - 1); }

int QL, QR, QV;

inline void modify(int idx) {
    push(idx);
    if (l[idx] >= QL && r[idx] <= QR) { apply(idx, QV); return; }
    if (r[lch[idx]] >= QL) modify(lch[idx]);
    if (l[rch[idx]] <= QR) modify(rch[idx]);
    update(idx);
}
inline void modify(int L, int R, int V) { QL = L, QR = R, QV = V; modify(0); }

inline int query(int idx) {
    push(idx);
    if (l[idx] >= QL && r[idx] <= QR) return min[idx];
    int ans = INF;
    if (r[lch[idx]] >= QL) ans = std::min(ans, query(lch[idx]));
    if (l[rch[idx]] <= QR) ans = std::min(ans, query(rch[idx]));
    return ans;
}
inline int query(int L, int R) { if (L > R) return INF; QL = L, QR = R; return query(0); }

}

template <typename T> inline int discretize(int n, T *arr, T *mapped)
{
    static std::pair<T, int> p[MAXQ * 2];
    for (int i = 0; i < n; ++i) p[i] = std::make_pair(arr[i], i);
    std::sort(p, p + n);
    int rk = -1;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || p[i].first != p[i - 1].first) mapped[++rk] = p[i].first;
        arr[p[i].second] = rk;
    }
    return rk + 1;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d%d%d", &op[i], &pos[i][0], &pos[i][1]); --pos[i][0];
        if (op[i] == 1) scanf("%d", &x[i]);
    }
    elmts = discretize(q * 2, (int *)pos, real);

    sgt::build(n, b);
    for (int i = 0; i < elmts - 1; ++i) {
        if (real[i + 1] - real[i] >= n)
            rg_min[i] = sgt::query(0, n - 1);
        else if (real[i + 1] % n < real[i] % n)
            rg_min[i] = std::min(sgt::query(0, real[i + 1] % n - 1), sgt::query(real[i] % n, n - 1));
        else
            rg_min[i] = sgt::query(real[i] % n, real[i + 1] % n - 1);
        //printf("[%d, %d)  %d\n", real[i], real[i + 1], rg_min[i]);
    }

    sgt::build(elmts - 1, rg_min);
    for (int i = 0; i < q; ++i) switch (op[i]) {
        case 1:
            sgt::modify(pos[i][0], pos[i][1] - 1, x[i]);
            break;
        case 2:
            printf("%d\n", sgt::query(pos[i][0], pos[i][1] - 1));
            break;
        default: puts("> <"); break;
    }

    return 0;
}