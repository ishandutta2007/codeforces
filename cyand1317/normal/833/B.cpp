#include <cstdio>
#include <algorithm>
static const int MAXN = 35004;
static const int MAXK = 52;
static const int INF = 0x3fffffff;

int n, k;
int a[MAXN];

class sgt {
// Range increment, range maximum query

protected:

static const int MAXN = ::MAXN * 2;
int sz;
struct node { int l, r, lch, rch, max, tag; } t[MAXN];

inline void apply(int idx, int val) {
    t[idx].max += val;
    t[idx].tag += val;
}

inline void push(int idx) {
    if (t[idx].lch == -1 || t[idx].tag == 0) return;
    apply(t[idx].lch, t[idx].tag);
    apply(t[idx].rch, t[idx].tag);
    t[idx].tag = 0;
}

inline void update(int idx) {
    push(idx);
    t[idx].max = std::max(t[t[idx].lch].max, t[t[idx].rch].max);
}

inline int build(int L, int R) {
    int idx = sz++;
    t[idx].l = L, t[idx].r = R;
    t[idx].max = t[idx].tag = 0;
    if (L == R) {
        t[idx].lch = t[idx].rch = -1;
    } else {
        int M = (L + R) >> 1;
        t[idx].lch = build(L, M);
        t[idx].rch = build(M + 1, R);
    }
    return idx;
}

int QL, QR, QV;

inline int query(int idx) {
    push(idx);
    if (t[idx].l >= QL && t[idx].r <= QR) return t[idx].max;
    int ans = -INF;
    if (t[t[idx].lch].r >= QL) ans = std::max(ans, query(t[idx].lch));
    if (t[t[idx].rch].l <= QR) ans = std::max(ans, query(t[idx].rch));
    return ans;
}

inline void modify(int idx) {
    push(idx);
    if (t[idx].l >= QL && t[idx].r <= QR) { apply(idx, QV); return; }
    if (t[t[idx].lch].r >= QL) modify(t[idx].lch);
    if (t[t[idx].rch].l <= QR) modify(t[idx].rch);
    update(idx);
}

public:

inline void rebuild(int L, int R) { sz = 0; build(L, R); }
inline int query(int L, int R) { QL = L, QR = R; return query(0); }
inline void modify(int L, int R, int Inc) { QL = L, QR = R, QV = Inc; modify(0); }

} f[MAXK];

int last[MAXN] = { 0 };

int main()
{
    //printf("%lu\n", sizeof f / 1048576);

    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), --a[i];

    for (int i = 0; i <= k; ++i) f[i].rebuild(0, n);

    for (int i = 1; i <= n; ++i) {
        // Update segment values
        for (int j = 0; j <= k; ++j)
            f[j].modify(last[a[i]], i - 1, +1);
        last[a[i]] = i;
        // Retrieve maximum values
        for (int j = 1; j <= k; ++j)
            f[j].modify(i, i, f[j - 1].query(0, i - 1));
    }

    int ans = -INF;
    for (int i = 0; i <= k; ++i) ans = std::max(ans, f[i].query(n, n));
    printf("%d\n", ans);

    return 0;
}