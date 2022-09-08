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

const int max_n = 111111, max_lev = 18, max_k = 1111111, mod = 1000000007;

int k, n, tm, p[max_lev][max_n], t_in[max_n], t_out[max_n], pw[max_k], a[max_n], b[max_n], aa, bb;
vector<int> g[max_n], t[max_n], q[max_n];

void dfs(int v, int pp) {
    ++tm;
    t_in[v] = tm;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != pp) {
            p[0][g[v][i]] = v;
            dfs(g[v][i], v);
        }
    }
    ++tm;
    t_out[v] = tm;
}

void get_all_ancestors() {
    for (int i = 1; i < max_lev; ++i) {
        for (int j = 0; j < max_n; ++j) {
            p[i][j] = p[i - 1][p[i - 1][j]];
        }
    }
}

bool is_ancestor(int v1, int v2) {
    return v1 == 0 || (t_in[v1] <= t_in[v2] && t_out[v1] >= t_out[v2]);
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

void dfs2(int v, int p) {
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != p) {
            int ka = aa;
            int kb = bb;
            dfs2(g[v][i], v);
            ka = aa - ka;
            kb = bb - kb;
            if (t[v][i] == -1) {
                q[v][i] += ka;
            }
            if (t[v][i] == 1) {
                q[v][i] += kb;
            }
        }
    }
    //cout << v << " aa = " << aa << "  bb = " << bb << endl;
    aa += a[v];
    bb += b[v];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v, tp;
        scanf("%d%d%d", &u, &v, &tp);
        g[u].push_back(v);
        q[u].push_back(0);
        t[u].push_back(tp);
        g[v].push_back(u);
        q[v].push_back(0);
        t[v].push_back(-tp);
    }
    pw[0] = 1;
    for (int i = 1; i < max_k; ++i) {
        pw[i] = (1LL * pw[i - 1] * 2) % mod;
    }
    dfs(1, -1);
    scanf("%d", &k);
    int v1, v2;
    v1 = 1;
    get_all_ancestors();
    for (int i = 1; i <= k; ++i) {
        scanf("%d", &v2);
        int lc = lca(v1, v2);
        //cout << v1 << " " << v2 << " lca = " << lc << endl;
        --a[lc];
        ++a[v2];
        --b[lc];
        ++b[v1];
        v1 = v2;
    }
    dfs2(1, -1);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            //cout << i << " -> " << g[i][j] << " " << q[i][j] << endl;
            int x = pw[q[i][j]] - 1;
            if (x < 0) {
                x += mod;
            }
            ans += x;
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}