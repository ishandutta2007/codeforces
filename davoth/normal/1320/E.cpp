#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll=long long int;
using ld=long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define kill(x) cout << x << '\n';exit(0);
const int N=2e5+10,LN=18,M=1e8+10,SQ=256,B=737,inf=1e9;
const ll INF=1e18;
const ld ep=1e-7;
const int MH=1000696969,MD=998244353,MOD=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,q,st[N],fn[N],t,h[N],P[LN][N],sp[N],vi[N],m[N],wtf[N];
pll d[N];
vector<ll> adj[N];
bool cmp(ll &a, ll &b){
    return st[a]<st[b];
}
void dfs(ll v, ll p=0){
    st[v]=++t;
    h[v]=h[p]+1;
    P[0][v]=p;
    for(ll i=1; i<LN; i++) P[i][v]=P[i-1][P[i-1][v]];
    for(ll u : adj[v]) if(u!=p) dfs(u,v);
    fn[v]=t;
}
ll lca(ll v, ll u){
    if(h[v]>h[u]) swap(v,u);
    for(ll i=LN; i--; ) if(h[v]<=h[P[i][u]]) u=P[i][u];
    if(v==u) return v;
    for(ll i=LN; i--; ) if(P[i][v]!=P[i][u]) v=P[i][v],u=P[i][u];
    return P[0][v];
}
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i<n; i++){
        ll v,u;
        cin >> v >> u;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    dfs(1);
    cin >> q;
    while(q--){
        ll x,y;
        vector<ll> vr,s;
        cin >> x >> y;
        for(ll i=1; i<=x; i++){
            cin >> vi[i] >> sp[i];
            vr.pb(vi[i]);
        }
        for(ll i=1; i<=y; i++){
            cin >> m[i];
            vr.pb(m[i]);
        }
        sort(vr.begin(),vr.end(),cmp);
        for(ll i=1; i<x+y; i++) vr.pb(lca(vr[i-1],vr[i]));
        sort(vr.begin(),vr.end());
        vr.resize(unique(vr.begin(),vr.end())-vr.begin());
        sort(vr.begin(),vr.end(),cmp);
        for(ll v : vr) adj[v].clear();
        s.pb(vr[0]);
        d[vr[0]]={inf,inf};
        for(ll i=1; i<vr.size(); i++){
            ll v=vr[i];
            d[v]=d[vr[0]];
            while(st[v]>fn[s.back()]) s.pop_back();
            adj[s.back()].pb(v);
            adj[v].pb(s.back());
            s.pb(v);
        }
        priority_queue<pair<pll,ll>,vector<pair<pll,ll>>,greater<pair<pll,ll>>> pq;
        for(ll i=1; i<=x; i++){
            d[vi[i]]={0,i};
            wtf[vi[i]]=0;
            pq.push({d[vi[i]],vi[i]});
        }
        while(!pq.empty()){
            auto [di,v]=pq.top();
            pq.pop();
            if(d[v]!=di) continue;
            for(ll u : adj[v]){
                ll wt=wtf[v]+abs(h[v]-h[u]);
                pll w={(wt+sp[di.S]-1)/sp[di.S],di.S};
                if(w<d[u]){
                    d[u]=w;
                    wtf[u]=wt;
                    pq.push({d[u],u});
                }
            }
        }
        for(ll i=1; i<=y; i++) cout << d[m[i]].S << ' ';
        cout << '\n';
    }
    return 0;
}