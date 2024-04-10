#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <vector <int>> adj(n);
        for (int i = 0, u, v; i < n - 1; ++i) {
            cin >> u >> v, --u, --v;
            adj[u].push_back(v), adj[v].push_back(u);
        }
        vector <int> val(n), sz(n);
        function <void(int, int, int)> dfs = [&](int v, int pa, int d) {
            for (int u : adj[v]) if (u != pa) {
                dfs(u, v, d + 1);
                sz[v] += sz[u];
            }
            int need = d & 1 ? 1 : -1;
            if (d == 0)
                need = 0;
            val[v] = need - sz[v];
            sz[v] += val[v];
        };
        dfs(0, -1, 0);
        for (int i = 0; i < n; ++i)
            cout << val[i] << ' ';
        cout << endl;
    }
}