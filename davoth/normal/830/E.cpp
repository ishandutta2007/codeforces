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
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define kill(x) cout << x << '\n';exit(0)
#define killshayan kill("done!")
#define killmashtali kill("Hello, World!")
const int N=2e5+10,LN=20,M=1e6+10,SQ=700,BS=737,inf=1.05e9,NSQ=N/SQ+3;
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
ll t,n,m,f[N],an[N],ans,mx,h[N],P[N];
vector<ll> adj[N],cp;
ll dfs(ll v, ll p){
    P[v]=p;
    h[v]=h[p]+1;
    if((ll)adj[v].size()>mx){
        mx=adj[v].size();
        cp.clear();
    }
    if(mx==(ll)adj[v].size()) cp.pb(v);
    f[v]=1;
    for(ll u : adj[v]){
        if(u==p) continue;
        if(f[u]){
            ans=1;
            an[v]=1;
            return u;
        }
        ll k=dfs(u,v);
        if(k){
            an[v]=1;
            if(k==v) return 0;
            else return k;
        }
    }
    return 0;
}
void sfd(ll v, ll p){
    h[v]=h[p]+1;
    P[v]=p;
    for(ll u : adj[v]){
        if(u==p) continue;
        sfd(u,v);
    }
    if((ll)adj[v].size()==1) cp.pb(v);
}
void solve(ll v){
    cp.clear();
    mx=0;
    dfs(v,0);
    if(ans==1) return;
    if(mx>=4){
        ans=1;
        an[cp[0]]=2;
        for(ll v : adj[cp[0]]) an[v]=1;
        return;
    }
    if(mx<=2) return;
    if((ll)cp.size()>=2){
        ans=1;
        ll v=cp[0],u=cp[1];
        if(h[u]<h[v]) swap(v,u);
        while(h[u]>h[v]){
            an[u]=2;
            u=P[u];
        }
        while(u!=v){
            an[u]=an[v]=2;
            u=P[u];
            v=P[v];
        }
        an[u]=2;
        for(ll v : adj[cp[0]]) if(!an[v]) an[v]=1;
        for(ll v : adj[cp[1]]) if(!an[v]) an[v]=1;
        return;
    }
    v=cp[0];
    cp.clear();
    sfd(v,0);
    sort(cp.begin(),cp.end(),[&](const ll &a, const ll &b){return h[a]<h[b];});
    if(h[cp[0]]>=3){
        an[v]=3;
        for(ll i=0; i<3; i++){
            while(h[cp[i]]>3) cp[i]=P[cp[i]];
            an[cp[i]]=1;
            an[P[cp[i]]]=2;
        }
        ans=1;
        return;
    }
    if(h[cp[1]]>=4){
        an[v]=4;
        an[cp[0]]=2;
        for(ll i=1; i<3; i++){
            while(h[cp[i]]>4) cp[i]=P[cp[i]];
            an[cp[i]]=1;
            an[P[cp[i]]]=2;
            an[P[P[cp[i]]]]=3;
        }
        ans=1;
        return;
    }
    if(h[cp[1]]==3 && h[cp[2]]>=6){
        an[v]=6;
        an[cp[0]]=3;
        an[cp[1]]=2;
        an[P[cp[1]]]=4;
        v=cp[2];
        while(h[v]>6) v=P[v];
        an[v]=1;
        v=P[v];
        an[v]=2;
        v=P[v];
        an[v]=3;
        v=P[v];
        an[v]=4;
        v=P[v];
        an[v]=5;
        ans=1;
    }
}
int main(){
    fast_io;
    cin >> t;
    while(t--){
        cin >> n >> m;
        ans=0;
        for(ll i=1; i<=n; i++){
            adj[i].clear();
            an[i]=f[i]=0;
        }
        for(ll i=1; i<=m; i++){
            ll v,u;
            cin >> v >> u;
            adj[v].pb(u);
            adj[u].pb(v);
        }
        for(ll i=1; i<=n; i++){
            if(ans) break;
            if(!f[i]) solve(i);
        }
        if(ans){
            cout << "YES\n";
            for(ll i=1; i<=n; i++) cout << an[i] << ' ';
            cout << '\n';
        }else cout << "NO\n";
    }
    return 0;
}