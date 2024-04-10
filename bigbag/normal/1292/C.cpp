#include <bits/stdc++.h>

using namespace std;

const int max_n = 3033, inf = 1000111222;

int n, sz[max_n], h[max_n], tin[max_n], tout[max_n], curt, p[max_n];
vector<int> g[max_n];
vector<pair<int, int>> all[max_n];
long long dp[max_n][max_n];

void dfs(int v) {
    tin[v] = ++curt;
    sz[v] = 1;
    for (int to : g[v]) {
        if (to == p[v]) {
            continue;
        }
        h[to] = h[v] + 1;
        p[to] = v;
        dfs(to);
        sz[v] += sz[to];
    }
    tout[v] = curt;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

void dfs2(int start, int v, int p, int d) {
    if (start < v) {
        all[d].push_back({start, v});
    }
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs2(start, to, v, d + 1);
    }
}

void upd(int u, int v, long long x) {
    dp[u][v] = max(dp[u][v], x);
    swap(u, v);
    dp[u][v] = max(dp[u][v], x);
}

void proc(int u, int v) {
    if (is_ancestor(v, u)) {
        swap(v, u);
    }
    if (is_ancestor(u, v)) {
        int forb;
        for (int to : g[u]) {
            if (to != p[u] && is_ancestor(to, v)) {
                forb = to;
            }
        }
        for (int to : g[v]) {
            if (to == p[v]) {
                continue;
            }
            upd(u, to, dp[u][v] + sz[to] * (n - sz[forb]));
        }
        for (int to : g[u]) {
            if (to == forb) {
                continue;
            }
            if (to == p[u]) {
                upd(to, v, dp[u][v] + sz[v] * (n - sz[u]));
            } else {
                upd(to, v, dp[u][v] + sz[v] * sz[to]);
            }
        }
    } else {
        for (int it = 0; it < 2; ++it) {
            for (int to : g[v]) {
                if (to == p[v]) {
                    continue;
                }
                upd(u, to, dp[u][v] + sz[to] * sz[u]);
            }
            swap(u, v);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    for (int v = 0; v < n; ++v) {
        for (int to : g[v]) {
            if (to == p[v]) {
                continue;
            }
            dp[v][to] = dp[to][v] = sz[to] * (n - sz[to]);
        }
        dfs2(v, v, v, 0);
    }
    for (int it = 1; it + 1 < n; ++it) {
        for (const auto &p : all[it]) {
            proc(p.first, p.second);
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            //cout << i << " " << j << ": " << dp[i][j] << " " << endl;
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << "\n";
    return 0;
}