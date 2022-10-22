#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1.5e4+10,LN=20,M=3e4+10,SQ=450,inf=1e9;
const ll INF=1e18;
const int MH=1000696969,MOD=1000000007 /*998244353*/;
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
ll n,k,q,a[N],b[N],l[N],r[N],dp[1010],P[1010],Q=1e9+7,B=1e7+19;
bool qu[M];
vector<ll> f[4*M];
void upd(ll v, ll l, ll r, ll tl, ll tr, ll x){
    if(tl>=tr) return;
    if(tl==l && tr==r){
        f[v].pb(x);
        return;
    }
    ll m=(l+r)>>1;
    upd(lc,l,m,tl,min(m,tr),x);
    upd(rc,m,r,max(m,tl),tr,x);
}
void solve(ll v, ll l, ll r){
    ll tmp[1010];
    for(ll i=0; i<=k; i++) tmp[i]=dp[i];
    for(ll i : f[v]){
        for(ll j=k; j>=b[i]; j--) dp[j]=max(dp[j],dp[j-b[i]]+a[i]);
    }
    if(r-l==1){
        if(qu[l]){
            ll ans=0,t=dp[0];
            for(ll i=1; i<=k; i++){
                t=max(t,dp[i]);
                ans=(ans+t*P[i-1])%Q;
            }
            cout << ans << '\n';
        }
    }else{
        ll m=(l+r)>>1;
        solve(lc,l,m);
        solve(rc,m,r);
    }
    for(ll i=0; i<=k; i++) dp[i]=tmp[i];
}
int main(){
    fast_io;
    cin >> n >> k;
    P[0]=1;
    for(ll i=1; i<=k; i++) P[i]=P[i-1]*B%Q;
    for(ll i=1; i<=n; i++){
        cin >> a[i] >> b[i];
        l[i]=0;
    }
    cin >> q;
    for(ll i=1; i<=n; i++) r[i]=q+1;
    for(ll i=1; i<=q; i++){
        ll t;
        cin >> t;
        if(t==1){
            n++;
            cin >> a[n] >> b[n];
            l[n]=i;
            r[n]=q+1;
        }
        if(t==2){
            ll x;
            cin >> x;
            r[x]=i;
        }
        if(t==3) qu[i]=1;
    }
    for(ll i=1; i<=n; i++) upd(1,0,q+1,l[i],r[i],i);
    solve(1,0,q+1);
    return 0;
}