#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int sz[N];
long double g[N], h[N], f[N], dp[N][N], C[N][N];
vector<int> adj[N];

void dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    sz[u] = 1;
    g[1] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        long double tsum = 0;
        for (int j = sz[v] + 1; j > 0; j--) {
            if (j <= sz[v]) tsum += dp[v][j];
            f[j] = (dp[v][j - 1] * (j - 1) - tsum / 2) / sz[v];
        }
        for (int j = 1; j < sz[u] + sz[v]; j++) h[j] = 0;
        for (int j = 1; j < sz[u]; j++) {
            long double mul = g[j] * j * C[sz[u] - 1][j], fsum = 0;
            for (int k = sz[v] + 1; k > 0; k--) {
                fsum += f[k];
                h[j + k - 1] += mul * fsum * C[sz[v]][k - 1];
            }
        }
        for (int j = 1; j <= sz[v]; j++) {
            long double mul = f[j] * j * C[sz[v]][j], gsum = 0;
            for (int k = sz[u]; k > 0; k--) {
                gsum += g[k];
                h[j + k - 1] += mul * gsum * C[sz[u] - 1][k - 1];
            }
        }
        for (int j = 1; j < sz[u] + sz[v]; j++) h[j] /= j * C[sz[u] + sz[v] - 1][j];
        h[sz[u] + sz[v]] = g[sz[u]] * f[sz[v] + 1];
        sz[u] += sz[v];
        for (int j = 1; j <= sz[u]; j++) g[j] = h[j];
    }
    for (int j = 1; j <= sz[u]; j++) dp[u][j] = g[j];
}

int main() {
    for (int i = 0; i < N; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) C[i][j] = C[i-1][j] + C[i-1][j-1];
    }
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        dfs(i, 0);
        long double ans = 0;
        for (int j = 1; j <= n; j++) ans += dp[i][j];
        printf("%.10lf\n", (double)ans);
    }
    return 0;
}