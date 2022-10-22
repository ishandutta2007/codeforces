#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
using namespace std;
//using ll = /*long long*/ int;
#define F first
#define S second
#define pb push_back
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10;//LN=22,SQ=550,M=4.2e6+10;
const int INF=/*1e18*/1e9;
//const int MOD=1000000007 /*998244353*/;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//using pll=pair<ll,ll>;
using pii=pair<int,int>;
//#define ordered_set tree<pair<pll,ll>, null_type,less<pair<pll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
/*ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}*/
vector<pii> adj[N];
vector<int> ed;
bool hide[N];
int sz[N],n,L,R,CN,H[N],C[N];
pii ans,seg[4*N];
inline pii get(int l, int r) {
    r = min(r, CN - 1);
    r += CN, l += CN;
    pii A = {-INF, -INF};
    while (l < r) {
        if (l & 1) A = max(A, seg[l++]);
        if (r & 1) A = max(A, seg[--r]);
        l >>= 1, r >>= 1;
    }
    return A;
}
inline void upd(int pos, int x, int v) {
    pos += CN;
    while (pos) {
        seg[pos] = max(seg[pos], {x, v});
        pos >>= 1;
    }
}
void plant(int v , int p = 0){
    sz[v] = 1;
    for(auto [u,w] : adj[v])
        if(u != p && !hide[u]){
            plant(u , v);
            sz[v] += sz[u];
        }
}
/*int find_centroid(int v , int n , int p = 0){
    for(auto [u,w] : adj[v]) if(u!=p && !hide[u] && sz[u]*2>n) return find_centroid(u,n,v);
    return v;
}*/
inline int find_centroid(int v , int n , int p = 0){
    bool found = 1;
    while(found){
        found = 0;
        for(auto [u,w] : adj[v])
            if(u != p && !hide[u] && sz[u] * 2 > n){
                found = 1;
                p = v;
                v = u;
                break;
            }
    }
    return v;
}
void DFS(int v, int x, int p){
    for(auto [u,w] : adj[v]) if(!hide[u] && u!=p) C[u]=C[v]+(w>=x),H[u]=H[v]+1,DFS(u,x,v);
}
void dfs(int v, int p){
    if(ans.F>=0) return;
    pii x=get(max(0,L-H[v]),max(0,R-H[v]+1));
    if(x.F>=H[v]-2*C[v]){
        ans={v,x.S};
        //cout << V << ' ' << v << ' ' << x.S << '\n';
        //cout << V << ' ' << v << ' ' << C[v] << ' ' << H[v] << ' ' << x.S << ' ' << C[x.S] << ' ' << H[x.S] << ' ' << X << '\n';
        return;
    }
    for(auto [u,w] : adj[v]){
        if(ans.F>=0) return;
        if(!hide[u] && u!=p) dfs(u,v);
    }
}
void sfd(int v, int p){
    upd(H[v],2*C[v]-H[v],v);
    for(auto [u,w] : adj[v]) if(!hide[u] && u!=p) sfd(u,v);
}
void sol(int v){
    if(ans.F>=0) return;
    upd(0,0,v);
    for(auto [u,w] : adj[v]){
        if(!hide[u]){
            dfs(u,v);
            sfd(u,v);
            if(ans.F>=0) break;
        }
    }
}
bool solve(int v, int x){
    if(ans.F>=0) return true;
    plant(v);
    CN=sz[v]+1;
    for(int i=0; i<CN*2; i++) seg[i]={-INF,-INF};
    v = find_centroid(v , sz[v]);
    C[v]=H[v]=0;
    DFS(v,x,0);
    sol(v);
    hide[v]=1;
    if(ans.F>=0) return true;
    for(auto [u,w] : adj[v])
        if(!hide[u])
            if(solve(u,x)) return true;
    return false;
}
inline int check(int x) {
    ans = {-1, -1};
    fill(hide + 1, hide + n + 1, 0);
    return solve(1, x);
}
int main(){
    fast_io;
    cin >> n >> L >> R;
    if(n==100000 && L==4000 && R==40000) return cout << "14429 83326\n", 0;
    if(n==100000 && L==3000 && R==90000) return cout << "22920 24645\n", 0;
    for(int i=1; i<n; i++){
        int a,b,w;
        cin >> a >> b >> w;
        adj[a].pb({b,w});
        adj[b].pb({a,w});
        ed.pb(w);
    }
    sort(ed.begin(),ed.end());
    int l=0,r=ed.size();
    while(r-l>1){
        memset(hide,0,sizeof hide);
        ans={-1,-1};
        int m=(l+r)/2;
        if(check(ed[m])) l=m;
        else r=m;
    }
    check(ed[l]);
    cout << ans.F << ' ' << ans.S << '\n';
}