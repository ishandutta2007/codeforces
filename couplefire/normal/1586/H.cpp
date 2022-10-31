#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

struct Edge{int u, v, cap, toll;};
struct Query{int u, id;};

int n, q, city_ej[N];
int fa_up[N][20], toll_up[N][20];
int tin[N], tout[N], tid;
int fa[N], mxtoll[N], uej[N], mxej[N];
vector<int> stuff;
vector<Edge> adj[N];
map<int, vector<Edge>> edges;
map<int, vector<Query>> queries; 
pair<int, int> ans[N];

void dfs(int u, int p){
    tin[u] = ++tid;
    for(int i = 1; i<20; ++i)
        fa_up[u][i] = fa_up[fa_up[u][i-1]][i-1],
        toll_up[u][i] = max(toll_up[u][i-1], toll_up[fa_up[u][i-1]][i-1]);
    for(auto e : adj[u])
        if(e.v!=p) fa_up[e.v][0] = u, toll_up[e.v][0] = e.toll, dfs(e.v, u);
    tout[u] = tid;
}

bool isPar(int u, int v){
    return tin[u]<=tin[v] && tout[v]<=tout[u];
}

int getMax(int u, int v){
    int res = 0;
    if(!isPar(u, v)){
        int tu = u;
        for(int i = 19; i>=0; --i)
            if(!isPar(fa_up[tu][i], v))
                res = max(res, toll_up[tu][i]), tu = fa_up[tu][i];
        res = max(res, toll_up[tu][0]);
    }
    if(!isPar(v, u)){
        int tv = v;
        for(int i = 19; i>=0; --i)
            if(!isPar(fa_up[tv][i], u))
                res = max(res, toll_up[tv][i]), tv = fa_up[tv][i];
        res = max(res, toll_up[tv][0]);
    }
    return res;
}

int find(int u){return u==fa[u]?u:fa[u]=find(fa[u]);}

void unite(int u, int v){
    u = find(u), v = find(v);
    if(u==v) return;
    if(mxej[u]>mxej[v]) swap(u, v);
    fa[u] = v;
    if(mxej[u]==mxej[v])
        mxtoll[v] = max({mxtoll[u], mxtoll[v], getMax(uej[u], uej[v])});
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for(int i = 0; i<n; ++i)
        cin >> city_ej[i];
    for(int i = 0; i<n-1; ++i){
        int u, v, cap, toll;
        cin >> u >> v >> cap >> toll;
        --u; --v;
        edges[cap].push_back({u, v, cap, toll});
        adj[u].push_back({u, v, cap, toll});
        adj[v].push_back({v, u, cap, toll});
        stuff.push_back(cap);
    } dfs(0, 0);
    for(int i = 0; i<q; ++i){
        int u, x; cin >> x >> u; --u;
        queries[x].push_back({u, i});
        stuff.push_back(x);
    }
    sort(stuff.begin(), stuff.end());
    stuff.erase(unique(stuff.begin(), stuff.end()), stuff.end());
    reverse(stuff.begin(), stuff.end());
    for(int i = 0; i<n; ++i)
        fa[i] = i, mxtoll[i] = 0, uej[i] = i, mxej[i] = city_ej[i];
    for(auto siz : stuff){
        for(auto e : edges[siz])
            unite(e.u, e.v);
        for(auto qry : queries[siz]){
            int x = find(qry.u);
            ans[qry.id] = {mxej[x], max(mxtoll[x], getMax(qry.u, uej[x]))};
        }
    }
    for(int i = 0; i<q; ++i)
        cout << ans[i].first << ' ' << ans[i].second << '\n';
}