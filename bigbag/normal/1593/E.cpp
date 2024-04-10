/**
 *  created: 13/10/2021, 17:51:39
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 404444, inf = 1000111222;

int t, n, k, dist[max_n], sz[max_n];
vector<int> g[max_n];

void clr() {
    for (int i = 0; i < n; ++i) {
        g[i].clear();
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            dist[i] = 0;
            sz[i] = g[i].size();
            if (sz[i] <= 1) {
                q.push(i);
                dist[i] = 1;
            }
        }
        int ans = n;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            ans -= dist[v] <= k;
            for (int to : g[v]) {
                --sz[to];
                if (sz[to] <= 1 && dist[to] == 0) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }
        cout << ans << "\n";
        clr();
    }
    return 0;
}