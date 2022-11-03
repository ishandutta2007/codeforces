#include <bits/stdc++.h>


using namespace std;


using LL = long long;


vector<int> G[4000];
int par[3010][3010];
int sz[3010][3010];

void dfs(int n, int p, int o) {
    sz[o][n] = 1;
    for(int x : G[n]) {
        if(x == p) {
            continue;
        }
        par[o][x] = n;
        dfs(x, n, o);
        sz[o][n] += sz[o][x];
    }
}


LL memo[3010][3010];
LL dp(int u, int v) {
    if(memo[u][v]) {
        return memo[u][v];
    }
    if(u == v) {
        return 0;
    }
    return memo[u][v] = max(dp(u, par[u][v]), dp(par[v][u], v)) + sz[u][v] * sz[v][u];
}


int main() {
    int N;
    cin >> N;
    
    for(int n = 1; n < N; ++n) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int n = 0; n < N; ++n) {
        dfs(n, -1, n);
    }
    LL ans = 0;
    for(int u = 0; u < N; ++u) {
        for(int v = u + 1; v < N; ++v) {
            ans = max(ans, dp(u, v));
        }
    }
    cout << ans << "\n";
}