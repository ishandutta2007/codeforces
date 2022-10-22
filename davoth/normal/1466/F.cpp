#include <bits/stdc++.h>
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=5e5+10,LN=60,SQ=550,M=5e4+10;
const ll INF=2e18;
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
ll n,m,c,an=1,p[N],sz[N];
bool r[N];
vector<pair<pll,ll>> ed;
vector<ll> ans;
ll gp(ll x){
    return p[x] ? p[x]=gp(p[x]) : x;
}
bool uni(ll v, ll u){
    v=gp(v);
    u=gp(u);
    if(v==u || (r[v] && r[u])) return false;
    if(sz[v]<sz[u]) swap(v,u);
    p[u]=v;
    r[v]|=r[u];
    sz[v]+=sz[u];
    return true;
}
int main(){
    fast_io;
    cin >> m >> n;
    for(ll i=0; i<m; i++){
        ll k;
        cin >> k;
        if(k==1){
            ll x;
            cin >> x;
            ed.pb({{x,-1},i+1});
        }else{
            ll v,u;
            cin >> v >> u;
            ed.pb({{v,u},i+1});
        }
    }
    for(ll i=1; i<=n; i++) sz[i]=1;
    for(auto [P,i] : ed){
        auto [v,u]=P;
        if(u==-1 && !r[gp(v)]) r[gp(v)]=1,ans.pb(i);
        else if(u!=-1 && uni(v,u)) ans.pb(i);
    }
    for(ll i=1; i<=n; i++){
        if(gp(i)==i){
            if(r[i]) an=an*pow(2,sz[i],MOD)%MOD;
            else an=an*pow(2,sz[i]-1,MOD)%MOD;
        }
    }
    cout << an << ' ' << ans.size() << '\n';
    for(ll i : ans) cout << i << ' ';
    cout << '\n';
    return 0;
}