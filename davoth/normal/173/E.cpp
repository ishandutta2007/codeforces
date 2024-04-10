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
const int N=1e5+10,LN=20,M=2e4+10,SQ=350,B=737,inf=1e9;
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
ll n,a[N],b[N],g[N],c[N],k,q,L[N],R[N],f[N*4],ans[N],w;
void upd(ll t, ll x){
    while(t<N){
        g[t]+=x;
        t+=t&-t;
    }
}
ll gt(ll t, ll x=0){
    while(t){
        x+=g[t];
        t-=t&-t;
    }
    return x;
}
void update(ll v, ll l, ll r, ll p, ll x){
    if(r-l==1){
        f[v]=max(f[v],x);
        return;
    }
    ll m=(l+r)>>1;
    if(p<m) update(lc,l,m,p,x);
    else update(rc,m,r,p,x);
    f[v]=max(f[lc],f[rc]);
}
ll get(ll v, ll l, ll r, ll tl, ll tr){
    if(tl>=r || l>=tr) return 0;
    if(l>=tl && r<=tr) return f[v];
    ll m=(l+r)>>1;
    return max(get(lc,l,m,tl,tr),get(rc,m,r,tl,tr));
}
vector<ll> cp,vec[N],qu[N];
int main(){
    fast_io;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        cp.pb(a[i]);
    }
    sort(cp.begin(),cp.end());
    cp.resize(unique(cp.begin(),cp.end())-cp.begin());
    for(int i=1; i<=n; i++){
        a[i]=lower_bound(cp.begin(),cp.end(),a[i])-cp.begin()+1;
        vec[a[i]].pb(i);
    }
    cp={};
    for(int i=1; i<=n; i++){
        cin >> b[i];
        cp.pb(b[i]);
    }
    sort(cp.begin(),cp.end());
    cp.resize(unique(cp.begin(),cp.end())-cp.begin());
    for(int i=1; i<=n; i++){
        b[i]=lower_bound(cp.begin(),cp.end(),b[i])-cp.begin()+1;
    }
    for(int i=1; i<=n; i++){
        for(int j : vec[i]){
            upd(b[j],1);
        }
        for(int j : vec[i]){
            ll l=lower_bound(cp.begin(),cp.end(),cp[b[j]-1]-k)-cp.begin(),r=upper_bound(cp.begin(),cp.end(),cp[b[j]-1]+k)-cp.begin();
            c[j]=gt(r)-gt(l);
        }
    }
    w=cp.size();
    cin >> q;
    for(int i=1; i<=q; i++){
        ll x,y;
        cin >> x >> y;
        qu[max(a[x],a[y])].pb(i);
        L[i]=cp[max(b[x],b[y])-1]-k;
        R[i]=cp[min(b[x],b[y])-1]+k;
        L[i]=lower_bound(cp.begin(),cp.end(),L[i])-cp.begin()+1;
        R[i]=upper_bound(cp.begin(),cp.end(),R[i])-cp.begin();
    }
    for(int t=N; t--; ){
        for(int i : vec[t]){
            update(1,1,w+1,b[i],c[i]);
        }
        for(int i : qu[t]){
            ans[i]=get(1,1,w+1,L[i],R[i]+1);
            if(!ans[i]) ans[i]=-1;
        }
    }
    for(int i=1; i<=q; i++) cout << ans[i] << '\n';
    return 0;
}