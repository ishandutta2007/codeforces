#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
//#pragma GCC optimize("O2")
/*#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
using ld = long double;
#define F first
#define S second
#define pb push_back
//#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=5e5+10,LN=20,M=3.5e7+10,SQ=350,BS=737,inf=1e9+10;
const ll INF=1e18;
const ld ep=1e-7;
const int MH=1000696969,MOD=1000000007,MD=998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
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
ll T,d[N],n,m,f[N],od[N],x,y,c[N],t,td,h[N];
pll ed[N];
vector<ll> adj[N],dfv,ans;
vector<ll> inv(vector<ll> v){
    vector<ll> ans;
    for(ll i=1; i<=n; i++) f[i]=0;
    for(ll i : v) f[i]=1;
    for(ll i=1; i<=n; i++) if(!f[i]) ans.pb(i);
    return ans;
}
void dfc(ll v, ll p){
    if(!ans.empty()) return;
    dfv.pb(v);
    f[v]=1;
    c[v]=t;
    ll mx=-1,my=-1;
    for(ll u : adj[v]){
        if(u!=p && f[u] && d[u]==2){
            if(h[u]>mx) mx=h[u],my=u;
        }
    }
    if(~mx){
        ans=dfv;
        reverse(ans.begin(),ans.end());
        while(ans.back()!=my) ans.pop_back();
    }
    for(ll u : adj[v]) if(d[u]==2 && !f[u]) h[u]=h[v]+1,dfc(u,v);
    dfv.pop_back();
}
void dfp(ll v){
    if(!ans.empty()) return;
    f[v]=1;
    queue<ll> q;
    for(ll u : adj[v]) q.push(u),h[u]=v,f[u]=1;
    while(!q.empty()){
        ll u=q.front();
        q.pop();
        f[u]=1;
        if(d[u]==1){
            ans.pb(u);
            while(u!=v){
                u=h[u];
                ans.pb(u);
            }
            return;
        }
        for(ll i : adj[u]) if(!f[i]) f[i]=1,h[i]=u,q.push(i);
    }
}
void dfs(ll v, ll p){
    ans.pb(v);
    for(ll u : adj[v]){
        if(u==td && u!=p){
            return;
        }
    }
    for(ll u : adj[v]){
        if(u!=p){
            dfs(u,v);
            return;
        }
    }
}
void solve(ll p){
    cin >> n >> m;
    dfv=ans={};
    t=0;
    if(n==1){
        cout << "No\n";
        return;
    }
    x=y=0;
    for(ll i=1; i<=n; i++){
        adj[i]={};
        c[i]=f[i]=od[i]=d[i]=0;
    }
    for(ll i=1; i<=m; i++){
        ll v,u;
        cin >> v >> u;
        ed[i]={v,u};
        adj[v].pb(u);
        adj[u].pb(v);
        od[v]++;
        od[u]++;
    }
    for(ll i=1; i<=n; i++){
        d[i]=od[i]%3;
        if(od[i]==1) x++;
        if(od[i]==2) y++;
        if(!d[i]){
            ans=inv({i});
            cout << "Yes\n" << n-1 << '\n';
            for(ll j : ans) cout << j << ' ';
            cout << '\n';
            return;
        }
    }
    if(y==n || (x==2 && y==n-2)){
        cout << "No\n";
        return;
    }
    fill(f,f+n+1,0);
    for(ll i=1; i<=n; i++){
        if(d[i]==2 && !f[i]){
            dfv={};
            h[i]=0;
            t++;
            dfc(i,0);
        }
    }
    if(!ans.empty()){
        ans=inv(ans);
        //if(p==7310 && T==28303) cout << "Cycle\n";
        cout << "Yes\n" << ans.size() << '\n';
        for(ll i : ans) cout << i << ' ';
        cout << '\n';
        return;
    }
    dfv={};
    fill(f,f+n+1,0);
    for(ll i=1; i<=n; i++){
        if(d[i]==1 && !f[i]){
            td=i;
            dfp(i);
        }
    }
    if(!ans.empty()){
        ans=inv(ans);
        //if(p==7310 && T==28303) cout << "Path\n";
        cout << "Yes\n" << ans.size() << '\n';
        for(ll i : ans) cout << i << ' ';
        cout << '\n';
        return;
    }
    fill(f,f+n+1,0);
    if(od[td]==4 && y==n-1){
        cout << "No\n";
        return;
    }
    ll g=0;
    ans={td};
    for(ll u : adj[td]){
        if(!f[c[u]]){
            dfs(u,td);
            g++;
            f[c[u]]=1;
        }
        if(g==2) break;
    }
    ans=inv(ans);
    //if(p==7310 && T==28303) cout << "Special\n";
    cout << "Yes\n" << ans.size() << '\n';
    for(ll i : ans) cout << i << ' ';
    cout << '\n';
}
int main(){
    fast_io;
    cin >> T;
    for(ll i=1; i<=T; i++){
        solve(i);
    }
    return 0;
}