#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 200005;

int n, k, fa[N], dep[N], cnt[N], nodes[N], vis[N];
vector<int> adj[N];

void init(int v, int p){
    fa[v] = p;
    for(auto u : adj[v])
        if(u!=p) dep[u] = dep[v]+1, init(u, v);
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 0; i<n-1; ++i){
        int u, v; cin >> u >> v; --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    } init(0, 0);
    iota(nodes, nodes+n, 0);
    sort(nodes, nodes+n, [&](int a, int b){return dep[a]>dep[b];});
    for(int i = 0; i<n; ++i){
        int v = nodes[i];
        while(!vis[v]) ++cnt[nodes[i]], vis[v] = 1, v = fa[v];
    }
    sort(nodes, nodes+n, [&](int a, int b){return cnt[a]>cnt[b];});
    int w = n, r = 0, b = n; ll ans = -(ll)1e18;
    for(int i = 0; i<k; ++i){
        --w; ++r; b -= cnt[nodes[i]];
        if(b>=(n+1)/2)
            ans = max(ans, 1ll*(w-n/2)*(r-n/2)),
            ans = max(ans, 1ll*(w-(n+1)/2)*(r-(n+1)/2));
        else ans = max(ans, 1ll*(w-b)*(r-b));
    }
    cout << ans << '\n';
}