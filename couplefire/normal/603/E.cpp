#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005

struct DSU{
    int fa[MAXN], siz[MAXN], st[MAXN], n, tot = 0, top = 0;
    void init(int nn){
        n = nn;
        tot = n;
        for(int i = 1; i<=n; i++) fa[i] = i, siz[i] = 1;
    }
    int find(int v){
        while(v != fa[v]) v = fa[v];
        return v;
    }
    void link(int v, int u){
        v = find(v), u = find(u);
        if(u == v) return;
        if(siz[v] < siz[u]) swap(v, u);
        fa[u] = v; tot -= (siz[v]&1), tot -= (siz[u]&1);
        siz[v] += siz[u]; tot += (siz[v]&1); st[++top] = u;
    }
    void back(){
        int u = st[top--], v = fa[u];
        tot -= (siz[v]&1); siz[v] -= siz[u]; tot += (siz[v]&1);
        tot += (siz[u]&1); fa[u] = u;
    }
};

struct edges{
    int ind, u, v, w;
    edges(){}
};

int n, m;
edges e[3*MAXN];
edges bruh[3*MAXN];
int ans[3*MAXN];
DSU dsu;
int id[3*MAXN];

void cdq(int l, int r, int x, int y){
    if(l > r) return;
    int mid = (l+r)/2, pre = dsu.top;
    for(int i = l; i<=mid; i++){
        if(id[i] < x) dsu.link(bruh[i].v, bruh[i].u);
    }
    for(int i = x; i<=y; i++){
        if(e[i].ind <= mid) dsu.link(e[i].v, e[i].u);
        if(!dsu.tot){
            ans[mid] = i; break;
        }
    }
    while(dsu.top > pre) dsu.back();
    if(!ans[mid]){
        for(int i = l; i<=mid; i++){
            if(id[i] < x) dsu.link(bruh[i].v, bruh[i].u);
        }
        cdq(mid+1, r, x, y);
        return;
    }
    for(int i = l; i<=mid; i++){
        if(id[i] < x) dsu.link(bruh[i].v, bruh[i].u);
    }
    cdq(mid+1, r , x, ans[mid]);
    while(dsu.top > pre) dsu.back();
    for(int i = x; i<=ans[mid]; i++){
        if(e[i].ind < l) dsu.link(e[i].v, e[i].u);
    }
    cdq(l, mid-1, ans[mid], y);
    while(dsu.top > pre) dsu.back();
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m; dsu.init(n);
    for(int i = 1; i<=m; i++){
        e[i].ind = i;
        cin >> e[i].u >> e[i].v >> e[i].w;
        bruh[i] = e[i];
    }
    sort(e+1, e+m+1, [&](edges a, edges b){return a.w < b.w;});
    for(int i = 1; i<=m; i++) id[e[i].ind] = i;
    cdq(1, m, 1, m);
    for(int i = 1; i<=m; i++) cout << ((!ans[i])?-1:e[ans[i]].w) << endl;
}