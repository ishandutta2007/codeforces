#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int n, m, q, fa[N], tin[N], tout[N], tid;
vector<int> adj[N]; bool vis[N];

void dfs(int v){
    vis[v] = 1, tin[v] = ++tid;
    for(auto u : adj[v])
        if(!vis[u]) fa[u] = v, dfs(u);
    tout[v] = tid;
}

bool isPar(int u, int v){return tin[u]<=tin[v] && tout[v]<=tout[u];}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i<m; ++i){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    } dfs(1);
    cin >> q;
    vector<pair<int, int>> arr(q);
    set<int> st;
    for(int i = 0; i<q; ++i){
        int u, v; cin >> u >> v;
        if(st.count(u)) st.erase(u);
        else st.insert(u);
        if(st.count(v)) st.erase(v);
        else st.insert(v);
        arr[i] = {u, v};
    }
    if(!st.empty()){
        cout << "NO" << '\n';
        cout << st.size()/2 << '\n';
        exit(0);
    }
    cout << "YES" << '\n';
    for(auto [u, v] : arr){
        vector<int> a;
        while(!isPar(u, v))
            a.push_back(u), u = fa[u];
        a.push_back(u);
        vector<int> b;
        while(v!=u) b.push_back(v), v = fa[v];
        reverse(b.begin(), b.end());  
        cout << a.size()+b.size() << '\n';
        for(auto x : a)
            cout << x << ' ';
        for(auto x : b)
            cout << x << ' ';
        cout << '\n';
    }
}