#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
const int INF = 1e9 + 10;

typedef long long LL;

int tree[2][N];

void upd(int id, int x, int y) {
    for (; x <= N - 10; x += x & -x) tree[id][x] += y;
}

int que(int id, int x) {
    int res = 0;
    for (; x; x -= x & -x) res += tree[id][x];
    return res;
}

struct Tree {
    struct node {
        int l, r, mx, ct, mx1, tag, x; LL sum;
    } T[N << 2];

    void pushup(int rt) {
        T[rt].mx = max(T[rt << 1].mx, T[rt << 1 | 1].mx), T[rt].ct = 0;
        T[rt].mx1 = max(T[rt << 1].mx1, T[rt << 1 | 1].mx1);
        if (T[rt].mx == T[rt << 1].mx) T[rt].ct += T[rt << 1].ct;
        else T[rt].mx1 = max(T[rt].mx1, T[rt << 1].mx);
        if (T[rt].mx == T[rt << 1 | 1].mx) T[rt].ct += T[rt << 1 | 1].ct;
        else T[rt].mx1 = max(T[rt].mx1, T[rt << 1 | 1].mx);
        T[rt].sum = T[rt << 1].sum + T[rt << 1 | 1].sum;
        T[rt].tag = T[rt << 1].tag & T[rt << 1 | 1].tag;
    }

    void operate(int rt, int x) {
        if (T[rt].mx <= x) return;
        T[rt].tag = 1, T[rt].x = x;
        if (T[rt].mx != INF) 
            T[rt].sum -= (LL)T[rt].mx * T[rt].ct;
        T[rt].mx = x, T[rt].sum += (LL)x * T[rt].ct;
    }

    void pushdown(int rt) {
        if (T[rt].x) operate(rt << 1, T[rt].x), operate(rt << 1 | 1, T[rt].x), T[rt].x = 0;
    }

    void build(int rt, int l, int r) {
        T[rt].l = l, T[rt].r = r;
        T[rt].mx = INF, T[rt].ct = r - l + 1;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(rt << 1, l, mid), build(rt << 1 | 1, mid + 1, r);
    }

    void update(int rt, int start, int end, int x) {
        int l = T[rt].l, r = T[rt].r, mid = (l + r) >> 1;
        if (x >= T[rt].mx) return;
        if (start <= l && r <= end && x > T[rt].mx1) 
            return operate(rt, x);
        pushdown(rt);
        if (start <= mid) update(rt << 1, start, end, x);
        if (end > mid) update(rt << 1 | 1, start, end, x);
        pushup(rt);
    }
} T1, T2;

LL query(int rt, int start, int end) {
    if (T1.T[rt].sum == 0 || T2.T[rt].sum == 0) return 0;
    int l = T1.T[rt].l, r = T1.T[rt].r;
    if (start <= l && r <= end && T1.T[rt].tag && T2.T[rt].tag) 
        return T1.T[rt].sum + T2.T[rt].sum;
    T1.pushdown(rt), T2.pushdown(rt);
    int mid = (l + r) >> 1; LL res = 0;
    if (start <= mid) res += query(rt << 1, start, end);
    if (end > mid) res += query(rt << 1 | 1, start, end);
    return res;
}

int main() {
    int q; scanf("%d", &q);
    T1.build(1, 1, N - 10), T2.build(1, 1, N - 10);
    while (q--) {
        int op, l, r, k; scanf("%d%d%d", &op, &l, &r), r--;
        if (op == 1) {
            scanf("%d", &k);
            if (k > 0) T1.update(1, l, r, k);
            else T2.update(1, l, r, -k);
        } else printf("%lld\n", query(1, l, r));
    }
}