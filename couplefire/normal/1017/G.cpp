#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define f first
#define s second

const int N = 1<<17;
const int INF = 0x3f3f3f3f;

int n, q;
int siz[N], fa[N], tin[N], tout[N], tid = -1, head[N];
int sum[N<<1], suf[N<<1], lazy[N<<1];
vector<int> adj[N];

void dfs_siz(int v){
    siz[v] = 1;
    for(auto& u : adj[v]){
        dfs_siz(u);
        if(siz[u]>siz[adj[v][0]])
            swap(adj[v][0], u);
    }
}

void dfs_hld(int v){
    tin[v] = ++tid;
    for(auto u : adj[v]){
        head[u] = (u==adj[v][0]?head[v]:u);
        dfs_hld(u);
    }
    tout[v] = tid;
}

void push(int v, int tl, int tr){
    if(lazy[v]==INF) return;
    sum[v] = (tr-tl+1)*lazy[v];
    suf[v] = (lazy[v]<0?lazy[v]:sum[v]);
    if(tl!=tr)
        lazy[v<<1] = lazy[v],
        lazy[v<<1|1] = lazy[v];
    lazy[v] = INF;
}

void pull(int v){
    sum[v] = sum[v<<1]+sum[v<<1|1];
    suf[v] = max(suf[v<<1]+sum[v<<1|1], suf[v<<1|1]);
}

void add(int pos, int val, int v = 1, int tl = 0, int tr = N-1){
    push(v, tl, tr);
    if(tr<pos || tl>pos) return;
    if(tl==tr){
        sum[v] += val;
        suf[v] = sum[v];
        return;
    }
    int tm = (tl+tr)>>1;
    add(pos, val, v<<1, tl, tm);
    add(pos, val, v<<1|1, tm+1, tr);
    pull(v);
}

void assign(int l, int r, int val, int v = 1, int tl = 0, int tr = N-1){
    push(v, tl, tr);
    if(tr<l || tl>r) return;
    if(l<=tl && tr<=r){
        lazy[v] = val;
        push(v, tl, tr);
        return;
    }
    int tm = (tl+tr)>>1;
    assign(l, r, val, v<<1, tl, tm);
    assign(l, r, val, v<<1|1, tm+1, tr);
    pull(v);
}

pii query(int l, int r, int v = 1, int tl = 0, int tr = N-1){
    push(v, tl, tr);
    if(l<=tl && tr<=r) return {sum[v], suf[v]};
    int tm = (tl+tr)>>1;
    if(r<=tm) return query(l, r, v<<1, tl, tm);
    if(l>tm) return query(l, r, v<<1|1, tm+1, tr);
    pii a1 = query(l, r, v<<1, tl, tm);
    pii a2 = query(l, r, v<<1|1, tm+1, tr);
    return {a1.f+a2.f, max(a1.s+a2.f, a2.s)};
}

int hld_query(int v){
    int ans = -INF, psum = 0;
    while(v!=-1){
        pii res = query(tin[head[v]], tin[v]);
        ans = max(ans, res.s+psum); psum += res.f;
        v = fa[head[v]];
    } return ans;
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q; fa[0] = -1;
    for(int i = 1; i<n; ++i)
        cin >> fa[i], --fa[i], adj[fa[i]].push_back(i);
    dfs_siz(0); dfs_hld(0);
    memset(lazy, INF, sizeof lazy);
    assign(0, n-1, -1);
    while(q--){
        int t, v; cin >> t >> v; --v;
        if(t==1) add(tin[v], 1);
        else if(t==2){
            assign(tin[v], tout[v], -1);
            int tmp = hld_query(v);
            if(tmp>=0) add(tin[v], -tmp-1);
        } else cout << (hld_query(v)>=0?"black":"white") << '\n';
    }
}