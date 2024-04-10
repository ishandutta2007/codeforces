#include <bits/stdc++.h>

using namespace std;

const int max_n = 505555, inf = 1000111222;
const int max_x = 1000111;

pair<int, int> merge(const pair<int, int> &a, const pair<int, int> &b) {
    pair<int, int> res;
    res.first = min(a.first, b.first);
    if (res.first == a.first) {
        res.second += a.second;
    }
    if (res.first == b.first) {
        res.second += b.second;
    }
    return res;
}

struct tree {
    int a[4 * max_x], f[4 * max_x];
    pair<int, int> mn[4 * max_x];

    void push(int v) {
        if (f[v]) {
            mn[2 * v].first += f[v];
            mn[2 * v + 1].first += f[v];
            a[2 * v] += f[v];
            a[2 * v + 1] += f[v];
            f[2 * v] += f[v];
            f[2 * v + 1] += f[v];
            f[v] = 0;
        }
    }

    void add(int v, int tl, int tr, int l, int r, int x) {
        if (tl == l && tr == r) {
            a[v] += x;
            mn[v].first += x;
            f[v] += x;
            return;
        }
        push(v);
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            add(2 * v, tl, mid, l, r, x);
        } else if (l > mid) {
            add(2 * v + 1, mid + 1, tr, l, r, x);
        } else {
            add(2 * v, tl, mid, l, mid, x);
            add(2 * v + 1, mid + 1, tr, mid + 1, r, x);
        }
        mn[v] = merge(mn[2 * v], mn[2 * v + 1]);
    }

    void update(int v, int tl, int tr, int pos, int x) {
        if (tl == tr) {
            mn[v] = {a[v], x};
            return;
        }
        push(v);
        int mid = (tl + tr) / 2;
        if (pos <= mid) {
            update(2 * v, tl, mid, pos, x);
        } else {
            update(2 * v + 1, mid + 1, tr, pos, x);
        }
        mn[v] = merge(mn[2 * v], mn[2 * v + 1]);
    }
};

int n, q, a[max_n];
tree t;

void proc(int i, int z) {
    if (a[i] < a[i - 1]) {
        t.add(1, 1, max_x, a[i] + 1, a[i - 1], z);
    } else {
        t.add(1, 1, max_x, a[i - 1] + 1, a[i], z);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    a[0] = max_x;
    for (int i = 1; i <= n + 1; ++i) {
        proc(i, 1);
    }
    for (int i = 1; i <= n; ++i) {
        t.update(1, 1, max_x, a[i], 1);
    }
    while (q--) {
        int pos, x;
        scanf("%d%d", &pos, &x);
        proc(pos, -1);
        proc(pos + 1, -1);
        t.update(1, 1, max_x, a[pos], 0);
        a[pos] = x;
        t.update(1, 1, max_x, a[pos], 1);
        proc(pos, 1);
        proc(pos + 1, 1);
        int ans = 0;
        if (t.mn[1].first == 1) {
            ans = t.mn[1].second;
        }
        printf("%d\n", ans);
    }
    return 0;
}