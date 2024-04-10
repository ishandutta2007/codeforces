#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111111, max_lev = 19, inf = 111111111;

int n, m, cnt, dist[max_n], p[max_lev][max_n], sz[max_n], t_in[max_n], t_out[max_n];
vector<int> g[max_n];

void dfs(int v, int lev) {
    dist[v] = lev;
    sz[v] = 1;
    ++cnt;
    t_in[v] = cnt;
    for (int i = 0; i < g[v].size(); ++i) {
        if (sz[g[v][i]] == 0) {
            p[0][g[v][i]] = v;
            dfs(g[v][i], lev + 1);
            sz[v] += sz[g[v][i]];
        }
    }
    ++cnt;
    t_out[v] = cnt;
}

void get_all_ancestors() {
    for (int i = 1; i < max_lev; ++i) {
        for (int j = 0; j < max_n; ++j) {
            p[i][j] = p[i - 1][p[i - 1][j]];
        }
    }
}

bool is_ancestor(int v1, int v2) {
    return v1 == 0 || t_in[v1] <= t_in[v2] && t_out[v1] >= t_out[v2];
}

int lca(int v1, int v2) {
    if (is_ancestor(v1, v2)) {
        return v1;
    }
    if (is_ancestor(v2, v1)) {
        return v2;
    }
    int res = v2;
    for (int i = max_lev - 1; i >= 0; --i) {
        if (!is_ancestor(p[i][res], v1)) {
            res = p[i][res];
        }
    }
    return p[0][res];
}

int get_parent(int v, int d) {
    for (int i = max_lev - 1; i >= 0; --i) {
        if ((1 << i) <= d) {
            d -= (1 << i);
            v = p[i][v];
        }
    }
    return v;
}

int main() {
    //freopen("lca.in", "r", stdin);
    //freopen("lca.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    get_all_ancestors();
    scanf("%d", &m);
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        int lc = lca(u, v);
        int d1 = dist[u] - dist[lc];
        int d2 = dist[v] - dist[lc];
        if ((d1 + d2) % 2 == 1) {
            printf("0\n");
        } else if (u == v) {
            printf("%d\n", n);
        } else {
            if (d1 < d2) {
                swap(d1, d2);
                swap(u, v);
            }
            int Q = n;
            int x = get_parent(u, (d1 + d2) / 2);
            int y1 = get_parent(u, (d1 + d2) / 2 - 1);
            int y2 = 0;
            if (x == lc) {
                y2 = get_parent(v, d2 - 1);
                //cout << "!" << y2 << endl;
            } else {
                Q = sz[x];
            }
            //cout << lc << " " << x << "  " << y1 << " " << y2 << "   " << u << " " << v << "  " << d1 << " " << d2 << endl;
            printf("%d\n", Q - sz[y1] - sz[y2]);
        }
    }
    return 0;
}