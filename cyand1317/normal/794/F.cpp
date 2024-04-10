#include <cstdio>
#include <algorithm>
typedef long long int64;
static const int MAXN = 1e5 + 4;

int n, m, a[MAXN];

namespace sgt {

static const int MAXN = ::MAXN * 2;
int sz;
struct node { int l, r, lch, rch; int64 sum[10]; int tag[10]; } t[MAXN];

inline void push(int idx) {
    static int t_lch[10], t_rch[10];
    static int64 n_sum[10];

    if (t[idx].lch != -1) {
        for (int i = 0; i <= 9; ++i) {
            t_lch[i] = t[idx].tag[t[t[idx].lch].tag[i]];
            t_rch[i] = t[idx].tag[t[t[idx].rch].tag[i]];
        }
        for (int i = 0; i <= 9; ++i) {
            t[t[idx].lch].tag[i] = t_lch[i];
            t[t[idx].rch].tag[i] = t_rch[i];
        }
    }
    std::fill(n_sum, n_sum + 10, 0);
    for (int i = 0; i <= 9; ++i) n_sum[t[idx].tag[i]] += t[idx].sum[i];
    for (int i = 0; i <= 9; ++i) t[idx].sum[i] = n_sum[i], t[idx].tag[i] = i;
}
inline void update(int idx) {
    if (t[idx].lch == -1) return;
    push(t[idx].lch); push(t[idx].rch);
    for (int i = 0; i <= 9; ++i)
        t[idx].sum[i] = t[t[idx].lch].sum[i] + t[t[idx].rch].sum[i];
}

inline int build(int L, int R) {
    int idx = sz++;
    t[idx].l = L, t[idx].r = R;
    for (int i = 0; i <= 9; ++i) t[idx].tag[i] = i;
    if (L == R) {
        t[idx].lch = t[idx].rch = -1;
        std::fill(t[idx].sum, t[idx].sum + 10, 0);
        for (int v = ::a[L], mul = 1; v > 0; v /= 10, mul *= 10)
            t[idx].sum[v % 10] += mul;
    } else {
        int M = (L + R) >> 1;
        t[idx].lch = build(L, M);
        t[idx].rch = build(M + 1, R);
        update(idx);
    }
    return idx;
}
inline void rebuild(int L, int R) { sz = 0; build(L, R); }

int QL, QR, QF, QT;

inline void modify(int idx) {
    push(idx);
    if (t[idx].l >= QL && t[idx].r <= QR) {
        t[idx].tag[QF] = QT; push(idx); return;
    }
    if (t[t[idx].lch].r >= QL) modify(t[idx].lch);
    if (t[t[idx].rch].l <= QR) modify(t[idx].rch);
    update(idx);
}
inline void modify(int L, int R, int F, int T) { QL = L, QR = R, QF = F, QT = T; modify(0); }

inline int64 query_sum(int idx) {
    push(idx);
    int64 ans = 0;
    if (t[idx].l >= QL && t[idx].r <= QR) {
        for (int i = 0; i <= 9; ++i) ans += t[idx].sum[i] * i;
        return ans;
    }
    if (t[t[idx].lch].r >= QL) ans += query_sum(t[idx].lch);
    if (t[t[idx].rch].l <= QR) ans += query_sum(t[idx].rch);
    update(idx);
    return ans;
}
inline int64 query_sum(int L, int R) { QL = L, QR = R; return query_sum(0); }

void print() {
    for (int i = 0; i < sz; ++i) {
        printf("[%d] | [%d, %d] Sum = [", i, t[i].l, t[i].r);
        for (int j = 0; j <= 9; ++j) printf("%lld%c", t[i].sum[j], j == 9 ? ']' : ' ');
        printf(" Tag = [");
        for (int j = 0; j <= 9; ++j) printf("%d%c", t[i].tag[j], j == 9 ? ']' : ' ');
        putchar('\n');
    }
}

}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sgt::rebuild(0, n - 1);

    int op, l, r, x, y;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &op, &l, &r); --l, --r;
        if (op == 1) {
            scanf("%d%d", &x, &y);
            sgt::modify(l, r, x, y);
        } else if (op == 2) {
            printf("%I64d\n", sgt::query_sum(l, r));
        } else puts("> <");
        //sgt::print();
    }

    return 0;
}