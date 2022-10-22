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
const int N=1e5+10,LN=20,M=2e7+10,SQ=350,B=737,inf=1e9;
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
ll n,m,a[N],lz[N*4];
vector<ll> vec={4,7,44,47,74,77,444,447,474,477,744,747,774,777,4444,4447,4474,4477,4744,4747,4774,4777,7444,7447,7474,7477,7744,7747,7774,7777,44444};
struct node{
    ll m,c,i;
} f[N*4];
node operator+(node a, node b){
    node ans;
    if(a.m>b.m){
        ans=b;
    }else{
        ans=a;
        if(a.m==b.m) ans.c+=b.c;
    }
    return ans;
}
void build(ll v, ll l, ll r){
    if(r-l==1){
        ll x=*lower_bound(vec.begin(),vec.end(),a[l]);
        f[v].m=x-a[l];
        a[l]=x;
        f[v].c=1;
        f[v].i=l;
        return;
    }
    ll m=(l+r)>>1;
    build(lc,l,m);
    build(rc,m,r);
    f[v]=f[lc]+f[rc];
}
void shift(ll v, ll l, ll r){
    f[v].m-=lz[v];
    if(r-l>1){
        lz[lc]+=lz[v];
        lz[rc]+=lz[v];
    }
    lz[v]=0;
}
void upd(ll v, ll l, ll r, ll tl, ll tr, ll x){
    shift(v,l,r);
    if(tl>=r || l>=tr) return;
    if(tl<=l && tr>=r){
        lz[v]+=x;
        return shift(v,l,r);
    }
    ll m=(l+r)>>1;
    upd(lc,l,m,tl,tr,x);
    upd(rc,m,r,tl,tr,x);
    f[v]=f[lc]+f[rc];
}
void update(ll v, ll l, ll r, ll p, ll x){
    shift(v,l,r);
    if(r-l==1){
        f[v].m=x;
        return;
    }
    ll m=(l+r)>>1;
    if(p<m){
        update(lc,l,m,p,x);
        shift(rc,m,r);
    }
    else{
        update(rc,m,r,p,x);
        shift(lc,l,m);
    }
    f[v]=f[lc]+f[rc];
}
node get(ll v, ll l, ll r, ll tl, ll tr){
    shift(v,l,r);
    if(tl>=r || l>=tr) return f[0];
    if(l>=tl && r<=tr) return f[v];
    ll m=(l+r)>>1;
    return get(lc,l,m,tl,tr)+get(rc,m,r,tl,tr);
}
int main(){
    fast_io;
    cin >> n >> m;
    f[0].m=1;
    for(int i=1; i<=n; i++) cin >> a[i];
    build(1,1,n+1);
    while(m--){
        string s;
        cin >> s;
        if(s[0]=='c'){
            ll l,r;
            cin >> l >> r;
            node x=get(1,1,n+1,l,r+1);
            if(x.m==0) cout << x.c << '\n';
            else cout << 0 << '\n';
        }else{
            ll l,r,x,y;
            cin >> l >> r >> x;
            upd(1,1,n+1,l,r+1,x);
            while(f[1].m<0){
                ll i=f[1].i;
                a[i]-=f[1].m;
                y=*lower_bound(vec.begin(),vec.end(),a[i]);
                update(1,1,n+1,i,y-a[i]);
                a[i]=y;
            }
        }
    }
    return 0;
}