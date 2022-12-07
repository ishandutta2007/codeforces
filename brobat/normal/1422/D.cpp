#include <bits/stdc++.h>
using namespace std;
#define int long long

int func(pair<int, int> &a, pair<int, int> &b) {
    return min(abs(a.first - b.first), abs(a.second - b.second));
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int ignore; cin >> ignore;
    int n;
    cin >> n;
    pair <int, int> s, d;
    cin >> s.first >> s.second >> d.first >> d.second;
    vector<pair<int, int>> v(n);
    map<pair<int, int>, int> h;
    map<int, vector<int>> x, y;
    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        h[v[i]] = i;
        x[v[i].first].push_back(v[i].second);
        y[v[i].second].push_back(v[i].first);
    }
    vector<vector<pair<int, int>>> adj(n);
    for(auto i : x) {
        for(int j = 1; j < (int)i.second.size(); j++) {
            int a = h[{i.first, i.second[j]}];
            int b = h[{i.first, i.second[j - 1]}];
            adj[a].push_back({b, 0});
            adj[b].push_back({a, 0});
        }
    }
    for(auto i : y) {
        for(int j = 1; j < (int)i.second.size(); j++) {
            int a = h[{i.second[j], i.first}];
            int b = h[{i.second[j - 1], i.first}];
            adj[a].push_back({b, 0});
            adj[b].push_back({a, 0});
        }
    }
    for(int i = 0; i < n; i++) {
        auto nx = x.upper_bound(v[i].first);
        if(nx == x.end()) continue;
        int a = h[v[i]];
        int b = h[{(*nx).first, (*nx).second[0]}];
        int c = abs((*nx).first - v[i].first);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    for(int i = 0; i < n; i++) {
        auto nx = y.upper_bound(v[i].second);
        if(nx == y.end()) continue;
        int a = h[v[i]];
        int b = h[{(*nx).second[0], (*nx).first}];
        int c = abs((*nx).first - v[i].second);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    // for(int i = 0; i < n; i++) {
    //     cout << "Adj list of {" << v[i].first << "," << v[i].second << "} : ";
    //     for(auto j : adj[i]) {
    //         cout << "{" << v[j.first].first << "," << v[j.first].second << "," << j.second << "} ";
    //     }
    //     cout << '\n';
    // }
    vector <int> dist(n);
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < n; i++) {
        dist[i] = func(v[i], s);
        // cout << dist[i] << " ";
        pq.push({-dist[i], i});
    }
    // cout << '\n';
    while(!pq.empty()) {
        int curr = pq.top().second;
        int curr_dist = -pq.top().first;
        pq.pop();
        if(dist[curr] != curr_dist) continue;
        // cout << "Min. dist for {" << v[curr].first << "," << v[curr].second << "} = " << curr_dist << '\n'; 
        for(auto nx : adj[curr]) {
            if(curr_dist + nx.second < dist[nx.first]) {
                dist[nx.first] = curr_dist + nx.second;
                pq.push({-dist[nx.first], nx.first});
            }
        }
    }
    int ans = abs(s.first - d.first) + abs(s.second - d.second);
    for(int i = 0; i < n; i++) {
        dist[i] += abs(v[i].first - d.first) + abs(v[i].second - d.second);
        ans = min(ans, dist[i]);
    }
    cout << ans;

    return 0;
}