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
const int N=3e5+10,LN=18,M=1e6+10,SQ=500,B=737,inf=1e9;
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
ll n,q,a[N];
string s;
struct node{
    ll a,b,c,ab,bc,abc,ac;
} f[N*4];
node operator+(node x, node y){
    node z;
    z.a=x.a+y.a;
    z.b=x.b+y.b;
    z.c=x.c+y.c;
    z.ab=min({x.a+y.b,x.ab+y.b,x.a+y.ab});
    z.bc=min({x.b+y.c,x.bc+y.c,x.b+y.bc});
    z.ac=min({x.a+y.c,x.ac+y.c,x.a+y.ac});
    z.abc=min({x.a+y.abc,x.a+y.bc,x.ab+y.bc,x.ab+y.c,x.abc+y.c});
    return z;
}
void build(ll v, ll l, ll r){
    if(r-l==1){
        if(a[l]==1) f[v].a=1;
        if(a[l]==2) f[v].b=1;
        if(a[l]==3) f[v].c=1;
        return;
    }
    ll m=(l+r)>>1;
    build(lc,l,m);
    build(rc,m,r);
    f[v]=f[lc]+f[rc];
}
void upd(ll v, ll l, ll r, ll p, ll x){
    if(r-l==1){
        f[v]=f[0];
        if(x==1) f[v].a=1;
        if(x==2) f[v].b=1;
        if(x==3) f[v].c=1;
        return;
    }
    ll m=(l+r)>>1;
    if(p<m) upd(lc,l,m,p,x);
    else upd(rc,m,r,p,x);
    f[v]=f[lc]+f[rc];
}
int main(){
    fast_io;
    cin >> n >> q >> s;
    for(int i=1; i<=n; i++) a[i]=s[i-1]-'a'+1;
    build(1,1,n+1);
    while(q--){
        ll p;
        char c;
        cin >> p >> c;
        upd(1,1,n+1,p,c-'a'+1);
        cout << min({f[1].a,f[1].b,f[1].c,f[1].ab,f[1].bc,f[1].ac,f[1].abc}) << '\n';
    }
    return 0;
}