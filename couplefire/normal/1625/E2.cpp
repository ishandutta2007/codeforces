#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 600010;

int n, q, shif;
string s; int top, uh, fa[N], siz[N];
vector<int> adj[N]; int pos[N];
int id[N], tin[N], tout[N], tid;

void init(int v){
    tin[v] = ++tid; siz[v] = adj[v].size();
    for(int i = 0; i<siz[v]; ++i)
        pos[adj[v][i]] = ++uh;
    for(auto u : adj[v])
        init(u);
    tout[v] = tid;
}

struct BIT{
    ll bit[N];
    void add(int i, ll v){
        for(; i<N; i=(i|(i+1)))
            bit[i] += v;
    }

    ll query(int r){
        ll res = 0;
        for(; r>=0; r=(r&(r+1))-1)
            res += bit[r];
        return res;
    }

    ll query(int l, int r){
        return query(r)-query(l-1);
    }
} t1, t2;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q >> s;
    int cnt = 0, mn = 0;
    for(int i = 0; i<n; ++i)
        cnt += s[i]=='('?1:-1, mn = min(mn, cnt);
    if(mn<0) s = string(-mn, '(')+s, n += -mn, shif += -mn;
    if(cnt-mn>0) s += string(cnt-mn, ')'), n += cnt-mn;
    for(int i = 0, cur = 0; i<n; ++i){
        if(s[i]=='('){
            fa[++top] = cur;
            adj[cur].push_back(top);
            cur = top; id[i] = cur;
        } else id[i] = cur, cur = fa[cur];
    } init(0);
    for(int i = 0; i<=top; ++i)
        t1.add(tin[i], 1ll*siz[i]*(siz[i]+1)/2);
    while(q--){
        int t, l, r; cin >> t >> l >> r;
        --l; --r; l += shif; r += shif;
        if(t==1){
            int v = id[l];
            t1.add(tin[fa[v]], -1ll*siz[fa[v]]*(siz[fa[v]]+1)/2);
            --siz[fa[v]]; t2.add(pos[v], 1);
            t1.add(tin[fa[v]], 1ll*siz[fa[v]]*(siz[fa[v]]+1)/2);
        } else{
            int u = id[l], v = id[r];
            int huh = pos[v]-pos[u]+1-t2.query(pos[u], pos[v]);
            cout << t1.query(tin[u], tout[v])+1ll*huh*(huh+1)/2 << '\n';
        }
    }
}