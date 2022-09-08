#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 200111, max_m = 200111, inf = 1000111222;
const int max_lev = 20;

struct edge {
    int u, v, c, id;

    bool operator < (const edge &e) const {
        return c < e.c;
    }
};

int n, m, ans[max_m], parent[max_n], p[max_lev][max_n], tin[max_n], tout[max_n];
bool in_tree[max_m];
int t, mx[max_lev][max_n];
edge e[max_m];
vector<int> g[max_n], c[max_n];

int find_set(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_set(int v1, int v2, int d) {
    g[v1].push_back(v2);
    g[v2].push_back(v1);
    c[v1].push_back(d);
    c[v2].push_back(d);
    v1 = find_set(v1);
    v2 = find_set(v2);
    parent[v2] = v1;
}

void dfs1(int v) {
    tin[v] = t;
    ++t;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != p[0][v]) {
            mx[0][g[v][i]] = c[v][i];
            p[0][g[v][i]] = v;
            dfs1(g[v][i]);
        }
    }
    tout[v] = t;
}

void get_all_p() {
    for (int lev = 1; lev < max_lev; ++lev) {
        for (int i = 1; i <= n; ++i) {
            p[lev][i] = p[lev - 1][p[lev - 1][i]];
            mx[lev][i] = max(mx[lev - 1][i], mx[lev - 1][p[lev - 1][i]]);
        }
    }
}

bool is_ancestor(int v1, int v2) {
    if (v1 == 0) {
        return true;
    }
    if (v2 == 0) {
        return false;
    }
    return tin[v1] <= tin[v2] && tout[v1] >= tout[v2];
}

int lca(int v1, int v2) {
    if (is_ancestor(v1, v2)) {
        return v1;
    }
    for (int i = max_lev - 1; i >= 0; --i) {
        if (!is_ancestor(p[i][v1], v2)) {
            v1 = p[i][v1];
        }
    }
    return p[0][v1];
}

int get_max_vert(int v1, int v2) {
    int res = 0;
    for (int i = max_lev - 1; i >= 0; --i) {
        if (!is_ancestor(p[i][v1], v2) || p[i][v1] == v2) {
            res = max(res, mx[i][v1]);
            v1 = p[i][v1];
        }
    }
    return res;
}

int get_max(int v1, int v2) {
    int lc = lca(v1, v2);
    return max(get_max_vert(v1, lc), get_max_vert(v2, lc));
}

int update_vert(int v1, int v2, int x) {
    int res = 0;
    for (int i = max_lev - 1; i >= 0; --i) {
        if (!is_ancestor(p[i][v1], v2) || p[i][v1] == v2) {
            mx[i][v1] = min(mx[i][v1], x);
            v1 = p[i][v1];
        }
    }
    return res;
}

void update(int v1, int v2, int x) {
    int lc = lca(v1, v2);
    update_vert(v1, lc, x);
    update_vert(v2, lc, x);
}

void push_all() {
    for (int lev = max_lev - 1; lev > 0; --lev) {
        for (int i = 1; i <= n; ++i) {
            mx[lev - 1][i] = min(mx[lev - 1][i], mx[lev][i]);
            mx[lev - 1][p[lev - 1][i]] = min(mx[lev - 1][p[lev - 1][i]], mx[lev][i]);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].c);
        e[i].id = i;
    }
    sort(e, e + m);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        if (find_set(e[i].u) != find_set(e[i].v)) {
            union_set(e[i].u, e[i].v, e[i].c);
            in_tree[i] = 1;
        }
    }
    dfs1(1);
    get_all_p();
    for (int i = 0; i < m; ++i) {
        if (!in_tree[i]) {
            ans[e[i].id] = get_max(e[i].u, e[i].v);
        }
    }
    memset(mx, 127, sizeof(mx));
    for (int i = 0; i < m; ++i) {
        if (!in_tree[i]) {
            update(e[i].u, e[i].v, e[i].c);
        }
    }
    push_all();
    for (int i = 0; i < m; ++i) {
        if (in_tree[i]) {
            int v = e[i].u;
            if (is_ancestor(e[i].u, e[i].v)) {
                v = e[i].v;
            }
            ans[e[i].id] = mx[0][v];
            if (ans[e[i].id] > inf) {
                ans[e[i].id] = 0;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        printf("%d ", ans[i] - 1);
    }
    return 0;
}