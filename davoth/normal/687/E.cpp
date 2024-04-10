/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
using ld=long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
using point=complex<double>;
#define F first
#define S second
//#define X real()
//#define Y imag()
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define kill(x) cout << x << '\n';exit(0)
#define killshayan kill("done!")
#define killmashtali kill("Hello, World!")
const int N=5e3+10,LN=20,M=4e6+10,SQ=500,BS=737,inf=1.05e9,NSQ=N/SQ+1;
const ll INF=1e18;
const double pi=acos(-1);
const ld ep=1e-7;
const int MH=1000696969,MD=998244353,MOD=1000000007;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pii, null_type,greater<pii>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,m,c[N],f[N],t,ans,d[N];
vector<ll> in[N],out[N],cp[N],tp;
void dfs(ll v){
    f[v]=1;
    for(ll u : out[v]) if(!f[u]) dfs(u);
    tp.pb(v);
}
void sfd(ll v){
    f[v]=1;
    c[v]=t;
    cp[t].pb(v);
    for(ll u : in[v]) if(!f[u]) sfd(u);
}
int main(){
    fast_io;
    cin >> n >> m;
    ans=n;
    for(ll i=1; i<=m; i++){
        ll v,u;
        cin >> v >> u;
        out[v].pb(u);
        in[u].pb(v);
    }
    for(ll i=1; i<=n; i++) if(!f[i]) dfs(i);
    reverse(tp.begin(),tp.end());
    memset(f,0,sizeof f);
    for(ll i : tp){
        if(!f[i]){
            t++;
            sfd(i);
        }
    }
    for(ll i=1; i<=t; i++){
        ll g=0;
        for(ll j : cp[i]){
            for(ll x : out[j]){
                if(c[x]!=i){
                    g=1;
                    break;
                }
            }
        }
        if(g || cp[i].size()==1) continue;
        ans++;
        ll k=inf;
        for(ll j : cp[i]){
            for(ll x : cp[i]) d[x]=inf;
            d[j]=0;
            queue<ll> q;
            q.push(j);
            while(!q.empty()){
                ll v=q.front();
                q.pop();
                for(ll u : out[v]){
                    if(u==j) k=min(d[v]+1,k);
                    if(d[v]+1<d[u]){
                        d[u]=d[v]+1;
                        q.push(u);
                    }
                }
            }
        }
        ans+=k*998;
    }
    cout << ans << '\n';
    return 0;
}