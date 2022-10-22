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
const int N=2e5+10,LN=20,M=2e4+10,SQ=350,B=737,inf=1e9;
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
ll n,q,a[N],b[N],m;
pair<ll,pll> qu[N];
vector<ll> cp;
struct node{
    ll c,s,ans;
} f[N*4];
node operator+(node a, node b){
    node c;
    c.c=a.c+b.c;
    c.s=a.s+b.s;
    c.ans=a.ans+b.ans+b.s*a.c-a.s*b.c;
    return c;
}
void build(ll v, ll l, ll r){
    if(r-l==1){
        f[v].s=cp[l]*b[l];
        f[v].c=b[l];
        return;
    }
    ll m=(l+r)>>1;
    build(lc,l,m);
    build(rc,m,r);
    f[v]=f[lc]+f[rc];
}
void upd(ll v, ll l, ll r, ll p){
    if(r-l==1){
        f[v].s=cp[l]*b[l];
        f[v].c=b[l];
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
    for(int i=1; i<=n; i++){
        cin >> a[i];
        b[i]=a[i];
        cp.pb(a[i]);
    }
    cin >> q;
    for(int i=1; i<=q; i++){
        ll t,x,y;
        cin >> t >> x >> y;
        if(t==1){
            b[x]+=y;
            cp.pb(b[x]);
            y=b[x];
        }
        qu[i]={t,{x,y}};
    }
    sort(cp.begin(),cp.end());
    cp.resize(unique(cp.begin(),cp.end())-cp.begin());
    m=cp.size();
    for(int i=0; i<m; i++) b[i]=0;
    for(int i=1; i<=n; i++){
        a[i]=lower_bound(cp.begin(),cp.end(),a[i])-cp.begin();
        b[a[i]]++;
    }
    build(1,0,m);
    for(int i=1; i<=q; i++){
        ll t=qu[i].F,x=qu[i].S.F,y=qu[i].S.S;
        if(t==1){
            b[a[x]]--;
            upd(1,0,m,a[x]);
            a[x]=lower_bound(cp.begin(),cp.end(),y)-cp.begin();
            b[a[x]]++;
            upd(1,0,m,a[x]);
        }else{
            x=lower_bound(cp.begin(),cp.end(),x)-cp.begin();
            y=upper_bound(cp.begin(),cp.end(),y)-cp.begin();
            cout << get(1,0,m,x,y).ans << '\n';
        }
    }
    return 0;
}