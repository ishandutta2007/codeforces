#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;
const int max_x = 1000111;

struct tree {
    long long a[4 * max_x], f[4 * max_x];

    tree() {
        memset(a, 0, sizeof(a));
        memset(f, 0, sizeof(f));
    }

    void build(int v, int l, int r, long long x[]) {
        if (l == r) {
            a[v] = x[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, x);
        build(2 * v + 1, mid + 1, r, x);
        a[v] = max(a[2 * v], a[2 * v + 1]);
    }

    void push(int v, int l, int r) {
        if (f[v] != 0) {
            f[2 * v] += f[v];
            f[2 * v + 1] += f[v];
            a[2 * v] += f[v];
            a[2 * v + 1] += f[v];
            f[v] = 0;
        }
    }
    void update(int v, int tl, int tr, int l, int r, int value) {
        if (tl == l && tr == r) {
            f[v] += value;
            a[v] += value;
            return;
        }
        push(v, tl, tr);
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            update(2 * v, tl, mid, l, r, value);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r, value);
        } else {
            update(2 * v, tl, mid, l, mid, value);
            update(2 * v + 1, mid + 1, tr, mid + 1, r, value);
        }
        a[v] = max(a[2 * v], a[2 * v + 1]);
    }
};

int n, m, k, b[max_n], cb[max_n];
pair<int, int> a[max_n];
pair<pair<int, int>, int> x[max_n];
long long best[max_x];
tree t;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].first, &a[i].second);
    }
    for (int i = 0; i < max_x; ++i) {
        best[i] = -1LL * inf * inf;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &b[i], &cb[i]);
        best[b[i]] = max(best[b[i]], -1LL * cb[i]);
    }
    t.build(1, 0, max_x - 1, best);
    for (int i = 0; i < k; ++i) {
        scanf("%d%d%d", &x[i].first.first, &x[i].first.second, &x[i].second);
    }
    sort(a, a + n);
    sort(x, x + k);
    int pos = 0;
    long long ans = -2 * inf;
    for (int i = 0; i < n; ++i) {
        while (pos < k && x[pos].first.first < a[i].first) {
            t.update(1, 0, max_x - 1, x[pos].first.second + 1, max_x - 1, x[pos].second);
            ++pos;
        }
        long long res = -a[i].second + t.a[1];
        ans = max(ans, res);
    }
    cout << ans << "\n";
    return 0;
}