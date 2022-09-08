#include <bits/stdc++.h>

using namespace std;

const int max_n = 400444, inf = 1000111222;

template<typename T>
struct segment_tree {
    T f[4 * max_n];
    T mx[4 * max_n];

    void build(int v, int l, int r, T a[]) {
        f[v] = 0;
        if (l == r) {
            mx[v] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, a);
        build(2 * v + 1, mid + 1, r, a);
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }

    void push(int v, int l, int r, int mid) {
        if (f[v]) {
            mx[2 * v] += f[v];
            mx[2 * v + 1] += f[v];
            f[2 * v] += f[v];
            f[2 * v + 1] += f[v];
            f[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, T value) {
        if (tl == l && tr == r) {
            f[v] += value;
            mx[v] += value;
            return;
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        if (r <= mid) {
            update(2 * v, tl, mid, l, r, value);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r, value);
        } else {
            update(2 * v, tl, mid, l, mid, value);
            update(2 * v + 1, mid + 1, tr, mid + 1, r, value);
        }
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }

    T get_max(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return mx[v];
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        if (r <= mid) {
            return get_max(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_max(2 * v + 1, mid + 1, tr, l, r);
        }
        return max(get_max(2 * v, tl, mid, l, mid), get_max(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};

int n, k, q, init[max_n];
set<pair<int, int>> all;
segment_tree<int> t;
multiset<int> xs;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &k, &q);
    for (int i = 0; i < max_n; ++i) {
        init[i] = i;
    }
    t.build(1, 0, max_n - 1, init);
    while (q--) {
        int col, row;
        scanf("%d%d", &col, &row);
        int pos = row + abs(col - k);
        if (!all.count({col, row})) {
            all.insert({col, row});
            t.update(1, 0, max_n - 1, 0, pos, 1);
            xs.insert(pos);
        } else {
            all.erase({col, row});
            t.update(1, 0, max_n - 1, 0, pos, -1);
            xs.erase(xs.find(pos));
        }
        if (all.empty()) {
            puts("0");
        } else {
            int mx = *xs.rbegin();
            printf("%d\n", max(0, t.get_max(1, 0, max_n - 1, 0, mx) - n - 1));
        }
    }
    return 0;
}