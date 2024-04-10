#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1000000000 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int s, t;
        cin >> s >> t;
        --s; --t;
        vector<vector<int>> adj(n);
        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector <int> vis(n, 0);
        vector <int> dist(n, -1);
        vector <int> cnt(n, 0);
        vector <int> sh(n, 0);
        queue <pair<int, int>> q;
        vis[s] = 1;
        dist[s] = 0;
        sh[s] = 1;
        q.push({s, 0});
        while(!q.empty()) {
            int curr = q.front().first;
            int add = q.front().second;
            q.pop();
            for(auto next : adj[curr]) {
                if(add == 0) {
                    if(vis[next] == 0) {
                        dist[next] = dist[curr] + 1;
                        vis[next] = 1;
                        q.push({next, 0});
                    }
                    if(dist[next] == dist[curr] + 1) {
                        sh[next] += sh[curr];
                        sh[next] %= MOD;
                    }
                    if(dist[next] == dist[curr]) {
                        cnt[next] += sh[curr];
                        cnt[next] %= MOD;
                        if(vis[next] == 1) {
                            vis[next] = 2;
                            q.push({next, 1});
                        }
                    }
                } else {
                    if(dist[next] == dist[curr] + add) {
                        if(vis[next] == 1) {
                            vis[next] = 2;
                            q.push({next, 1});
                        }
                        cnt[next] += cnt[curr];
                        cnt[next] %= MOD;
                    }
                }
            }
        }
        cout << (cnt[t] + sh[t]) % MOD << '\n';
    }
    
    return 0;
}