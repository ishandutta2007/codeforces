#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define int long long

int n, m;
vector<array<int, 2>> adj[MAXN];
vector<array<int, 2>> revadj[MAXN];
int comp[MAXN], cur_comp = 1;
int vis[MAXN], len[MAXN], cycle[MAXN];
vector<int> order;

void dfs1(int v){
    vis[v] = 1;
    for(auto u : adj[v]){
        if(!vis[u[0]]) dfs1(u[0]);
    }
    order.push_back(v);
}

void dfs2(int v){
    comp[v] = cur_comp;
    for(auto u : revadj[v]){
        if(!comp[u[0]]) len[u[0]] = len[v]+u[1], dfs2(u[0]);
        else if(comp[u[0]] == comp[v]) cycle[comp[v]] = __gcd(cycle[comp[v]], llabs(len[v]+u[1]-len[u[0]]));
    }
}

signed main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int a, b, w;; cin >> a >> b >> w; --a; --b;
        adj[a].push_back({b, w});
        revadj[b].push_back({a, w});
    }
    for(int i = 0; i<n; i++) if(!vis[i]) dfs1(i);
    for(int i = n-1; i>=0; i--) if(!comp[order[i]]) dfs2(order[i]), cur_comp++;
    int q; cin >> q;
    while(q--){
        int v, s, t; cin >> v >> s >> t; --v;
        if(s%__gcd(t, cycle[comp[v]])) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}