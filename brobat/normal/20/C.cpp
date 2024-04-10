#include <bits/stdc++.h>
using namespace std;

const long long INF = 1E18;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        --a; --b;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    vector<long long> dist(n, INF);
    vector<int> prev(n, -1);
    priority_queue<pair<long long, int>> pq;
    pq.push({0, 0});
    dist[0] = 0;
    while(!pq.empty()) {
        auto [d, curr] = pq.top();
        d *= -1;
        pq.pop();
        if(d > dist[curr]) continue;
        for(auto [nx, wt] : adj[curr]) {
            if(d + wt < dist[nx]) {
                dist[nx] = d + wt;
                prev[nx] = curr;
                pq.push({-dist[nx], nx});
            }
        }
    }
    if(dist[n - 1] == INF) {
        cout << -1 << '\n';
        return 0;
    }
    vector <int> path;
    int x = n - 1;
    while(x) {
        path.push_back(x);
        x = prev[x];
    }
    path.push_back(0);
    reverse(path.begin(), path.end());
    for(auto i : path) cout << i + 1 << ' ';

    return 0;
}