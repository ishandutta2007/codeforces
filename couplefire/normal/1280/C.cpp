#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> siz;
vector<int> pa;
vector<vector<int>> adj;
vector<pair<pair<int, int>,int>> edges;

void dfs(int v, int p){
    pa[v] = p;
    siz[v] = 1;
    for(auto u : adj[v]){
        if(u == p) continue;
        dfs(u,v);
        siz[v] += siz[u];
    }
}

void solve(){
    int k; cin >> k;
    n = 2*k;
    siz.clear();
    siz.resize(n);
    adj.clear();
    adj.resize(n);
    pa.clear();
    pa.resize(n);
    edges.clear();
    edges.resize(n);
    for(int i = 0; i<n-1; i++){
        int a, b, c; cin >> a >> b >> c;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edges[i] = {{a,b},c};
    }
    dfs(0, -1);
    long long good = 0;
    long long bad = 0;
    for(auto e : edges){
        int a = e.first.first, b = e.first.second, c = e.second;
        if(pa[b] == a) swap(a, b);
        if(siz[a]%2 == 1) good += c;
        bad += 1ll*min(siz[a],(n-siz[a]))*c;
    }
    cout << good << " " << bad << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}