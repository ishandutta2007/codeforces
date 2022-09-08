#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;

struct tree {
    int mx[4 * max_n], f[4 * max_n];

    void push(int v) {
        if (f[v]) {
            f[2 * v] += f[v];
            f[2 * v + 1] += f[v];
            mx[2 * v] += f[v];
            mx[2 * v + 1] += f[v];
            f[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, int add) {
        if (tl == l && tr == r) {
            f[v] += add;
            mx[v] += add;
            return;
        }
        push(v);
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            update(2 * v, tl, mid, l, r, add);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r, add);
        } else {
            update(2 * v, tl, mid, l, mid, add);
            update(2 * v + 1, mid + 1, tr, mid + 1, r, add);
        }
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }

    int get_right(int v, int l, int r) {
        if (l == r) {
            return l;
        }
        push(v);
        int mid = (l + r) / 2;
        if (mx[2 * v + 1] > 0) {
            return get_right(2 * v + 1, mid + 1, r);
        }
        return get_right(2 * v, l, mid);
    }
};

int n, m, a[max_n], b[max_n];
tree t;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        t.update(1, 0, max_n - 1, 0, a[i], 1);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &b[i]);
        t.update(1, 0, max_n - 1, 0, b[i], -1);
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        int tp, pos, x;
        scanf("%d%d%d", &tp, &pos, &x);
        --pos;
        if (tp == 1) {
            t.update(1, 0, max_n - 1, 0, a[pos], -1);
            a[pos] = x;
            t.update(1, 0, max_n - 1, 0, a[pos], 1);
        } else {
            t.update(1, 0, max_n - 1, 0, b[pos], 1);
            b[pos] = x;
            t.update(1, 0, max_n - 1, 0, b[pos], -1);
        }
        if (t.mx[1] <= 0) {
            puts("-1");
        } else {
            printf("%d\n", t.get_right(1, 0, max_n - 1));
        }
    }
    return 0;
}