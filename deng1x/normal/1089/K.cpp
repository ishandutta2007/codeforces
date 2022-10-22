#include <bits/stdc++.h>

#define MAXN (1000010)
#define ll long long

int q;
struct node {
    ll e, f;
    node():e(-1), f(0){}
    node(ll e, ll f):e(e), f(f){}
} seg[MAXN << 2];
int a[MAXN];

node merge(int l, int m, node a, node b) {
    node ret;
    if (a.e == -1 && b.e == -1) {
        ret = {-1, 0};
        return ret;
    }
    if (a.e == -1) {
        ret = {b.e, b.f + m - l + 1};
        return ret;
    }
    if (b.e == -1) {
        ret = {a.e, a.f};
        return ret;
    }
    if (m + 1 <= a.e) {
        ll t = a.e - m - 1;
        ret = {
                b.e + std::max(0ll, t - b.f),
                a.f + std::max(0ll, b.f - t)
        };
    } else {
        ret = {
                b.e,
                a.f + b.f + m + 1 - a.e
        };
    }
    return ret;
}

void modify(int u, int l, int r, int loc, int c) {
    if (l == r) {
        if (c == -1) seg[u] = {-1, 0};
        else seg[u] = {l + c, 0};
        return;
    }
    int m = (l + r) >> 1, ls = u << 1, rs = ls | 1;
    if (loc <= m) modify(ls, l, m, loc, c);
    else modify(rs, m + 1, r, loc, c);
    seg[u] = merge(l, m, seg[ls], seg[rs]);
}

node query(int u, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return seg[u];
    }
    int m = (l + r) >> 1, ls = u << 1, rs = ls | 1;
    node a, b;
    if (!(m < ql)) a = query(ls, l, m, ql, qr);
    if (!(qr < m + 1)) b = query(rs, m + 1, r, ql, qr);
    if (b.e == -1) return a;
    return merge(l, m, a, b);
}

int main() {
    scanf("%d", &q);
    for (int i = 1; i <= q; ++i) {
        static char s[10];
        scanf("%s", s);
        if (s[0] == '+') {
            int t, d;
            scanf("%d%d", &t, &d);
            modify(1, 1, MAXN - 1, t, d);
            a[i] = t;
        } else if (s[0] == '-') {
            int j;
            scanf("%d", &j);
            modify(1, 1, MAXN - 1, a[j], -1);
        } else {
            int t;
            scanf("%d", &t);
            node now = query(1, 1, MAXN - 1, 1, t);
            printf("%lld\n", std::max(0ll, now.e - t));
        }
    }
    return 0;
}