#include <bits/stdc++.h>

using namespace std;

const int max_n = 500555, inf = 1000111222;

template<typename T>
struct segment_tree {
    T f[4 * max_n];
    T mx[4 * max_n];

    void build(int v, int l, int r) {
        f[v] = -1;
        if (l == r) {
            mx[v] = 0;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }

    void push(int v, int l, int r, int mid) {
        if (f[v] != -1) {
            mx[2 * v] = f[v];
            mx[2 * v + 1] = f[v];
            f[2 * v] = f[v];
            f[2 * v + 1] = f[v];
            f[v] = -1;
        }
    }

    void update(int v, int tl, int tr, int l, int r, T value) {
        if (tl == l && tr == r) {
            f[v] = value;
            mx[v] = value;
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

int n, k, a[max_n], bad[max_n];
vector<int> v;
segment_tree<int> t;

int compress(int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        a[i] -= i;
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    while (k--) {
        int pos;
        scanf("%d", &pos);
        --pos;
        bad[pos] = 1;
    }
    t.build(1, 0, n);
    for (int i = 0; i < n; ++i) {
        int x = compress(a[i]);
        int val = t.get_max(1, 0, n, 0, x) + 1;
        if (bad[i]) {
            t.update(1, 0, n, 0, n, -inf);
        }
        t.update(1, 0, n, x, x, val);
    }
    int ans = t.get_max(1, 0, n, 0, n);
    if (ans < 0) {
        ans = n + 1;
    }
    printf("%d\n", n - ans);
    return 0;
}