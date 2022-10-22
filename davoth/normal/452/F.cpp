#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
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
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=3e5+10,LN=20,M=1e6+10,SQ=350,B=737,inf=1e9;
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
ll n,p[N],pw[N];
struct node{
    ll sz,h,rh;
} f[N*4];
node operator+(node a, node b){
    node ans;
    ans.sz=a.sz+b.sz;
    ans.h=(a.h*pw[b.sz]+b.h)%MH;
    ans.rh=(b.rh*pw[a.sz]+a.rh)%MH;
    return ans;
}
void build(ll v, ll l, ll r){
    if(r-l==1){
        f[v].sz=1;
        return;
    }
    ll m=(l+r)>>1;
    build(lc,l,m);
    build(rc,m,r);
    f[v]=f[lc]+f[rc];
}
void upd(ll v, ll l, ll r, ll p){
    if(r-l==1){
        f[v].h=f[v].rh=1;
        return;
    }
    ll m=(l+r)>>1;
    if(p<m) upd(lc,l,m,p);
    else upd(rc,m,r,p);
    f[v]=f[lc]+f[rc];
}
node get(ll v, ll l, ll r, ll tl, ll tr){
    if(tl>=r || l>=tr) return f[0];
    if(l>=tl && r<=tr) return f[v];
    ll m=(l+r)>>1;
    return get(lc,l,m,tl,tr)+get(rc,m,r,tl,tr);
}
int main(){
    fast_io;
    cin >> n;
    pw[0]=1;
    for(ll i=1; i<=n; i++) pw[i]=pw[i-1]*B%MH;
    for(ll i=1; i<=n; i++){
        cin >> p[i];
    }
    for(ll i=1; i<=n; i++){
        ll x=min(p[i]-1,n-p[i]);
        if(get(1,1,n+1,p[i]-x,p[i]).h!=get(1,1,n+1,p[i]+1,p[i]+x+1).rh){
            cout << "YES\n";
            return 0;
        }
        upd(1,1,n+1,p[i]);
    }
    cout << "NO\n";
    return 0;
}