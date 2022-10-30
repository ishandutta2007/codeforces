#include <bits/stdc++.h>
using namespace std;
#define MAXN 300005
#define INF 1000000000000009

int n;
int arr[MAXN];
vector<int> adj[MAXN];
long long dp[MAXN];
bool visited[MAXN] = {0};
long long bbest = -INF;
int cnt = 0;

void dfs(int v, int p){
    dp[v] = arr[v];
    for(auto u : adj[v]){
        if(u == p) continue;
        dfs(u, v);
        if(dp[u] > 0) dp[v] += dp[u];
    }
}

void dfs2(int v, int p){
    for(auto u : adj[v]){
        if(u == p) continue;
        dfs2(u, v);
    }
    visited[v] = 0;
    for(auto u : adj[v]) if(dp[u] > 0) visited[v] |= visited[u];
    if(dp[v] == bbest && !visited[v]){
        cnt++;
        visited[v] = 1;
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++) cin >> arr[i];
    for(int i  =0; i<n-1; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    for(int i = 0; i<n; i++) if(dp[i] > bbest) bbest = dp[i];
    dfs2(0, -1);
    cout << bbest*cnt << " " << cnt << endl;
}