#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 100005;

int n, q, up[N], dep[N], siz[N], subsiz[N], ans[N], fa[N], tot;
vector<int> adj[N];

int find(int v){return v==fa[v]?v:fa[v]=find(fa[v]);}

void unite(int u, int v){
    u = find(u), v = find(v);
    if(u==v) return;
    fa[u] = v;
}

void dfs1(int v, int p){
    up[v] = p, siz[v] = 1;
    for(auto u : adj[v])
        if(u!=p) dep[u] = dep[v]+1, dfs1(u, v), subsiz[v] += subsiz[u], ans[v] -= subsiz[u]*subsiz[u];
    ans[v] += subsiz[v]*subsiz[v];
    ans[v] += 2*(n-1-subsiz[v])*subsiz[v];
    ++subsiz[v]; tot += ans[v];
}

void join(int u, int v){
    tot -= ans[v]+ans[u];
    int tmp = ans[v]+ans[u];
    int utmp = ((ans[u]-2*siz[u]*(n-subsiz[u])*(subsiz[u]-1))/siz[u]+2*(subsiz[u]-1))*siz[v];
    int vtmp = ((ans[v]-2*siz[v]*subsiz[u]*(n-subsiz[u]-1))/siz[v]+2*(n-subsiz[u]-1))*siz[u];
    ans[v] = tmp+utmp+vtmp, ans[u] = 0;
    siz[v] += siz[u], siz[u] = 0, subsiz[u] = 0;
    tot += ans[v];
    unite(u, v);
}

signed main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i<n-1; ++i){
        int u, v; cin >> u >> v; --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i<n; ++i)
        fa[i] = i;
    dfs1(0, -1);
    cout << tot << '\n';
    cin >> q;
    while(q--){
        int u, v; cin >> u >> v; --u; --v;
        u = find(u), v = find(v);
        while(u!=v){
            if(dep[u]<dep[v]) swap(u, v);
            join(u, find(up[u]));
            u = find(u);
        }
        cout << tot << '\n';
    }
}