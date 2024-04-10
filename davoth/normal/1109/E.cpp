#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#pragma GCC optimize("O2")
/*#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e5+10,LN=20,M=5e1+1,SQ=600,inf=1e9;
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
ll n,mod,f[15][N],g[N*4],b[N*4],lz[N*4];
vector<ll> pr;
void up(ll c, ll p, ll x){
    while(p<N) f[c][p]+=x,p+=p&-p;
}
ll gt(ll c, ll p, ll x=0){
    while(p) x+=f[c][p],p-=p&-p;
    return x;
}
void upd(ll v, ll l, ll r, ll tl, ll tr, ll x){
    if(tl>=tr) return;
    if(tl==l && tr==r){
        g[v]=g[v]*x%mod;
        return;
    }
    ll m=(l+r)>>1;
    upd(lc,l,m,tl,min(m,tr),x);
    upd(rc,m,r,max(m,tl),tr,x);
}
ll get(ll v, ll l, ll r, ll p){
    if(r-l==1) return g[v];
    ll m=(l+r)>>1;
    if(p<m) return g[v]*get(lc,l,m,p)%mod;
    else return g[v]*get(rc,m,r,p)%mod;
}
void build(ll v, ll l, ll r){
    lz[v]=1;
    if(r-l==1){
        b[v]=1;
        return;
    }
    ll m=(l+r)>>1;
    build(lc,l,m);
    build(rc,m,r);
    b[v]=(b[lc]+b[rc])%mod;
}
void shift(ll v, ll l, ll r){
    b[v]=b[v]*lz[v]%mod;
    if(r-l>1){
        lz[lc]=lz[lc]*lz[v]%mod;
        lz[rc]=lz[rc]*lz[v]%mod;
    }
    lz[v]=1;
}
void rupd(ll v, ll l, ll r, ll tl, ll tr, ll x){
    shift(v,l,r);
    if(tl>=tr) return;
    if(tl==l && tr==r){
        lz[v]=lz[v]*x%mod;
        return shift(v,l,r);
    }
    ll m=(l+r)>>1;
    rupd(lc,l,m,tl,min(m,tr),x);
    rupd(rc,m,r,max(m,tl),tr,x);
    b[v]=(b[lc]+b[rc])%mod;
}
void pupd(ll v, ll l, ll r, ll p, ll x){
    shift(v,l,r);
    if(r-l==1){
        b[v]=x%mod;
        return;
    }
    ll m=(l+r)>>1;
    shift(lc,l,m);
    shift(rc,m,r);
    if(p<m) pupd(lc,l,m,p,x);
    else pupd(rc,m,r,p,x);
    b[v]=(b[lc]+b[rc])%mod;
}
ll Get(ll v, ll l, ll r, ll tl, ll tr){
    shift(v,l,r);
    if(tl>=tr) return 0;
    if(tl==l && tr==r) return b[v];
    ll m=(l+r)>>1;
    return (Get(lc,l,m,tl,min(m,tr))+Get(rc,m,r,max(m,tl),tr))%mod;
}
int main(){
    fast_io;
    cin >> n >> mod;
    ll t=mod,fi=mod;
    for(ll i=2; i*i<=mod; i++){
        if(t%i==0){
            pr.pb(i);
            while(t%i==0) t/=i;
            fi/=i;
            fi*=(i-1);
        }
    }
    if(t>1){
        fi/=t;
        fi*=t-1;
        pr.pb(t);
    }
    build(1,1,n+1);
    fill(g,g+N*4,1);
    for(ll i=1; i<=n; i++){
        ll t;
        cin >> t;
        pupd(1,1,n+1,i,t);
        for(ll j=0; j<pr.size(); j++){
            ll k=0;
            while(t%pr[j]==0){
                k++;
                t/=pr[j];
            }
            up(j,i,k);
            up(j,i+1,-k);
        }
        upd(1,1,n+1,i,i+1,t);
    }
    ll q;
    cin >> q;
    while(q--){
        ll t;
        cin >> t;
        if(t==3){
            ll l,r;
            cin >> l >> r;
            cout << Get(1,1,n+1,l,r+1) << '\n';
        }else if(t==1){
            ll l,r,x;
            cin >> l >> r >> x;
            rupd(1,1,n+1,l,r+1,x);
            for(ll i=0; i<pr.size(); i++){
                ll k=0;
                while(x%pr[i]==0) k++,x/=pr[i];
                up(i,l,k);
                up(i,r+1,-k);
            }
            upd(1,1,n+1,l,r+1,x);
        }else{
            ll p,x;
            cin >> p >> x;
            for(ll i=0; i<pr.size(); i++){
                ll k=0;
                while(x%pr[i]==0) k++,x/=pr[i];
                up(i,p,-k);
                up(i,p+1,k);
            }
            x=pow(x,fi-1,mod);
            upd(1,1,n+1,p,p+1,x);
            x=get(1,1,n+1,p);
            for(ll i=0; i<pr.size(); i++){
                x=x*pow(pr[i],gt(i,p),mod)%mod;
            }
            pupd(1,1,n+1,p,x);
        }
    }
    return 0;
}