#include <bits/stdc++.h>
using namespace std;
#define MAXN 500005
#define INF 1000000009

int n, m;
vector<pair<int, int>> adj[MAXN];
int dp[2][MAXN];
int col[MAXN];

void dijkstra(){
    dp[0][n-1] = dp[1][n-1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, n-1});
    while(!pq.empty()){
        int v = pq.top().second, d = pq.top().first;
        pq.pop();
        if(d != max(dp[0][v], dp[1][v])) continue;
        if(dp[0][v] == d) col[v] = 0;
        else col[v] = 1;
        for(auto u : adj[v]){
            int curd = max(dp[0][u.first], dp[1][u.first]);
            dp[u.second][u.first] = min(dp[u.second][u.first], d+1);
            if(max(dp[0][u.first], dp[1][u.first]) < curd) pq.push({max(dp[0][u.first], dp[1][u.first]), u.first});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int a, b, t; cin >> a >> b >> t;
        --a; --b;
        adj[b].push_back({a, t});
    }
    fill(dp[0], dp[0]+MAXN, INF); fill(dp[1], dp[1]+MAXN, INF);
    dijkstra();
    for(int i = 0; i<n; i++){
        if(dp[0][i] == INF) col[i] = 0;
        else if(dp[1][i] == INF) col[i] = 1;
    }
    if(max(dp[0][0], dp[1][0]) == INF) cout << -1 << endl;
    else cout << max(dp[0][0], dp[1][0]) << endl;
    for(int i = 0; i<n; i++) cout << col[i];
    cout << endl;
}