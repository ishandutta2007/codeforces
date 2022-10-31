#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, ans[N], k; bool take[N];
vector<int> adj[N], fs[N];

int dfs(int v, int p){
    for(auto u : adj[v])
        if(u!=p) if(!dfs(u, v)) return 0;
    int val = 0;
    for(auto u : adj[v])
        if(u!=p && !take[u]) ++val;
    if(val%k) take[v] = 1, ++val;
    if(val%k) return 0;
    return 1;
}

void solve(){
    cin >> n; fill(ans, ans+n+1, 0);
    for(int i = 0; i<n; ++i)
        adj[i].clear();
    for(int i = 0; i<n-1; ++i){
        int u, v; cin >> u >> v; --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans[1] = 1;
    for(int i = 0; i<n-1; ++i)
        ans[1] = (ans[1]+ans[1])%998244353;
    for(auto x : fs[n-1])
        k = x, ans[x] = dfs(0, -1), memset(take, 0, sizeof take);
    for(int i = n; i>=1; --i)
        for(auto x : fs[n-1])
            if(x%i==0 && x>i) ans[i] -= ans[x];
    for(int i = 1; i<=n; ++i)
        cout << ans[i] << ' ';
    cout << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    for(int i = 2; i<N; ++i)
        for(int j = 1; i*j<N; ++j)
            fs[i*j].push_back(i);
    int t; cin >> t;
    while(t--) solve();
}