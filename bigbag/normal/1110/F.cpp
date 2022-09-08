#include <bits/stdc++.h>

using namespace std;

const int max_n = 500555;
const long long inf = 1000111222000111222LL;

struct tree {
    long long add[4 * max_n], mn[4 * max_n];

    void build(int v, int l, int r, long long h[]) {
        add[v] = 0;
        if (l == r) {
            mn[v] = h[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, h);
        build(2 * v + 1, mid + 1, r, h);
        mn[v] = min(mn[2 * v], mn[2 * v + 1]);
    }

    void push(int v) {
        if (add[v]) {
            add[2 * v] += add[v];
            add[2 * v + 1] += add[v];
            mn[2 * v] += add[v];
            mn[2 * v + 1] += add[v];
            add[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, int x) {
        if (tl == l && tr == r) {
            mn[v] += x;
            add[v] += x;
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
        mn[v] = min(mn[2 * v], mn[2 * v + 1]);
    }

    long long get_min(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return mn[v];
        }
        push(v);
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_min(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_min(2 * v + 1, mid + 1, tr, l, r);
        }
        return min(get_min(2 * v, tl, mid, l, mid), get_min(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};

int n, q, l[max_n], r[max_n];
long long dist[max_n], ans[max_n];
vector<int> g[max_n], d[max_n], queries[max_n];
int t, tin[max_n], tout[max_n];
tree tr;

void dfs(int v) {
    ++t;
    tin[v] = t;
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        dist[to] = dist[v] + d[v][i];
        dfs(to);
    }
    tout[v] = t;
    if (!g[v].empty()) {
        dist[v] = inf;
    }
}

void solve(int v) {
    for (int id : queries[v]) {
        ans[id] = tr.get_min(1, 1, n, l[id], r[id]);
    }
    for (int i = 0; i < g[v].size(); ++i) {
        tr.update(1, 1, n, 1, n, d[v][i]);
        tr.update(1, 1, n, tin[g[v][i]], tout[g[v][i]], -2 * d[v][i]);
        solve(g[v][i]);
        tr.update(1, 1, n, 1, n, -d[v][i]);
        tr.update(1, 1, n, tin[g[v][i]], tout[g[v][i]], 2 * d[v][i]);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 2; i <= n; ++i) {
        int p, w;
        scanf("%d%d", &p, &w);
        g[p].push_back(i);
        d[p].push_back(w);
    }
    for (int i = 0; i < q; ++i) {
        int v;
        scanf("%d%d%d", &v, &l[i], &r[i]);
        queries[v].push_back(i);
    }
    dfs(1);
    tr.build(1, 1, n, dist);
    solve(1);
    for (int i = 0; i < q; ++i) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}