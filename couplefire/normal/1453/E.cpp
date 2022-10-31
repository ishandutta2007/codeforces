#include <bits/stdc++.h>
using namespace std;
#define INF 1000000009

int n;
vector<vector<int>> adj;
vector<int> dp;

bool dfs(int v, int p, int k){
    for(auto u : adj[v]){
        if(u == p) continue;
        bool h = dfs(u, v, k);
        if(!h) return false;
    }
    if(v != 0 && adj[v].size() == 1){
        dp[v] = 0;
        return 1;
    }
    int cnt = 0;
    int mx = 0;
    int mi = INF;
    for(auto u : adj[v]){
        if(u == p) continue;
        if(dp[u]+2 > k) cnt++;
        mx = max(mx, dp[u]+2);
        mi = min(mi, dp[u]+2);
    }
    if(cnt >= 2) return false;
    if(cnt == 0){
        dp[v] = mi-1;
    }
    else{
        if(mx-1 > k) return false;
        dp[v] = mx-1;
    }
    return true;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        cin >> n;
        adj.clear();
        adj.resize(n);
        for(int i = 0; i<n-1; i++){
            int a, b; cin >> a >> b;
            --a; --b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int lo = 1, hi = n;
        while(lo < hi){
            int mid = lo+(hi-lo)/2;
            dp.clear();
            dp.assign(n, INF);
            if(dfs(0, -1, mid)) hi = mid;
            else lo = mid+1;
        }
        cout << lo << endl;
    }
}