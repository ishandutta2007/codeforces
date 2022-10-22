#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
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
const int N=1.5e5+10,LN=18,M=2e4+10,SQ=500,B=737,inf=1e9;
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
ll n,q,st[N],fn[N],t,sz[N],ans,f[N],iv[N],hv[N],up[N],a[N],P[N];
vector<ll> adj[N];
void sfd(ll v, ll p=0){
    sz[v]=1;
    for(ll u : adj[v]){
        if(u!=p){
            sfd(u,v);
            sz[v]+=sz[u];
            if(sz[u]>sz[hv[v]]) hv[v]=u;
        }
    }
}
void dfs(ll v, ll p=0){
    P[v]=p;
    st[v]=++t;
    for(ll u : adj[v]){
        if(u!=p){
            if(hv[v]==u) up[u]=up[v];
            else up[u]=u;
            dfs(u,v);
        }
    }
    fn[v]=t;
}
void upd(ll t, ll x){
    while(t<N){
        f[t]=(f[t]+x)%MD;
        t+=t&-t;
    }
}
ll get(ll t, ll x=0){
    while(t){
        x=(x+f[t])%MD;
        t-=t&-t;
    }
    return x;
}
int main(){
    fast_io;
    cin >> n >> q;
    for(ll i=1; i<n; i++){
        ll v,u;
        cin >> v >> u;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    sfd(1);
    dfs(1);
    for(ll i=0; i<=n; i++) iv[i]=pow(i,MD-2,MD);
    for(ll g=1; g<=q; g++){
        ll c,v;
        cin >> c >> v;
        if(c==1){
            ll d;
            cin >> d;
            ans=(ans+d*n)%MD;
            a[v]+=d;
            upd(1,(n-sz[v])*d%MD);
            upd(st[v],-((n-sz[v])*d%MD)+MD);
            upd(fn[v]+1,(n-sz[v])*d%MD);
            if(hv[v]){
                ll u=hv[v];
                upd(st[u],sz[u]*d%MD);
                upd(fn[u]+1,MD-sz[u]*d%MD);
            }
        }else{
            ll an=(ans-get(st[v])+MD)%MD;
            v=up[v];
            while(v){
                an=(an+MD-sz[v]*a[P[v]]%MD)%MD;
                v=up[P[v]];
            }
            cout << an*iv[n]%MD << '\n';
        }
    }
    return 0;
}