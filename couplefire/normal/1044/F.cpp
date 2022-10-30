#include <bits/stdc++.h>
using namespace std;
#define MAXN 201000

pair<int, int> numMax[MAXN*4];
int lazy[MAXN*4] = {0};

pair<int, int> comb(pair<int, int> p1, pair<int, int> p2){
    if(p1.first == p2.first) return {p1.first, p1.second+p2.second};
    else if(p1.first > p2.first) return p1;
    else return p2;
}

void pull(int v){
    numMax[v] = comb(numMax[v*2], numMax[v*2+1]);
}

void push(int v, int l, int r){
    numMax[v].first += lazy[v];
    if(l != r) lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
    lazy[v] = 0;
}

void build(int v = 1, int l = 0, int r = MAXN-1){
    if(l == r){
        numMax[v] = {0, 1};
        return;
    }
    int mid = (l+r)>>1;
    build(v*2, l, mid); build(v*2+1, mid+1, r);
    pull(v);
}

void upd(int lo, int hi, int inc, int v = 1, int l = 0, int r = MAXN-1){
    push(v, l, r);
    if(hi < l || r < lo) return;
    if(lo <= l && r <= hi){
        lazy[v] = inc;
        push(v, l, r);
        return;
    }
    int mid = (l+r)>>1;
    upd(lo, hi, inc, v*2, l, mid); upd(lo, hi, inc, v*2+1, mid+1, r);
    pull(v);
}

pair<int, int> query(int lo, int hi, int v = 1, int l = 0, int r = MAXN-1){
    push(v, l, r);
    if(hi < l || r < lo) return {-2*MAXN, 0};
    if(lo <= l && r <= hi) return numMax[v];
    int mid = (l+r)>>1;
    return comb(query(lo, hi, v*2, l, mid), query(lo, hi, v*2+1, mid+1, r));
}

int n, t, l;
set<pair<int, int>> edges;
vector<int> adj[MAXN];
vector<vector<int>> up;

int timer;
int tin[MAXN], tout[MAXN];
int depth[MAXN];

void dfs(int v, int p, int d = 0){
    timer++;
    tin[v] = timer;
    depth[v] = d;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)  up[v][i] = up[up[v][i-1]][i-1];
    for (int u : adj[v]) if(u != p) dfs(u, v, d+1);
    tout[v] = timer;
}

bool is_ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int getAncestor(int v, int num){
    for(int i = l; i>=0; --i){
        if(num >= (1<<i)){
            num -= (1<<i);
            v = up[v][i];
        }
    }
    return v;
}

void preprocess() {
    l = ceil(log2(n));
    timer = -1;
    up.assign(n, vector<int>(l + 1));
    dfs(0, 0);
}

void solve(){
    int a, b; cin >>a >> b;
    --a; --b;
    int sgn = 1;
    if(edges.count({min(a, b), max(a, b)})){
        sgn = -1;
        edges.erase({min(a, b), max(a, b)});
    }
    else{
        edges.insert({min(a, b), max(a, b)});
    }
    if(depth[a] > depth[b]) swap(a, b);
    if(!is_ancestor(a, b)){
        upd(0, timer, -1*sgn);
        upd(tin[a], tout[a], 1*sgn);
        upd(tin[b], tout[b], 1*sgn);
    }
    else{
        int aa = getAncestor(b, depth[b]-depth[a]-1);
        upd(tin[aa], tout[aa], -1*sgn);
        upd(tin[b], tout[b], 1*sgn);
    }
    pair<int, int> q = query(0, timer);
    if(q.first != 0) cout << 0 << endl;
    else cout << q.second << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> t;
    for(int i = 0; i<n-1; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    build();
    preprocess();
    while(t--){
        solve();
    }
}