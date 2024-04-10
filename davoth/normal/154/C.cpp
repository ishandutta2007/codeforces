#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e6+10,LN=30,SQ=550,M=1e6+10;
const ll INF=1e16;
const int MOD=1000000007 /*998244353*/;
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
ll n,m,a1[N],a2[N],p1[N],p2[N],b=737,m1=1000696969,m2=MOD,ans;
map<ll,unordered_map<ll,ll>> t;
pll c[N];
int main(){
    fast_io;
    cin >> n >> m;
    p1[0]=p2[0]=1;
    for(ll i=1; i<n; i++) p1[i]=b*p1[i-1]%m1,p2[i]=p2[i-1]*b%m2;
    for(ll i=0; i<m; i++){
        ll v,u;
        cin >> v >> u;
        v--,u--;
        a1[v]+=p1[u];
        a1[u]+=p1[v];
        a1[v]%=m1;
        a1[u]%=m1;
        a2[v]+=p2[u];
        a2[u]+=p2[v];
        a2[v]%=m2;
        a2[u]%=m2;
        c[i].F=v;
        c[i].S=u;
    }
    for(ll i=0; i<n; i++){
        ans+=t[a1[i]][a2[i]];
        t[a1[i]][a2[i]]++;
    }
    for(ll i=0; i<m; i++){
        ll v=c[i].F,u=c[i].S;
        if((a1[v]-p1[u]+m1)%m1==(a1[u]-p1[v]+m1)%m1 && (a2[v]-p2[u]+m2)%m2==(a2[u]-p2[v]+m2)%m2) ans++;
    }
    cout << ans << '\n';
    return 0;
}