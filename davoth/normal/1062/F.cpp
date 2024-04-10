#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=3e5+10,LN=20,M=1e5+10,SQ=250,inf=1e9;
const ll INF=1e18;
const int MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,m,f[N],t,p[N],mi[2][N],ma[2][N];
vector<ll> out[N],in[N],tp,ans,c[N];
void dfs(ll v){
    f[v]=1;
    for(ll u : out[v]){
        if(!f[u]) dfs(u);
    }
    tp.pb(v);
}
void sfd(ll v, ll s){
    f[v]=s;
    c[s].pb(v);
    for(ll u : in[v]){
        if(!f[u]) sfd(u,s);
    }
}
int main(){
    fast_io;
    cin >> n >> m;
    for(ll i=1; i<=m; i++){
        ll v,u;
        cin >> v >> u;
        out[v].pb(u);
        in[u].pb(v);
    }
    for(ll i=1; i<=n; i++){
        if(!f[i]) dfs(i);
    }
    reverse(tp.begin(),tp.end());
    memset(f,0,sizeof f);
    for(ll i : tp) if(!f[i]) sfd(i,++t);
    for(ll i=1; i<=t; i++){
        mi[0][i]=mi[1][i]=t+1;
        for(ll j : c[i]){
            for(ll k : out[j]){
                if(f[j]==f[k]) continue;
                if(f[k]<mi[1][i]) mi[1][i]=f[k];
                if(mi[1][i]<mi[0][i]) swap(mi[1][i],mi[0][i]);
            }
            for(ll k : in[j]){
                if(f[j]==f[k]) continue;
                if(f[k]>ma[1][i]) ma[1][i]=f[k];
                if(ma[1][i]>ma[0][i]) swap(ma[1][i],ma[0][i]);
            }
        }
    }
    for(ll i=1; i<=t; i++){
        //cout << i << ' ' << mi[0][i] << ' ' << mi[1][i] << ' ' << ma[0][i] << ' ' << ma[1][i] << '\n';
        p[ma[0][i]+1]++;
        p[i]--;
        p[i+1]++;
        p[mi[0][i]]--;
        if(mi[0][i]<=t){
            p[mi[0][i]+1]++;
            p[min(mi[1][i],mi[0][mi[0][i]])]--;
        }
        if(ma[0][i]){
            p[max(ma[1][i],ma[0][ma[0][i]])+1]++;
            p[ma[0][i]]--;
        }
    }
    for(ll i=1; i<=t; i++){
        p[i]+=p[i-1];
        if(p[i]<2) for(ll j : c[i]) ans.pb(j);
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << '\n';
    /*for(ll i : ans) cout << i << ' ';
    cout << '\n';*/
    return 0;
}