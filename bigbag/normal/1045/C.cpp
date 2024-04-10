#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;
const int max_lev = 18;

int n, m, q, parent[max_lev][max_n], best_h[max_n], used[max_n], h[max_n];
int real_p[max_lev][max_n];
int tin[max_n], tout[max_n], cur;
vector<int> g[max_n];

void dfs(int v, int p) {
    ++cur;
    tin[v] = cur;
    used[v] = 1;
    parent[0][v] = p;
    real_p[0][v] = p;
    best_h[v] = h[v] - 1;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        if (used[to]) {
            if (h[to] < best_h[v]) {
                best_h[v] = h[to];
                parent[0][v] = to;
            }
        } else {
            h[to] = h[v] + 1;
            dfs(to, v);
            if (best_h[to] < best_h[v]) {
                best_h[v] = best_h[to];
                parent[0][v] = parent[0][to];
            }
        }
    }
    tout[v] = cur;
}

void get_all_p(int parent[max_lev][max_n]) {
    for (int lev = 1; lev < max_lev; ++lev) {
        for (int i = 0; i < n; ++i) {
            parent[lev][i] = parent[lev - 1][parent[lev - 1][i]];
        }
    }
}

bool is_ancestor(int v1, int v2) {
    return tin[v1] <= tin[v2] && tout[v1] >= tout[v2];
}

int lca(int v1, int v2) {
    if (is_ancestor(v1, v2)) {
        return v1;
    }
    for (int i = max_lev - 1; i >= 0; --i) {
        if (!is_ancestor(real_p[i][v1], v2)) {
            v1 = real_p[i][v1];
        }
    }
    return real_p[0][v1];
}

int get_d(int v, int up) {
    if (v == up) {
        return 0;
    }
    int res = 1;
    for (int i = max_lev - 1; i >= 0; --i) {
        if (!is_ancestor(parent[i][v], up)) {
            res += 1 << i;
            v = parent[i][v];
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &q);
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, 0);
    /*for (int i = 0; i < n; ++i) {
        cout << i << ": " << best_h[i] << " " << parent[0][i] << endl;
    }*/
    get_all_p(parent);
    get_all_p(real_p);
    while (q--) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        int lc = lca(u, v);
        int ans = get_d(u, lc) + get_d(v, lc);
        printf("%d\n", ans);
    }
    return 0;
}