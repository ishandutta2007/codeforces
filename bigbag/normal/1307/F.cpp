#include <bits/stdc++.h>

using namespace std;

const int max_n = 400444, inf = 1000111222;
const int max_lev = 19;

class tree {
public:
    int curt, tin[max_n], tout[max_n];
    int h[max_n], p[max_lev][max_n];

    void init(int n, vector<int> g[]) {
        curt = 0;
        dfs(0, g);
        get_all_p(n);
    }

    bool is_ancestor(int u, int v) const {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int lca(int u, int v) const {
        if (is_ancestor(u, v)) {
            return u;
        }
        for (int i = max_lev - 1; i >= 0; --i) {
            if (!is_ancestor(p[i][u], v)) {
                u = p[i][u];
            }
        }
        return p[0][u];
    }

    int get_dist(int u, int v) const {
        const int lc = lca(u, v);
        return h[u] + h[v] - 2 * h[lc];
    }

    int get_up(int v, int dist) const {
        for (int i = max_lev - 1; i >= 0; --i) {
            if (get_bit(dist, i)) {
                v = p[i][v];
            }
        }
        return v;
    }

    void update(int &v1, int &v2, int k) {
        int lc = lca(v1, v2);
        int nv1, nv2;
        if (h[v1] - h[lc] >= k) {
            nv1 = get_up(v1, k);
        } else {
            nv1 = get_up(v2, h[v2] - h[lc] - (k - (h[v1] - h[lc])));
        }

        if (h[v2] - h[lc] >= k) {
            nv2 = get_up(v2, k);
        } else {
            nv2 = get_up(v1, h[v1] - h[lc] - (k - (h[v2] - h[lc])));
        }
        v1 = nv1;
        v2 = nv2;
    }

private:
    void dfs(int v, vector<int> g[]) {
        tin[v] = ++curt;
        for (int to : g[v]) {
            if (to == p[0][v]) {
                continue;
            }
            p[0][to] = v;
            h[to] = h[v] + 1;
            dfs(to, g);
        }
        tout[v] = curt;
    }

    void get_all_p(int n) {
        for (int lev = 1; lev < max_lev; ++lev) {
            for (int i = 0; i < n; ++i) {
                p[lev][i] = p[lev - 1][p[lev - 1][i]];
            }
        }
    }

    static bool get_bit(int mask, int pos) {
        return (mask >> pos) & 1;
    }
};

int n, k, m, ok[max_n], from[max_n], p[max_n], dist[max_n];
vector<int> g[max_n];
tree t;

void add_edge(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
}

int find_set(int v) {
    if (v == p[v]) {
        return v;
    }
    return p[v] = find_set(p[v]);
}

void union_set(int v1, int v2) {
    v1 = find_set(v1);
    v2 = find_set(v2);
    p[v1] = v2;
}

void bfs() {
    memset(from, -1, sizeof(from));
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    for (int v = 0; v < n; ++v) {
        if (ok[v]) {
            from[v] = v;
            dist[v] = 0;
            p[v] = v;
            q.push(v);
        }
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : g[v]) {
            if (dist[to] == -1) {
                dist[to] = dist[v] + 1;
                q.push(to);
                if (dist[to] <= k) {
                    from[to] = from[v];
                }
            } else if (dist[v] + 1 <= k && dist[to] <= k && from[v] != from[to]) {
                union_set(from[v], from[to]);
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        add_edge(u, n + i);
        add_edge(v, n + i);
    }
    while (m--) {
        int v;
        scanf("%d", &v);
        --v;
        ok[v] = 1;
    }
    bfs();
    const int vert = 2 * n - 1;
    for (int i = 0; i < vert; ++i) {
        if (from[i] != -1) {
            from[i] = find_set(from[i]);
        }
    }
    t.init(vert, g);
    int q;
    scanf("%d", &q);
    while (q--) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        --v1;
        --v2;
        if (t.get_dist(v1, v2) <= 2 * k) {
            puts("YES");
            continue;
        }
        t.update(v1, v2, k);
        if (from[v1] != -1 && from[v2] != -1 && from[v1] == from[v2]) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}