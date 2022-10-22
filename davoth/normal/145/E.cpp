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
const int N=1e6+10,LN=20,M=1e4+0,SQ=350,B=737,inf=1e9;
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
struct node{
    ll x,y,a,b;
} f[N*4];
node operator+(node a, node b){
    node ans;
    ans.a=a.a+b.a;
    ans.b=a.b+b.b;
    ans.x=max(a.a+b.x,a.x+b.b);
    ans.y=max(a.b+b.y,a.y+b.a);
    return ans;
}
ll n,q,lz[N*4],a[N];
string s;
void build(ll v, ll l, ll r){
    if(r-l==1){
        f[v].a=1-a[l];
        f[v].b=a[l];
        f[v].x=f[v].y=1;
        return;
    }
    ll m=(l+r)>>1;
    build(lc,l,m);
    build(rc,m,r);
    f[v]=f[lc]+f[rc];
}
void shift(ll v, ll l, ll r){
    if(lz[v]==0) return;
    lz[v]=0;
    swap(f[v].a,f[v].b);
    swap(f[v].x,f[v].y);
    if(r-l>1){
        lz[lc]^=1;
        lz[rc]^=1;
    }
}
void upd(ll v, ll l, ll r, ll tl, ll tr){
    shift(v,l,r);
    if(tl>=r || l>=tr) return;
    if(l>=tl && r<=tr){
        lz[v]=1;
        return shift(v,l,r);
    }
    ll m=(l+r)>>1;
    upd(lc,l,m,tl,tr);
    upd(rc,m,r,tl,tr);
    f[v]=f[lc]+f[rc];
}
int main(){
    fast_io;
    cin >> n >> q >> s;
    for(int i=0; i<n; i++) a[i+1]=(s[i]=='7');
    build(1,1,n+1);
    while(q--){
        cin >> s;
        if(s[0]=='c') cout << f[1].x << '\n';
        else{
            ll l,r;
            cin >> l >> r;
            upd(1,1,n+1,l,r+1);
        }
    }
    return 0;
}