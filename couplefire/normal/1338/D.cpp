#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, dp[N][2], ans;
vector<int> adj[N];

void dfs(int v, int p){
    dp[v][0] = 1, dp[v][1] = (int)adj[v].size()-(p!=-1);
    for(auto u : adj[v]){
        if(u==p) continue;
        dfs(u, v);
        ans = max(ans, dp[v][0]+dp[u][1]);
        ans = max(ans, dp[v][1]+max(dp[u][0], dp[u][1])-(p==-1));
        dp[v][0] = max(dp[v][0], dp[u][1]+1);
        dp[v][1] = max(dp[v][1], max(dp[u][0], dp[u][1])+(int)adj[v].size()-1-(p!=-1));
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i<n-1; ++i){
        int a, b; cin >> a >> b; --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    } dfs(0, -1);
    cout << ans << '\n';
}