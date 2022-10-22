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
const int N=2e5+10,LN=60,M=4e6+10,SQ=500,BS=737,inf=1.05e9,NSQ=N/SQ+1;
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
ll n,m,f[N],h[N],dp[N],t,hd[N],r;
vector<ll> adj[N],cp[N],ad[N],cy,ls,pt;
void sfd(ll v){
    hd[v]=1;
    cp[t].pb(v);
    for(ll u : adj[v]){
        if(h[u]>h[v] && !hd[u]) sfd(u);
    }
}
void dfs(ll v){
    f[v]=1;
    dp[v]=h[v];
    vector<ll> tp;
    for(ll u : adj[v]){
        if(f[u]){
            dp[v]=min(dp[v],h[u]);
            continue;
        }
        tp.pb(u);
        h[u]=h[v]+1;
        dfs(u);
        dp[v]=min(dp[v],dp[u]);
        if(dp[u]>=h[v] && v!=r){
            cp[++t].pb(v);
            sfd(u);
        }
    }
    if(v==r){
        for(ll u : tp){
            cp[++t].pb(v);
            sfd(u);
        }
    }
}
void DFS(ll v, ll p=0){
    f[v]=1;
    ls.pb(v);
    for(ll u : ad[v]){
        if(u==p) continue;
        if(!cy.empty()) return;
        if(!f[u]) DFS(u,v);
        else{
            while(ls.back()!=u){
                cy.pb(ls.back());
                ls.pop_back();
            }
            cy.pb(u);
        }
    }
}
void SFD(ll v){
    hd[v]=1;
    pt.pb(v);
    if(f[v]) return;
    for(ll u : ad[v]){
        if(u==r) continue;
        if(!hd[u]) SFD(u);
        if(pt.back()!=v) return;
    }
    pt.pop_back();
}
int main(){
    fast_io;
    cin >> n >> m;
    for(ll i=1; i<=m; i++){
        ll v, u;
        cin >> v >> u;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    for(ll i=1; i<=n; i++) if(!f[i]) dfs(r=i);
    memset(f,0,sizeof f);
    memset(hd,0,sizeof hd);
    for(ll i=1; i<=t; i++){
        ll sz=cp[i].size();
        if(sz<3) continue;
        f[cp[i][0]]=1;
        ad[cp[i][0]].clear();
        for(ll j=1; j<sz; j++){
            ad[cp[i][j]].clear();
            f[cp[i][j]]=1;
            for(ll u : adj[cp[i][j]]){
                if(f[u]){
                    ad[u].pb(cp[i][j]);
                    ad[cp[i][j]].pb(u);
                }
            }
        }
        cy.clear();
        ls.clear();
        for(ll v : cp[i]) f[v]=0;
        DFS(cp[i][0]);
        for(ll v : cp[i]) f[v]=0;
        for(ll v : cy){
            f[v]=1;
        }
        ll s=cy.size();
        for(ll j=0; j<s; j++){
            ll v=cy[j];
            if((ll)ad[v].size()==2 || !pt.empty()) continue;
            ll pv=cy[(j+s-1)%s],nx=cy[(j+1)%s];
            r=v;
            pt.pb(v);
            for(ll u : ad[v]){
                if(u!=pv && u!=nx){
                    SFD(u);
                    break;
                }
            }
        }
        for(ll v : cp[i]) hd[v]=f[v]=0;
        if(pt.empty()) continue;
        ll v=pt[0],u=pt.back(),x,y;
        for(ll j=0; j<s; j++){
            if(cy[j]==v) x=j;
            if(cy[j]==u) y=j;
        }
        vector<ll> t1,t2;
        if(x>y){
            reverse(pt.begin(),pt.end());
            swap(x,y);
        }
        for(ll j=x; j<=y; j++) t1.pb(cy[j]);
        for(ll j=x; j>=0; j--) t2.pb(cy[j]);
        for(ll j=s-1; j>=y; j--) t2.pb(cy[j]);
        cout << "YES\n";
        cout << pt.size() << ' ';
        for(ll j : pt) cout << j << ' ';
        cout << '\n' << t1.size() << ' ';
        for(ll j : t1) cout << j << ' ';
        cout << '\n' << t2.size() << ' ';
        for(ll j : t2) cout << j << ' ';
        cout << '\n';
        return 0;
    }
    cout << "NO\n";
    return 0;
}