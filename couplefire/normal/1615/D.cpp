#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m, fa[N], val[N];
vector<int> adj[N];
vector<array<int, 2>> todo;
array<int, 3> edges[N];

int find(int v){return v==fa[v]?v:fa[v]=find(fa[v]);}

void unite(int u, int v){
    u = find(u); v = find(v);
    if(u==v) return;
    fa[u] = v;
}

bool dfs(int v, int c){
    val[v] = c;
    for(auto u : adj[v]){
        if(val[u]==2){
            if(!dfs(u, c^1)) return 0;
        } else if(val[u]!=(c^1)) return 0;
    } return 1;
}

void solve(){
    cin >> n >> m;
    iota(fa, fa+n, 0);
    for(int i = 0; i<n; ++i)
        adj[i].clear();
    todo.clear();
    for(int i = 0; i<n-1; ++i){
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        --edges[i][0]; --edges[i][1];
        bool odd = (__builtin_popcount(edges[i][2])&1);
        if(edges[i][2]!=-1 && !odd)
            unite(edges[i][0], edges[i][1]);
        else if(edges[i][2]!=-1 && odd)
            todo.push_back({edges[i][0], edges[i][1]});
    }
    for(int i = 0; i<m; ++i){
        int a, b, p;
        cin >> a >> b >> p;
        --a; --b;
        if(p) todo.push_back({a, b});
        else unite(a, b);
    }
    for(auto [u, v] : todo)
        adj[find(u)].push_back(find(v)),
        adj[find(v)].push_back(find(u));
    for(int i = 0; i<n; ++i)
        val[i] = 2;
    for(int i = 0; i<n; ++i)
        if(val[find(i)]==2) 
            if(!dfs(find(i), 0)){
                cout << "NO" << '\n';
                return;
            }
    cout << "YES" << '\n';
    for(int i = 0; i<n-1; ++i){
        cout << edges[i][0]+1 << ' ' << edges[i][1]+1 << ' ';
        if(edges[i][2]==-1) cout << (val[find(edges[i][0])]^val[find(edges[i][1])]) << '\n';
        else cout << edges[i][2] << '\n';
    }
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}