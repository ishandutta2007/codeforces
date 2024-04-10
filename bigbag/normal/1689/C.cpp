/**
 *  created: 10/06/2022, 19:46:40
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

int t, n, sz[max_n], dp[max_n];
vector<int> g[max_n];

void dfs(int v, int p) {
    sz[v] = 1;
    vector<int> nxt;
    for (int to : g[v]) {
        if (to != p) {
            dfs(to, v);
            nxt.push_back(to);
            sz[v] += sz[to];
        }
    }
    dp[v] = 0;
    if (nxt.size() == 1) {
        dp[v] = sz[nxt[0]] - 1;
    } else if (nxt.size() == 2) {
        for (int it = 0; it < 2; ++it) {
            dp[v] = max(dp[v], sz[nxt[it]] - 1 + dp[nxt[it ^ 1]]);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0, -1);
        cout << dp[0] << "\n";
        for (int i = 0; i < n; ++i) {
            g[i].clear();
        }
    }
    return 0;
}