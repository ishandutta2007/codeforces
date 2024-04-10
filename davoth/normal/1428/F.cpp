#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
/*#pragma comment(linker, "/stack:200000000")
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
//#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=5e5+10,LN=20,M=5e6,SQ=350,B=737,inf=1e9+10;
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
ll n,f[N*4],lz[N*4],ans,ls;
string s;
void shift(ll v, ll l, ll r){
    if(lz[v]){
        f[v]+=lz[v]*(r-l);
        if(r-l>1){
            lz[lc]+=lz[v];
            lz[rc]+=lz[v];
        }
        lz[v]=0;
    }
}
void upd(ll v, ll l, ll r, ll tl, ll tr, ll x){
    shift(v,l,r);
    if(tl>=r || l>=tr) return;
    if(l>=tl && r<=tr){
        lz[v]=x;
        return shift(v,l,r);
    }
    ll m=(l+r)>>1;
    upd(lc,l,m,tl,tr,x);
    upd(rc,m,r,tl,tr,x);
    f[v]=f[lc]+f[rc];
}
ll get(ll v, ll l, ll r, ll p){
    shift(v,l,r);
    if(r-l==1) return f[v];
    ll m=(l+r)>>1;
    if(p<m) return get(lc,l,m,p);
    return get(rc,m,r,p);
}
int main(){
    fast_io;
    cin >> n >> s;
    ls=n+1;
    for(ll i=n; i; i--){
        if(s[i-1]=='0') ls=i;
        else{
            ll x=ls-i,l=ls-1,r=n+1;
            while(r-l>1){
                ll m=(l+r)>>1;
                if(get(1,1,n+1,m)<x) l=m;
                else r=m;
            }
            upd(1,1,n+1,i,r,1);
        }
        ans+=f[1];
    }
    cout << ans << '\n';
    return 0;
}