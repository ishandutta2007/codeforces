// Better approaches? OuO
#include <cstdio>
#include <algorithm>
#include <utility>
typedef long long int64;
static const int MAXN = 1e5 + 4;

int n;
int op[MAXN];
int64 x[MAXN][2];
int64 mapped[MAXN * 2];

template <typename T> inline int discretize(int n, T *arr, T *mapped)
{
    static std::pair<T, int> p[MAXN * 2];
    for (int i = 0; i < n; ++i) p[i] = std::make_pair(arr[i], i);
    std::sort(p, p + n);
    int rk = -1;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || p[i].first != p[i - 1].first) mapped[++rk] = p[i].first;
        arr[p[i].second] = rk;
    }
    return rk + 1;
}

namespace sgt {
// Range 0/1-fill, range inversion, mex query

static const int MAXN = ::MAXN * 4;
int sz;
enum tag_t { TAG_NONE = 0, TAG_ZEROFILL, TAG_ONEFILL, TAG_INVERT };
struct node { int l, r, lch, rch; int sum; tag_t tag; } t[MAXN];

inline void apply(int idx, tag_t val) {
    if (val == TAG_ZEROFILL) {
        t[idx].sum = 0;
        t[idx].tag = val;
    } else if (val == TAG_ONEFILL) {
        t[idx].sum = (t[idx].r - t[idx].l + 1);
        t[idx].tag = val;
    } else if (val == TAG_INVERT) {
        t[idx].sum = (t[idx].r - t[idx].l + 1) - t[idx].sum;
        switch (t[idx].tag) {
            case TAG_NONE: t[idx].tag = TAG_INVERT; break;
            case TAG_ZEROFILL: t[idx].tag = TAG_ONEFILL; break;
            case TAG_ONEFILL: t[idx].tag = TAG_ZEROFILL; break;
            case TAG_INVERT: t[idx].tag = TAG_NONE; break;
            default: puts("> <");
        }
    }
}
inline void push(int idx) {
    if (t[idx].tag == TAG_NONE || t[idx].lch == -1) return;
    apply(t[idx].lch, t[idx].tag);
    apply(t[idx].rch, t[idx].tag);
    t[idx].tag = TAG_NONE;
}
inline void update(int idx) {
    if (t[idx].lch == -1) return;
    push(idx);
    t[idx].sum = t[t[idx].lch].sum + t[t[idx].rch].sum;
}

inline int build(int L, int R) {
    int idx = sz++;
    t[idx].l = L, t[idx].r = R;
    t[idx].sum = 0, t[idx].tag = TAG_NONE;
    if (L == R) {
        t[idx].lch = t[idx].rch = -1;
    } else {
        int M = (L + R) >> 1;
        t[idx].lch = build(L, M);
        t[idx].rch = build(M + 1, R);
    }
    return idx;
}
inline void rebuild(int N) { sz = 0; build(0, N - 1); }

int QL, QR;
tag_t QV;

inline void modify(int idx) {
    push(idx);
    if (t[idx].l >= QL && t[idx].r <= QR) { apply(idx, QV); return; }
    if (t[t[idx].lch].r >= QL) modify(t[idx].lch);
    if (t[t[idx].rch].l <= QR) modify(t[idx].rch);
    update(idx);
}
inline void modify(int L, int R, tag_t V) { QL = L, QR = R, QV = V; modify(0); }

inline int query_mex() {
    int idx = 0;
    while (t[idx].lch != -1) {
        push(idx);
        if (t[t[idx].lch].sum != t[t[idx].lch].r - t[t[idx].lch].l + 1) idx = t[idx].lch;
        else idx = t[idx].rch;
    }
    return t[idx].l;
}

}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d%I64d%I64d", &op[i], &x[i][0], &x[i][1]), ++x[i][1];

    x[n][0] = 1;    // T^T
    int elmts = discretize<int64>(n * 2 + 1, &x[0][0], mapped);
    sgt::rebuild(elmts);

    for (int i = 0; i < n; ++i) {
        --x[i][1];
        switch (op[i]) {
            case 1: sgt::modify(x[i][0], x[i][1], sgt::TAG_ONEFILL); break;
            case 2: sgt::modify(x[i][0], x[i][1], sgt::TAG_ZEROFILL); break;
            case 3: sgt::modify(x[i][0], x[i][1], sgt::TAG_INVERT); break;
            default: puts("QuQ");
        }
        printf("%I64d\n", mapped[sgt::query_mex()]);
    }

    return 0;
}