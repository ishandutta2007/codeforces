#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXW 55
#define MAXN 100005

int n, m;
vector<array<int, 2>> adj[MAXW*MAXN];
int dist[MAXW*MAXN];
priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int u, v, w; cin >> u >> v >> w; --u; --v;
        adj[u].push_back({w*n+v, 0});
        for(int j = 1; j<MAXW; j++) adj[j*n+u].push_back({v, (j+w)*(j+w)});
        adj[v].push_back({w*n+u, 0});
        for(int j = 1; j<MAXW; j++) adj[j*n+v].push_back({u, (j+w)*(j+w)});
    }
    memset(dist, INF, sizeof dist);
    dist[0] = 0; pq.push({0, 0});
    while(!pq.empty()){
        int v = pq.top()[1], d = pq.top()[0]; pq.pop();
        if(d != dist[v]) continue;
        for(auto u : adj[v]){
            if(dist[u[0]] > dist[v]+u[1]){
                dist[u[0]] = dist[v]+u[1];
                pq.push({dist[u[0]], u[0]});
            }
        }
    }
    for(int i = 0; i<n; i++) cout << (dist[i]==INF?-1:dist[i]) << " ";
    cout << endl;
}