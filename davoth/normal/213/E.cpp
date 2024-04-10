#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
//#pragma GCC optimize("O2")
/*#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10,LN=20,M=1.1e7+10,SQ=350,B=737373,inf=1e9;
const ll INF=1e18;
const int MH=1000696969,MOD=1000000007  /*998244353*/;
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
ll n,m,ans,a[N],b[N],p[N],f[N*4],g[N*4],t,h,P[N];
void merge(ll v){
    g[v]=g[lc]+g[rc];
    f[v]=(f[rc]+f[lc]*p[g[rc]])%MH;
}
void upd(ll v, ll l, ll r, ll p){
    if(r-l==1){
        g[v]^=1;
        f[v]=0;
        if(g[v]) f[v]=b[l];
        return;
    }
    ll m=(l+r)>>1;
    if(p<m) upd(lc,l,m,p);
    else upd(rc,m,r,p);
    merge(v);
}
int main(){
    fast_io;
    cin >> n >> m;
    p[0]=1;
    for(ll i=1; i<N; i++) p[i]=p[i-1]*B%MH;
    for(ll i=1; i<=n; i++){
        cin >> a[i];
        h=(h*B+a[i])%MH,t=(t*B+1)%MH;
    }
    for(ll i=1; i<=m; i++){
        cin >> b[i];
        P[b[i]]=i;
    }
    for(ll i=1; i<n; i++) upd(1,1,m+1,P[i]);
    for(ll i=n; i<=m; i++){
        upd(1,1,m+1,P[i]);
        if(f[1]==((i-n)*t+h)%MH) ans++;
        upd(1,1,m+1,P[i-n+1]);
    }
    cout << ans << '\n';
    return 0;
}