#include <bits/stdc++.h>
using namespace std;
#define MAXN 300005
#define INF 10000000000000000ll

struct Seg{
    long long mini[4*MAXN], lazy[4*MAXN];
    Seg(){
        fill(mini, mini+4*MAXN, INF);
        fill(lazy, lazy+4*MAXN, 0);
    }
    void push(int ind, int l, int r){
        mini[ind] += lazy[ind];
        mini[ind] = min(mini[ind], INF);
        if(l != r){
            lazy[ind*2] += lazy[ind], lazy[ind*2+1] += lazy[ind];
            lazy[ind*2] = min(lazy[ind*2], INF);
            lazy[ind*2+1] = min(lazy[ind*2+1], INF);
        }
        lazy[ind] = 0;
    }
    void updSet(int pos, long long val, int ind, int tl, int tr){
        push(ind, tl, tr);
        if(tr < pos || tl > pos) return;
        if(tl == tr){
            mini[ind] = val;
            return;
        }
        int tm = (tl+tr)/2;
        updSet(pos, val, ind*2, tl, tm); updSet(pos, val, ind*2+1, tm+1, tr);
        mini[ind] = min(mini[ind*2], mini[ind*2+1]);
    }
    void updAdd(int cl, int cr, long long val, int ind, int tl, int tr){
        push(ind, tl, tr);
        if(tr < cl || tl > cr) return;
        if(tl >= cl && tr <= cr){
            lazy[ind] += val;
            lazy[ind] = min(lazy[ind], INF);
            push(ind, tl, tr);
            return;
        }
        int tm = (tl+tr)/2;
        updAdd(cl, cr, val, ind*2, tl, tm); updAdd(cl, cr, val, ind*2+1, tm+1, tr);
        mini[ind] = min(mini[ind*2], mini[ind*2+1]);
    }
    long long query(int cl, int cr, int ind, int tl, int tr){
        push(ind, tl, tr);
        if(tr < cl || tl > cr) return INF;
        if(tl >= cl && tr <= cr) return mini[ind];
        int tm = (tl+tr)/2;
        return min(query(cl, cr, ind*2, tl, tm), query(cl, cr, ind*2+1, tm+1, tr));
    }
};

int n, m;
vector<int> adj[MAXN];
vector<pair<int, int>> add[MAXN];
vector<pair<int, int>> del[MAXN];
int tin[MAXN], tout[MAXN];
int ind[MAXN];
int cost[MAXN];
int timer;
long long dp[MAXN];
Seg seg;

void init(int v, int p){
    tin[v] = timer+1;
    for(auto x : add[v]) ind[x.second] = ++timer;
    for(auto u : adj[v]){
        if(u == p) continue;
        init(u, v);
    }
    tout[v] = timer;
}

long long solve(int v, int p){
    long long tot = 0;
    for(auto u : adj[v]){
        if(u == p) continue;
        tot += solve(u, v);
        tot = min(tot, INF);
    }
    if(tot == INF) tot = 2*INF;
    if(v == 0) return dp[v] = tot;
    for(auto x : add[v]) seg.updSet(ind[x.second], tot+cost[x.second], 1, 0, MAXN-1);
    for(auto x : del[v]) seg.updSet(ind[x.second], INF, 1, 0, MAXN-1);
    for(auto u : adj[v]){
        if(u == p) continue;
        seg.updAdd(tin[u], tout[u], tot-dp[u], 1, 0, MAXN-1);
    }
    dp[v] = seg.query(tin[v], tout[v], 1, 0, MAXN-1);
    return dp[v];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<n-1; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i<m; i++){
        int x, y, c; cin >> x >> y >> c;
        --x; --y;
        add[x].push_back({y, i});
        del[y].push_back({x, i});
        cost[i] = c;
    }
    init(0, -1);
    solve(0, -1);
    cout << ((dp[0] >= INF)?-1:dp[0]) << endl;
}