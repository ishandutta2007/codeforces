#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
long long n;
vector<long long> adj[MAXN];
long long dproot[MAXN][2] = {0};
long long dp[MAXN][2] = {0};
long long total = 0;

long long dfs(long long v, long long p){
    long long a = 0;
    for(auto u : adj[v]){
        if(u != p){
            long long t = dfs(u, v);
            a += t;
            total += t*(n-t);
        }
    }
    for(auto u : adj[v]){
        dproot[v][0] += dproot[u][1];
        dproot[v][1] += dproot[u][0];
    }
    dproot[v][0]++;
    dp[v][0] = dproot[v][0];
    dp[v][1] = dproot[v][1];
    long long sume = 0;
    long long sumo = 0;
    for(auto u : adj[v]){
        dp[v][0] += dp[u][0];
        dp[v][1] += dp[u][1];
        sume += dproot[u][0];
        sumo += dproot[u][1];
    }
    dp[v][0] += sume*sume+sumo*sumo;
    dp[v][1] += sume*sumo;
    for(auto u : adj[v]){
        dp[v][0] -= dproot[u][0]*dproot[u][0]+dproot[u][1]*dproot[u][1];
        dp[v][1] -= dproot[u][1]*dproot[u][0];
    }
    dp[v][0] /= 2;
    return a+1;
}

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(long long i = 0; i<n-1; i++){
        long long a, b; cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    cout << (total+dp[0][1])/2 << endl;
}