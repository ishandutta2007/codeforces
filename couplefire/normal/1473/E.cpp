#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define INF 1e18+9ll

int n, m;
vector<pair<int, int>> adj[4*MAXN]; //0: no jump, 1: jump max, 2: jump min, 3: jump both
long long dp[4*MAXN];

int hsh(pair<int, int> p){return n*p.second+p.first;}
void ae(int a, int b, int w){
    adj[a].push_back({b, w});
    adj[b].push_back({a, w});
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int a, b, w; cin >> a >> b >> w;
        --a; --b;
        for(int j = 0; j<4; j++) ae(hsh({a, j}), hsh({b, j}), w);
        adj[hsh({a, 0})].push_back({hsh({b, 1}), 0});
        adj[hsh({b, 0})].push_back({hsh({a, 1}), 0});
        adj[hsh({a, 0})].push_back({hsh({b, 2}), 2*w});
        adj[hsh({b, 0})].push_back({hsh({a, 2}), 2*w});
        adj[hsh({a, 1})].push_back({hsh({b, 3}), 2*w});
        adj[hsh({b, 1})].push_back({hsh({a, 3}), 2*w});
        adj[hsh({a, 2})].push_back({hsh({b, 3}), 0});
        adj[hsh({b, 2})].push_back({hsh({a, 3}), 0});
        adj[hsh({a, 0})].push_back({hsh({b, 3}), w});
        adj[hsh({b, 0})].push_back({hsh({a, 3}), w});
    }
    fill(dp, dp+4*MAXN, INF);
    dp[hsh({0, 0})] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, hsh({0, 0})});
    while(!pq.empty()){
        int v = pq.top().second;
        long long d = pq.top().first;
        pq.pop();
        if(d != dp[v]) continue;
        for(auto to : adj[v]){
            int u = to.first, w = to.second;
            if(d+w < dp[u]){
                dp[u] = d+w;
                pq.push({dp[u], u});
            }
        }
    }
    // cout << dp[hsh({2, 0})] << endl;
    for(int i = 1; i<n; i++){
        cout << dp[hsh({i, 3})] << endl;
    }
}