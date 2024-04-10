#include <bits/stdc++.h>
using namespace std;

const int N = 220000;

vector<int> adj[N];
int dp[N];
int ans[3][N];

void dfs(int u, int p) {
    dp[u] = dp[p] + 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    ans[2][u] = (dp[u] >= 2);
    int diff = 1e9;
    for (int v : adj[u]) {
        if (v == p) continue;
        ans[0][u] += ans[1][v];
        ans[1][u] += ans[1][v];
        diff = min(diff, ans[2][v] - ans[1][v]);
        ans[2][u] += ans[0][v];
    }
    ans[1][u] = min(ans[2][u], ans[1][u] + diff);
    ans[0][u] = min(ans[0][u], ans[1][u]);
}

int main() {
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dp[0] = -1;
    dfs(1, 0);
    cout << ans[0][1] << endl;
    return 0;
}