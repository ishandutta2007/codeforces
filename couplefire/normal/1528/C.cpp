#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> tree, adj;
vector<int> tin, tout, add, del; int timer = -1, ans = 0;
set<array<int, 3>> st;

void init(int v, int p){
    tin[v] = ++timer;
    for(auto u : adj[v])
        if(u != p) init(u, v);
    tout[v] = timer;
}

void dfs(int v, int p){
    auto it = st.lower_bound({tin[v], tout[v], v});
    if(it == st.end() || (*it)[0] > tout[v]){
        if(it == st.begin() || (*prev(it))[1] < tin[v])
            add[v] = v, st.insert({tin[v], tout[v], v});
        else 
            add[v] = v, del[v] = (*prev(it))[2], st.erase(prev(it)), st.insert({tin[v], tout[v], v});
    }
    ans = max(ans, (int)st.size());
    for(auto u : tree[v])
        if(u != p) dfs(u, v);
    if(add[v] != -1) st.erase({tin[add[v]], tout[add[v]], add[v]});
    if(del[v] != -1) st.insert({tin[del[v]], tout[del[v]], del[v]});
}

void solve(){
    tree.clear(); adj.clear(); st.clear();
    tin.clear(); tout.clear(); timer = -1, ans = 0;
    add.clear(); del.clear();
    cin >> n;
    tree.resize(n); adj.resize(n);
    tin.resize(n); tout.resize(n);
    add.assign(n, -1); del.assign(n, -1);
    for(int i = 1; i<n; i++){
        int a; cin >> a; --a;
        tree[i].push_back(a);
        tree[a].push_back(i);
    }
    for(int i = 1; i<n; i++){
        int a; cin >> a; --a;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }
    init(0, 0);
    dfs(0, 0);
    cout << ans << endl;
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}