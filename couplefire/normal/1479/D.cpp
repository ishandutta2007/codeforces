#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 300005;

mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());

int n, q;
vector<int> adj[N];
int hsh[N], arr[N], up[N][20], tin[N], tout[N], timer;

struct node{
    node *l, *r;
    int val = 0;
    node(int val = 0): l(nullptr), r(nullptr), val(val){}
    node(node *l, node *r): l(l), r(r){
        if(l) val^=l->val;
        if(r) val^=r->val;
    }
};

node* root[N];

node* build(int tl, int tr){
    if(tl == tr) return new node();
    int tm = (tl+tr)>>1;
    return new node(build(tl, tm), build(tm+1, tr));
}

node* upd(node* v, int num, int tl, int tr){
    if(tl == tr) return new node(v->val^hsh[num]);
    int tm = (tl+tr)>>1;
    if(num <= tm) return new node(upd(v->l, num, tl, tm), v->r);
    return new node(v->l, upd(v->r, num, tm+1, tr));
}

void dfs(int v, int p){
    tin[v] = ++timer;
    root[v] = upd(root[v==1?0:p], arr[v], 1, n);
    up[v][0] = p;
    for(int i = 1; i<20; i++)
        up[v][i] = up[up[v][i-1]][i-1];
    for(auto u : adj[v])
        if(u != p) dfs(u, v);
    tout[v] = timer;
}

bool isPar(int u, int v){return tin[u] <= tin[v] && tout[v] <= tout[u];}

int LCA(int u, int v){
    if(isPar(u, v)) return u;
    if(isPar(v, u)) return v;
    for(int i = 19; i>=0; i--)
        if(!isPar(up[u][i], v)) u = up[u][i];
    return up[u][0];
}

int calc(node* a, node* b, node* c, node* d, int tl, int tr){
    if(tl == tr) return tl;
    int tm = (tl+tr)>>1;
    if(a->l->val^b->l->val^c->l->val^d->l->val) 
        return calc(a->l, b->l, c->l, d->l, tl, tm);
    return calc(a->r, b->r, c->r, d->r, tm+1, tr);
}

int query(node* a, node* b, node* c, node* d, int l, int r, int tl, int tr){
    if(tl == l && tr == r){
        if(a->val^b->val^c->val^d->val)
            return calc(a, b, c, d, tl, tr);
        return -1;
    }
    int tm = (tl+tr)>>1;
    if(r <= tm) return query(a->l, b->l, c->l, d->l, l, r, tl, tm);
    if(l >= tm+1) return query(a->r, b->r, c->r, d->r, l, r, tm+1, tr);
    int tmp = query(a->l, b->l, c->l, d->l, l, tm, tl, tm);
    if(tmp != -1) return tmp;
    return query(a->r, b->r, c->r, d->r, tm+1, r, tm+1, tr);
}

main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i<=n; i++)
        cin >> arr[i];
    for(int i = 1; i<=n; i++)
        hsh[i] = rng();
    for(int i = 1; i<n; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    root[0] = build(1, n);
    dfs(1, 1);
    // cout << (root[3]->val^root[5]->val^root[1]->val) << endl;
    while(q--){
        int u, v, l, r; cin >> u >> v >> l >> r;
        int p = LCA(u, v);
        cout << query(root[u], root[v], root[p], root[p==1?0:up[p][0]], l, r, 1, n) << '\n';
    }
}