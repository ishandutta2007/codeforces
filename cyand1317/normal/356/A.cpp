#include <cstdio>
static const int MAXN = 3e5 + 4;
static const int MAXM = 3e5 + 3;

int n, m;
int l[MAXM], r[MAXM], x[MAXM];

namespace sgt {

static const int MAXN = ::MAXN * 2;
int sz;
struct node { int l, r, lch, rch, tag; } t[MAXN];

inline void push(int idx) {
    if (t[idx].lch == -1 || t[idx].tag == -1) return;
    t[t[idx].lch].tag = t[idx].tag;
    t[t[idx].rch].tag = t[idx].tag;
    t[idx].tag = -1;
}

inline int build(int L, int R) {
    int idx = sz++;
    t[idx].l = L, t[idx].r = R;
    t[idx].tag = -1;
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
    push(idx);
    if (t[idx].l >= QL && t[idx].r <= QR) { t[idx].tag = QV; return; }
    if (t[t[idx].lch].r >= QL) modify(t[idx].lch);
    if (t[t[idx].rch].l <= QR) modify(t[idx].rch);
}
inline void modify(int L, int R, int V) { if (L > R) return; QL = L, QR = R, QV = V; modify(0); }

inline int get(int pos) {
    int idx = 0;
    while (t[idx].lch != -1) {
        push(idx);
        if (t[t[idx].lch].r >= pos) idx = t[idx].lch; else idx = t[idx].rch;
    }
    return t[idx].tag;
}

}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &l[i], &r[i], &x[i]);
        --l[i], --r[i], --x[i];
    }

    sgt::rebuild(0, n - 1);
    for (int i = m - 1; i >= 0; --i) {
        sgt::modify(l[i], x[i] - 1, x[i]);
        sgt::modify(x[i] + 1, r[i], x[i]);
    }

    for (int i = 0; i < n; ++i)
        printf("%d%c", sgt::get(i) + 1, i == n - 1 ? '\n' : ' ');

    return 0;
}