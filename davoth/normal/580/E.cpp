#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10,LN=30,SQ=550,M=1e6+10;
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
string s;
ll n,m=1000696969,b=737,f[10][N*4],p[N],a[N],g[N],lz[10][N*4],q,q1;
void build(ll c, ll v, ll l, ll r){
    if(r-l<=1){
        if(a[l]==c) f[c][v]=1;
        return;
    }
    ll md=(l+r)/2;
    build(c,v*2,l,md);
    build(c,v*2+1,md,r);
    f[c][v]=(f[c][v*2]*p[r-md]+f[c][v*2+1])%m;
}
void shift(ll c, ll v, ll l, ll r){
    if(lz[c][v]==-1) return;
    lz[c][v*2]=lz[c][v*2+1]=lz[c][v];
    ll md=(l+r)/2;
    f[c][v*2]=g[md-l]*lz[c][v];
    f[c][v*2+1]=g[r-md]*lz[c][v];
    lz[c][v]=-1;
}
void update(ll c, ll v, ll l, ll r, ll tl, ll tr, ll x){
    if(tl>=tr) return;
    if(tl==l && tr==r){
        f[c][v]=g[r-l]*x;
        lz[c][v]=x;
        return;
    }
    shift(c,v,l,r);
    ll md=(l+r)/2;
    update(c,v*2,l,md,tl,min(md,tr),x);
    update(c,v*2+1,md,r,max(tl,md),tr,x);
    f[c][v]=(f[c][v*2]*p[r-md]+f[c][v*2+1])%m;
}
ll get(ll c, ll v, ll l, ll r, ll tl, ll tr){
    if(tl>=tr) return 0;
    if(tl==l && tr==r) return f[c][v];
    shift(c,v,l,r);
    ll md=(l+r)/2;
    if(tr<md) return get(c,v*2,l,md,tl,tr);
    if(tl>=md) return get(c,v*2+1,md,r,tl,tr);
    return (get(c,v*2,l,md,tl,md)*p[tr-md]+get(c,v*2+1,md,r,md,tr))%m;
}
int main(){
    fast_io;
    cin >> n >> q >> q1 >> s;
    q+=q1;
    memset(lz,-1,sizeof lz);
    for(ll i=1; i<=n; i++) a[i]=s[i-1]-'0';
    p[0]=1;
    g[0]=0;
    for(ll i=1; i<N; i++) p[i]=p[i-1]*b%m,g[i]=(g[i-1]*b+1)%m;
    for(ll i=0; i<10; i++) build(i,1,1,n+1);
    while(q--){
        ll t,l,r,c;
        cin >> t >> l >> r >> c;
        if(t==1){
            for(ll i=0; i<10; i++){
                if(i==c) update(i,1,1,n+1,l,r+1,1);
                else update(i,1,1,n+1,l,r+1,0);
            }
        }else{
            bool d=1;
            ll tr=r-(r-l+1)%c,tc=(r-l+1)%c;
            for(ll i=0; i<10; i++){
                d&=get(i,1,1,n+1,l,tr+1-c)==get(i,1,1,n+1,l+c,tr+1);
                d&=get(i,1,1,n+1,l,l+tc)==get(i,1,1,n+1,tr+1,r+1);
            }
            if(d) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}