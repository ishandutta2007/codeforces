#include <bits/stdc++.h>
using namespace std;
#define MAXN 605
#define INF 1000000000000000009ll

int n, m, q;
vector<array<long long, 2>> adj[MAXN];
vector<array<long long, 2>> queries[MAXN];
vector<array<long long, 3>> edges;
long long dist[MAXN][MAXN];
bool good[MAXN*MAXN];

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<n; i++) for(int j = 0; j<n; j++) if(i != j) dist[i][j] = INF;
    for(int i = 0; i<m; i++){
        int a, b, w; cin >> a >> b >> w; --a; --b;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
        edges.push_back({a, b, w});
        dist[a][b] = dist[b][a] = w;
    }
    for(int k = 0; k<n; k++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++) dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
        }
    }
    cin >> q;
    for(int i = 0; i<q; i++){
        int u, v, l; cin >> u >> v >> l; --u; --v;
        queries[u].push_back({v, l});
    }
    for(int i = 0; i<n; i++){
        if(queries[i].empty()) continue;
        long long mx = 0;
        for(auto x : queries[i]) mx = max(mx, x[1]);
        for(int j = 0; j<n; j++){
            dist[j][n] = INF;
            for(auto x : queries[i]) dist[j][n] = min(dist[j][n], dist[j][x[0]]+mx-x[1]);
        }
        for(int j = 0; j<m; j++){
            if(dist[i][edges[j][0]]+dist[edges[j][1]][n]+edges[j][2] <= mx || dist[i][edges[j][1]]+dist[edges[j][0]][n]+edges[j][2] <= mx) good[j] = 1;
        }
    }
    int cnt = 0;
    for(int i = 0; i<m; i++) if(good[i]) cnt++;
    cout << cnt << endl;
}