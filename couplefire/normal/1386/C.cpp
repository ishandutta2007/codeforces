#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005

struct DSU{
    int n;
    int fa[2*MAXN], siz[2*MAXN];
    stack<pair<int, int>> st;
    vector<pair<int, int>> tmp;
    DSU(){}
    void init(int _n){
        n = _n;
        for(int i = 0; i<2*n; i++) fa[i] = i, siz[i] = 1;
    }
    int find(int v){
        while(v != fa[v]) v = fa[v];
        return v;
    }
    int unite(int u, int v){
        int u1 = find(u), v1 = find(v), u2 = find(u+n), v2 = find(v+n);
        if(u1 == v1) return 0;
        if(u1 == v2) return 1;
        if(siz[u1] > siz[v2]) swap(u1, v2);
        fa[u1] = v2; siz[v2] += siz[u1];
        if(siz[u2] > siz[v1]) swap(u2, v1);
        fa[u2] = v1; siz[v1] += siz[u2];
        st.push({u1, v2}); st.push({u2, v1});
        tmp.push_back({u, v});
        return 2;
    }
    void rollback(){
        if(st.empty()) return;
        pair<int, int> x = st.top(); st.pop();
        pair<int, int> y = st.top(); st.pop();
        int u2 = x.first, v1 = x.second, u1 = y.first, v2 = y.second;
        fa[u2] = u2; siz[v1] -= siz[u2];
        fa[u1] = u1; siz[v2] -= siz[u1];
        tmp.pop_back();
    }
} dsu;

int n, m, q;
array<int, 2> edges[MAXN];
int ans[MAXN];

void solve(int tl, int tr, int optl, int optr){
    if(tl > tr) return;
    // cout << tl << " " << tr << " " << optl << " " << optr << endl;
    int cnt = 0;
    int tm = (tl+tr)/2;
    int optm = max(optl, tm-1);
    // cout << tm+1 << endl;
    // for(auto x : dsu.tmp) cout << x.first+1 << " " << x.second+1 << endl;
    for(int i = tl; i<tm; i++){
        int res = dsu.unite(edges[i][0], edges[i][1]);
        if(!res){
            for(int j = tm; j<=tr; j++) ans[j] = optr;
            while(cnt--) dsu.rollback();
            cnt = 0;
            solve(tl, tm-1, optl, optr);
            return;
        }
        cnt += max(res-1, 0);
    }
    for(int i = optr, end = max(tm, optl+1); i>=end; i--){
        int res = dsu.unite(edges[i][0], edges[i][1]);
        if(!res){
            optm = i-1; break;
        }
        cnt += max(res-1, 0);
    }
    // cout << tm+1 << " " << optr+1 << endl;
    ans[tm] = optm;
    while(cnt--) dsu.rollback();
    cnt = 0;
    bool f1 = false;
    for(int i = optr; i>optm; i--){
        int res = dsu.unite(edges[i][0], edges[i][1]);
        if(!res){
            for(int j = tl; j<tm; j++) ans[j] = optm;
            f1 = 1;
            break;
        }
        cnt += max(res-1, 0);
    }
    if(!f1) solve(tl, tm-1, optl, optm);
    while(cnt--) dsu.rollback();
    cnt = 0; bool f2 = false;
    for(int i = tl; i<=tm; i++){
        int res = dsu.unite(edges[i][0], edges[i][1]);
        if(!res){
            for(int j = tm+1; j<=tr; j++) ans[j] = optr;
            f2 = 1;
            break;
        }
        cnt += max(res-1, 0);
    }
    if(!f2) solve(tm+1, tr, optm, optr);
    while(cnt--) dsu.rollback();
    cnt = 0;
}

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    for(int i = 0; i<m; i++){
        cin >> edges[i][0] >> edges[i][1];
        --edges[i][0]; --edges[i][1];
    }
    dsu.init(n);
    solve(0, m-1, -1, m-1);
    // for(int i = 0; i<m; i++) cout << ans[i]+1 << endl;
    while(q--){
        int l, r; cin >> l >> r; --l; --r;
        cout << (ans[l] >= r ? "YES" : "NO") << endl;
    }
}