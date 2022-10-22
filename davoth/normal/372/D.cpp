#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10,LN=20,SQ=550,M=5e4+10;
const ll INF=1e18;
const int MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<pair<pll,ll>, null_type,less<pair<pll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,q,s[N],t,ans,d[N],P[LN][N],k,an;
vector<ll> adj[N];
void dfs(ll v, ll p){
    s[v]=++t;
    for(auto u : adj[v]){
        if(u==p) continue;
        P[0][u]=v;
        d[u]=d[v]+1;
        dfs(u,v);
    }
}
ll LCA(ll v, ll u){
    if(d[u]<d[v]) swap(v,u);
    for(ll i=LN; i--;) if(d[P[i][u]]>=d[v]) u=P[i][u];
    if(v==u) return v;
    for(ll i=LN; i--;) if(P[i][u]!=P[i][v]) v=P[i][v],u=P[i][u];
    return P[0][v];
}
auto cmp = [](ll a, ll b) { return s[a]<s[b]; };
set<ll, decltype(cmp)> st(cmp);
ll dist(ll v, ll u){ return d[v]+d[u]-2*d[LCA(v,u)];}
void add(ll v){
    st.insert(v);
    auto nx=st.lower_bound(v);
    auto pv=nx;
    nx++;
    if(nx==st.end()) nx=st.begin();
    if(pv==st.begin()) pv=st.end();
    pv--;
    ans+=dist(v,*pv)+dist(v,*nx)-dist(*pv,*nx);
}
void rem(ll v){
    auto nx=st.lower_bound(v);
    auto pv=nx;
    nx++;
    if(nx==st.end()) nx=st.begin();
    if(pv==st.begin()) pv=st.end();
    pv--;
    ans-=dist(v,*pv)+dist(v,*nx)-dist(*pv,*nx);
    st.erase(v);
}
int main(){
    fast_io;
    cin >> n >> k;
    for(ll i=1; i<n; i++){
        ll v,u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    dfs(1,0);
    for(ll i=1; i<LN; i++) for(ll v=1; v<=n; v++) P[i][v]=P[i-1][P[i-1][v]];
    ll l=1,r=1;
    while(l<=n){
        while(r<=n && ans/2<k){
            add(r++);
        }
        if(ans/2>=k) rem(--r);
        an=max(an,r-l);
        rem(l);
        l++;
        r=max(l,r);
    }
    cout << an << '\n';
    return 0;
}