#include <bits/stdc++.h>
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e5+10,LN=20,SQ=550,M=1e1+10;
const ll INF=1e18;
const int MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<pair<pll,ll>, null_type,less<pair<pll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,m,q,col[M][N],p[50],cnt[50];
ll gp(ll x){
    return p[x]?gp(p[x]):x;
}
struct node{
    ll c[2*M],l,r,s;
    node operator+(node x){
        node ans;
        ans.l=l;
        ans.r=x.r;
        ans.s=s+x.s;
        memset(p,0,sizeof p);
        memset(cnt,0,sizeof cnt);
        for(ll i=1; i<=n; i++){
            if(col[i][r-1]==col[i][x.l]){
                ll tl=gp(c[n+i]),tr=gp(2*n+x.c[i]);
                if(tl==tr) continue;
                ans.s--;
                p[tl]=tr;
            }
        }
        for(ll i=1; i<=n; i++){
            cnt[gp(c[i])]=1;
            cnt[gp(n*2+x.c[n+i])]=1;
        }
        for(ll i=2; i<=4*n; i++) cnt[i]+=cnt[i-1];
        for(ll i=1; i<=n; i++){
            ans.c[i]=cnt[gp(c[i])];
            ans.c[n+i]=cnt[gp(n*2+x.c[n+i])];
        }
        return ans;
    }
} f[N*4];
void build(ll v, ll l, ll r){
    if(r-l==1){
        for(ll i=1; i<=n; i++){
            if(col[i][l]!=col[i-1][l]){
                f[v].c[i]=f[v].c[i-1]+1;
                f[v].s++;
            }else f[v].c[i]=f[v].c[i-1];
        }
        for(ll i=n+1; i<=2*n; i++) f[v].c[i]=f[v].c[i-n];
        f[v].l=l;
        f[v].r=r;
        return;
    }
    ll m=(l+r)/2;
    build(v*2,l,m);
    build(v*2+1,m,r);
    f[v]=f[v*2]+f[v*2+1];
}
node get(ll v, ll l, ll r, ll tl, ll tr){
    if(tr==r && tl==l) return f[v];
    ll m=(l+r)/2;
    if(tr<=m) return get(v*2,l,m,tl,tr);
    if(tl>=m) return get(v*2+1,m,r,tl,tr);
    return get(v*2,l,m,tl,m)+get(v*2+1,m,r,m,tr);
}
int main(){
    fast_io;
    cin >> n >> m >> q;
    for(ll i=1; i<=n; i++) for(ll j=1; j<=m; j++) cin >> col[i][j];
    build(1,1,m+1);
    while(q--){
        ll l,r;
        cin >> l >> r;
        cout << get(1,1,m+1,l,r+1).s << '\n';
    }
    return 0;
}