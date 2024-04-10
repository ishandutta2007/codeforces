#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

struct node{
    int v, val, rbd;
    bool operator < (const node& o) const{if(val!=o.val) return val<o.val; return rbd<o.rbd;}
    bool operator > (const node& o) const{return o<(*this);}
};

int n, m;
vector<node> adj[N];
priority_queue<node, vector<node>, greater<>> pq;
vector<node>::iterator pt[N];

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i<m; ++i){
        int u, v, l, r; cin >> u >> v >> l >> r;
        --u; --v; --r;
        if(l!=r || !(l&1)) 
            adj[u].push_back({n+v, l+(l&1), r-(r&1)}),
            adj[v].push_back({n+u, l+(l&1), r-(r&1)});
        if(l!=r || (l&1))
            adj[n+u].push_back({v, l+!(l&1), r-!(r&1)}),
            adj[n+v].push_back({u, l+!(l&1), r-!(r&1)});
    }
    for(int i = 0; i<2*n; ++i)
        sort(adj[i].begin(), adj[i].end()), pt[i] = adj[i].begin();
    pq.push({0, 0, 0});
    while(!pq.empty()){
        auto [v, val, rbd] = pq.top(); pq.pop();
        if(v==n-1 || v==2*n-1){cout << val << '\n'; return 0;}
        for(auto &it = pt[v]; it!=adj[v].end(); ++it){
            if(it->val>rbd) break; if(it->rbd<val) continue;
            pq.push({it->v, max(it->val, val)+1, it->rbd+1});
        }
    }
    cout << -1 << '\n';
}