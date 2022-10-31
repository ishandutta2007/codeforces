#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 100005;
const int LIM = N+100;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int pw[N*2], lc[N*120], rc[N*120], hsh[N*120], tot;

int build(int tl, int tr){
    int v = ++tot;
    if(tl == tr) return v;
    int tm = (tl+tr)>>1;
    lc[v] = build(tl, tm);
    rc[v] = build(tm+1, tr);
    return v;
}

array<int, 2> upd(int pos, int v, int tl, int tr){ // new node, carry
    int nv = ++tot;
    lc[nv] = lc[v], rc[nv] = rc[v];
    if(tl == tr){
        hsh[nv] = hsh[v]^1;
        return {nv, hsh[v]};
    }
    int tm = (tl+tr)>>1; array<int, 2> tmp;
    if(pos > tm){
        tmp = upd(pos, rc[nv], tm+1, tr);
        rc[nv] = tmp[0];
    } else{
        tmp = upd(pos, lc[nv], tl, tm);
        lc[nv] = tmp[0];
        if(tmp[1]){
            tmp = upd(pos, rc[nv], tm+1, tr);
            rc[nv] = tmp[0];
        }
    }
    hsh[nv] = add(hsh[lc[nv]], mul(pw[tm-tl+1], hsh[rc[nv]]));
    return {nv, tmp[1]};
}

bool cmp(int v1, int v2, int tl, int tr){
    if(tl == tr) return hsh[v1]<hsh[v2];
    int tm = (tl+tr)>>1;
    if(hsh[rc[v1]] == hsh[rc[v2]])
        return cmp(lc[v1], lc[v2], tl, tm);
    return cmp(rc[v1], rc[v2], tm+1, tr);
}

struct node{
    int v, rt;
    bool operator < (const node& o) const{
        return !cmp(rt, o.rt, 0, LIM);
    }
};

int n, m, s, t, root[N], pre[N];
vector<array<int, 2>> adj[N];
priority_queue<node> pq;

void dfs(int v, int dep){
    if(v == s){
        cout << dep << '\n' << v << " ";
        return;
    }
    dfs(pre[v], dep+1);
    cout << v << " ";
}

void output(){
    cout << hsh[root[t]] << '\n';
    dfs(t, 1); exit(0);
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    cin >> s >> t;
    pw[0] = 1;
    for(int i = 1; i<2*N; i++)
        pw[i] = mul(pw[i-1], 2);
    root[s] = build(0, LIM);
    pq.push({s, root[s]});
    while(!pq.empty()){
        node v = pq.top(); pq.pop();
        if(v.rt != root[v.v]) continue;
        if(v.v == t) output();
        for(auto [u, w] : adj[v.v]){
            auto [rt, _] = upd(w, v.rt, 0, LIM);
            if(!root[u] || cmp(rt, root[u], 0, LIM))
                root[u] = rt, pq.push({u, root[u]}), pre[u] = v.v;
        }
    }
    cout << "-1" << '\n';
}