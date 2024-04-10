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

const int max_n = 222222, max_lev = 20, inf = 1111111111;

int n, m, u[max_n], v[max_n];
int cnt, tin[max_n], tout[max_n], p[max_lev][max_n], dd[max_lev][max_n];
vector<int> g[max_n], d[max_n];

void dfs(int v, int pp) {
    p[0][v] = pp;
    ++cnt;
    tin[v] = cnt;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] == pp) {
            continue;
        }
        dfs(g[v][i], v);
        dd[0][g[v][i]] = d[v][i];
    }
    ++cnt;
    tout[v] = cnt;
}

void get_all_p() {
    p[0][1] = 0;
    for (int lev = 1; lev < max_lev; ++lev) {
        for (int i = 1; i <= n; ++i) {
            p[lev][i] = p[lev - 1][p[lev - 1][i]];
            dd[lev][i] = max(dd[lev - 1][i], dd[lev - 1][p[lev - 1][i]]);
        }
    }
}

bool is_ancestor(int u, int v) {
    if (u == 0) {
        return true;
    }
    if (v == 0) {
        return false;
    }
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) {
        return u;
    }
    if (is_ancestor(v, u)) {
        return v;
    }
    for (int i = max_lev - 1; i >= 0; --i) {
        if (!is_ancestor(p[i][u], v)) {
            u = p[i][u];
        }
    }
    return p[0][u];
}

int q[max_n], aa[max_n], bb[max_n], cc[max_n];
vector<pair<int, pair<int, int> > > e;

int find_set(int v) {
    if (v == q[v]) {
        return v;
    }
    return q[v] = find_set(q[v]);
}

void union_set(int v1, int v2) {
    v1 = find_set(v1);
    v2 = find_set(v2);
    q[v1] = v2;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &aa[i], &bb[i], &cc[i]);
        e.push_back(make_pair(cc[i], make_pair(aa[i], bb[i])));
    }
    sort(e.begin(), e.end());
    for (int i = 1; i <= n; ++i) {
        q[i] = i;
    }
    long long ans = 0;
    for (int i = 0; i < m; ++i) {
        int u = e[i].second.first;
        int v = e[i].second.second;
        if (find_set(u) != find_set(v)) {
            union_set(u, v);
            ans += e[i].first;
            g[u].push_back(v);
            g[v].push_back(u);
            d[u].push_back(e[i].first);
            d[v].push_back(e[i].first);
        }
    }
    dfs(1, -1);
    dd[0][1] = -inf;
    get_all_p();
    for (int i = 0; i < m; ++i) {
        int u = aa[i], v = bb[i];
        int lc = lca(u, v);
        int mn = 0;
        for (int j = max_lev - 1; j >= 0; --j) {
            if (!is_ancestor(p[j][u], lc)) {
                mn = max(mn, dd[j][u]);
                u = p[j][u];
            }
        }
        if (u != lc) mn = max(mn, dd[0][u]);
        u = v;
        for (int j = max_lev - 1; j >= 0; --j) {
            if (!is_ancestor(p[j][u], lc)) {
                mn = max(mn, dd[j][u]);
                u = p[j][u];
            }
        }
        if (u != lc) mn = max(mn, dd[0][u]);
        cout << ans - mn + cc[i] << endl;
        //cout << mn << endl;
    }
    return 0;
}