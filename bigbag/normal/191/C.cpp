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

const int max_n = 101111, max_lev = 18, inf = 1111111111;

int n, cnt, p[max_lev][max_n], tin[max_n], tout[max_n], a[max_n], u[max_n], v[max_n], ans[max_n];
vector<int> g[max_n];

void dfs(int v, int par) {
    p[0][v] = par;
    ++cnt;
    tin[v] = cnt;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != par) {
            dfs(g[v][i], v);
        }
    }
    ++cnt;
    tout[v] = cnt;
}

void get_all_ancestors() {
    for (int lev = 1; lev < max_lev; ++lev) {
        for (int i = 1; i <= n; ++i) {
            p[lev][i] = p[lev - 1][p[lev - 1][i]];
        }
    }
}

bool is_ancestor(int v1, int v2) {
    return v1 == 0 || (tin[v1] <= tin[v2] && tout[v1] >= tout[v2]);
}

int lca(int v1, int v2) {
    if (is_ancestor(v1, v2)) {
        return v1;
    }
    if (is_ancestor(v2, v1)) {
        return v2;
    }
    for (int i = max_lev - 1; i >= 0; --i) {
        if (!is_ancestor(p[i][v1], v2)) {
            v1 = p[i][v1];
        }
    }
    return p[0][v1];
}

void get_ans(int v, int p) {
    ans[v] = a[v];
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != p) {
            get_ans(g[v][i], v);
            ans[v] += ans[g[v][i]];
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &u[i], &v[i]);
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
    }
    dfs(1, 0);
    cnt = 0;
    get_all_ancestors();
    int qqq;
    scanf("%d", &qqq);
    while (qqq--) {
        int u, v;
        scanf("%d%d", &u, &v);
        int lc = lca(u, v);
        a[lc] -= 2;
        ++a[u];
        ++a[v];
    }
    get_ans(1, 0);
    for (int i = 1; i < n; ++i) {
        if (is_ancestor(v[i], u[i])) {
            printf("%d ", ans[u[i]]);
        } else {
            printf("%d ", ans[v[i]]);
        }
    }
    return 0;
}