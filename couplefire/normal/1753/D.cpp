#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, p, q;
    cin >> n >> m >> p >> q;

    vector<string> grid(n);
    for (int i = 0; i<n; ++i) {
        cin >> grid[i];
    }

    vector<vector<int>> mp(n, vector<int>(m));
    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<m; ++j) {
            mp[i][j] = i*m+j;
        }
    }

    vector<vector<pair<int, int>>> adj(n*m);
    vector<ll> dist(n*m, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<m; ++j) {
            if (grid[i][j] == '#') {
                continue;
            }
            if (grid[i][j] == '.') {
                dist[mp[i][j]] = 0;
                pq.push({0, mp[i][j]});
            }
            if (i > 0 && j < m-1 && (grid[i-1][j+1] == 'R' || grid[i-1][j+1] == 'U')) {
                adj[mp[i][j]].push_back({mp[i-1][j+1], p});
            }
            if (i < n-1 && j < m-1 && (grid[i+1][j+1] == 'D' || grid[i+1][j+1] == 'R')) {
                adj[mp[i][j]].push_back({mp[i+1][j+1], p});
            }
            if (i < n-1 && j > 0 && (grid[i+1][j-1] == 'L' || grid[i+1][j-1] == 'D')) {
                adj[mp[i][j]].push_back({mp[i+1][j-1], p});
            }
            if (i > 0 && j > 0 && (grid[i-1][j-1] == 'U' || grid[i-1][j-1] == 'L')) {
                adj[mp[i][j]].push_back({mp[i-1][j-1], p});
            }
            if (i > 1 && grid[i-2][j] == 'U') {
                adj[mp[i][j]].push_back({mp[i-2][j], q});
            }
            if (j < m-2 && grid[i][j+2] == 'R') {
                adj[mp[i][j]].push_back({mp[i][j+2], q});
            }
            if (i < n-2 && grid[i+2][j] == 'D') {
                adj[mp[i][j]].push_back({mp[i+2][j], q});
            }
            if (j > 1 && grid[i][j-2] == 'L') {
                adj[mp[i][j]].push_back({mp[i][j-2], q});
            }
        }
    }

    while (pq.size()) {
        ll d = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (dist[v] != d) {
            continue;
        }

        for (auto [u, w] : adj[v]) {
            if (d+w < dist[u]) {
                dist[u] = d+w;
                pq.push({d+w, u});
            }
        }
    }

    ll ans = INF;
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < m; ++j) {
            ans = min(ans, dist[mp[i][j]] + dist[mp[i+1][j]]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m-1; ++j) {
            ans = min(ans, dist[mp[i][j]] + dist[mp[i][j+1]]);
        }
    }
    cout << (ans == INF ? -1 : ans) << '\n';
}