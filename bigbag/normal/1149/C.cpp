#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

struct node {
    int mn, mx, pr, suf, ans;

    node() {
    }

    node(int x): mn(x), mx(x), pr(0), suf(0), ans(0) {
    }
};

node merge(const node &a, const node &b) {
    node res;
    res.mn = min(a.mn, b.mn);
    res.mx = max(a.mx, b.mx);
    res.pr = max({a.pr, b.pr, b.mx - 2 * a.mn});
    res.suf = max({a.suf, b.suf, a.mx - 2 * b.mn});
    res.ans = max({a.ans, b.ans, a.suf + b.mx, a.mx + b.pr});
    return res;
}

struct tree {
    int f[4 * max_n];
    node a[4 * max_n];

    void push(int v) {
        if (f[v]) {
            for (int to = 2 * v; to <= 2 * v + 1; ++to) {
                a[to].mn += f[v];
                a[to].mx += f[v];
                a[to].pr -= f[v];
                a[to].suf -= f[v];
                f[to] += f[v];
            }
            f[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, int x) {
        if (tl == l && tr == r) {
            a[v].mn += x;
            a[v].mx += x;
            a[v].pr -= x;
            a[v].suf -= x;
            f[v] += x;
            return;
        }
        push(v);
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            update(2 * v, tl, mid, l, r, x);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r, x);
        } else {
            update(2 * v, tl, mid, l, mid, x);
            update(2 * v + 1, mid + 1, tr, mid + 1, r, x);
        }
        a[v] = merge(a[2 * v], a[2 * v + 1]);
    }
};

int n, q;
char a[max_n];
tree t;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &q);
    scanf("%s", a);
    int len = 2 * (n - 1);
    for (int i = 0; i < len; ++i) {
        if (a[i] == '(') {
            t.update(1, 0, len - 1, i, len - 1, 1);
        } else {
            t.update(1, 0, len - 1, i, len - 1, -1);
        }
    }
    printf("%d\n", t.a[1].ans);
    while (q--) {
        int pos1, pos2;
        scanf("%d%d", &pos1, &pos2);
        --pos1;
        --pos2;
        if (a[pos1] != a[pos2]) {
            if (a[pos1] == '(') {
                t.update(1, 0, len - 1, pos1, len - 1, -2);
                t.update(1, 0, len - 1, pos2, len - 1, 2);
            } else {
                t.update(1, 0, len - 1, pos1, len - 1, 2);
                t.update(1, 0, len - 1, pos2, len - 1, -2);
            }
            swap(a[pos1], a[pos2]);
        }
        printf("%d\n", t.a[1].ans);
    }
    return 0;
}