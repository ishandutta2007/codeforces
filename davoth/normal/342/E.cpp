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
const int N=1e5+10,LN=19,M=2e4+10,SQ=350,B=737,inf=1e9;
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
ll n,q,h[N],st[N],sp[LN][N*2],d[N];
vector<ll> adj[N],ds,ls={1},rd={1};
queue<ll> qu;
void dfs(ll v, ll p){
    st[v]=ds.size();
    ds.pb(v);
    for(ll u : adj[v]){
        if(u!=p){
            h[u]=h[v]+1;
            dfs(u,v);
            ds.pb(v);
        }
    }
}
ll get(ll l, ll r){
    if(r<l) swap(l,r);
    ll k=63-__builtin_clzll(r-l+1);
    return min(sp[k][l],sp[k][r-(1<<k)+1]);
}
int main(){
    fast_io;
    cin >> n >> q;
    for(int i=1; i<n; i++){
        ll v,u;
        cin >> v >> u;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    h[1]=1;
    dfs(1,0);
    for(ll i=0; i<ds.size(); i++) sp[0][i]=h[ds[i]];
    for(ll i=1; i<LN; i++){
        for(ll j=0; j<ds.size(); j++){
            sp[i][j]=sp[i-1][j];
            if(j+(1<<(i-1))<ds.size()){
                sp[i][j]=min(sp[i][j],sp[i-1][j+(1<<(i-1))]);
            }
        }
    }
    memset(d,63,sizeof d);
    for(int t=1; t<=q; t++){
        if(t%SQ==0){
            ls={};
            memset(d,63,sizeof d);
            for(ll i : rd){
                qu.push(i);
                d[i]=0;
            }
            while(!qu.empty()){
                ll v=qu.front();
                qu.pop();
                for(ll u : adj[v]){
                    if(d[u]>d[v]+1){
                        d[u]=d[v]+1;
                        qu.push(u);
                    }
                }
            }
        }
        ll c,v;
        cin >> c >> v;
        if(c==1){
            rd.pb(v);
            ls.pb(v);
        }else{
            ll ans=d[v];
            for(ll u : ls){
                ll x=get(st[v],st[u]);
                ans=min(ans,h[v]+h[u]-2*x);
            }
            cout << ans << '\n';
        }
    }
    return 0;
}