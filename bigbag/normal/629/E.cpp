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
long long d[max_n], q[max_n], sz[max_n];
long long dd[max_n], qq[max_n], szz[max_n];
int cnt, tin[max_n], tout[max_n], p[max_lev][max_n];
vector<int> g[max_n];

void dfs(int v, int pp) {
    p[0][v] = pp;
    ++cnt;
    tin[v] = cnt;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] == pp) {
            continue;
        }
        dfs(g[v][i], v);
    }
    ++cnt;
    tout[v] = cnt;
}

void get_all_p() {
    p[0][1] = 0;
    for (int lev = 1; lev < max_lev; ++lev) {
        for (int i = 1; i <= n; ++i) {
            p[lev][i] = p[lev - 1][p[lev - 1][i]];
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

void dfs2(int v, int p, int len) {
    q[v] = d[v] = len;
    sz[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != p) {
            dfs2(g[v][i], v, len + 1);
            q[v] += q[g[v][i]];
            sz[v] += sz[g[v][i]];
        }
    }
}

void dfs3(int v, int p) {
    szz[v] = n;
    qq[v] = q[v];
    dd[v] = 0;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != p) {
            long long Q = qq[v] - q[g[v][i]];
            Q += n - 2 * sz[g[v][i]];
            q[g[v][i]] += Q;
            dfs3(g[v][i], v);
            q[g[v][i]] -= Q;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &u[i], &v[i]);
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
    }
    dfs(1, -1);
    get_all_p();
    dfs2(1, -1, 0);
    dfs3(1, -1);
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        int lc = lca(u, v);
        int len = d[u] + d[v] - 2 * d[lc];
        if (u != lc && v != lc) {
            long long ans = 1LL * sz[u] * sz[v] * (len - d[u] - d[v]);
            long long all = 1LL * sz[u] * sz[v];
            ans += 1LL * q[u] * sz[v];
            ans += 1LL * q[v] * sz[u];
            ans += all;
            long double x = ans;
            x /= all;
            printf("%.10f\n", (double) (x));
        } else {
            if (u == lc) {
                swap(u, v);
            }
            int pp = u;
            for (int i = max_lev - 1; i >= 0; --i) {
                if (!is_ancestor(p[i][pp], v)) {
                    pp = p[i][pp];
                }
            }
            long long ans = 1LL * sz[u] * (sz[v] - sz[pp]) * (len - d[u] - d[v]);
            long long all = 1LL * sz[u] * (sz[v] - sz[pp]);
            ans += 1LL * q[u] * (sz[v] - sz[pp]);
            ans += 1LL * (q[v] - q[pp]) * sz[u];

            if (v != 1) {
                pp = p[0][v];
                ans += 1LL * sz[u] * (n - sz[v]) * (len + 1 - d[u]);
                all += 1LL * sz[u] * (n - sz[v]);
                ans += 1LL * q[u] * (n - sz[v]);
                ans += 1LL * (qq[pp] - q[v] + d[pp] * sz[v]) * sz[u];
            }
            ans += all;
            long double x = ans;
            x /= all;
            printf("%.10f\n", (double) (x));
        }
    }
    return 0;
}