#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

void solve(){
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<int> dp[2], dist;
    dp[0].assign(n+1, 0);
    dp[1].assign(n+1, 0);
    dist.assign(n+1, n);
    vector<vector<int>> adj(n+1);
    for(int i = 1; i<=m; ++i){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> que;
    que.push(s);
    dist[s] = 0;
    while(que.size()){
        int v = que.front(); que.pop();
        for(auto u : adj[v])
            if(dist[u]==n){
                dist[u] = dist[v]+1;
                que.push(u);
            }
    }
    vector<int> stuff(n+1);
    iota(stuff.begin()+1, stuff.end(), 1);
    sort(stuff.begin()+1, stuff.end(), [&](int a, int b){
        return dist[a]<dist[b];
    });
    dp[0][s] = 1;
    for(int i = 1; i<=n; ++i){
        int v = stuff[i];
        for(auto u : adj[v]){
            if(dist[u]==dist[v]-1)
                inc(dp[0][v], dp[0][u]);
        }
    }
    for(int i = 1; i<=n; ++i){
        int v = stuff[i];
        for(auto u : adj[v]){
            if(dist[u]==dist[v]-1)
                inc(dp[1][v], dp[1][u]);
            else if(dist[u]==dist[v])
                inc(dp[1][v], dp[0][u]);
        }
    }
    cout << add(dp[0][t], dp[1][t]) << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}