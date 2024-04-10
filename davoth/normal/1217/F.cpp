#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
using namespace std;
using ll = /*long long*/ int;
#define F first
#define S second
#define pb push_back
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=4e5+10,LN=20,M=5e1+1,SQ=450,inf=1e9;
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
ll n,m,p[N],sz[N],ls,po,qu[N],me[N],a[N],b[N],g;
pll ud[N],ed[N],c[N],d[N];
vector<ll> f[N*4];
vector<ll> ne[N];
map<ll,ll> mp[N];
ll gp(ll x){
    return p[x]?gp(p[x]):x;
}
bool uni(ll v, ll u){
    v=gp(v);
    u=gp(u);
    if(v==u) return false;
    if(sz[v]<sz[u]) swap(v,u);
    p[u]=v;
    sz[v]+=sz[u];
    ud[++po]={v,u};
    return true;
}
void un(){
    auto [u,v]=ud[po];
    po--;
    sz[u]-=sz[v];
    p[v]=0;
}
void upd(ll v, ll l, ll r, ll tl, ll tr, ll x){
    if(tl>=tr) return;
    if(tl==l && tr==r){
        f[v].pb(x);
        return;
    }
    ll m=(l+r)>>1;
    upd(lc,l,m,tl,min(m,tr),x);
    upd(rc,m,r,max(m,tl),tr,x);
}
void solve(ll v, ll l, ll r){
    ll tmp=0;
    for(ll x : f[v]){
        tmp+=uni(ed[x].F,ed[x].S);
    }
    if(r-l==1){
        if(qu[l]){
            ll x,y;
            if(ls) x=d[l].F,y=d[l].S;
            else x=c[l].F,y=c[l].S;
            x=gp(x);
            y=gp(y);
            if(x==y) ls=1;
            else ls=0;
            cout << ls;
        }
        if(r<=m && !qu[r]){
            if(ls){
                ne[b[r]].pop_back();
                ne[a[r]].pop_back();
                if(me[b[r]]==0){
                    upd(1,0,m+1,r,ne[b[r]].back(),b[r]);
                }
                me[b[r]]^=1;
                if(me[a[r]]==1){
                    upd(1,0,m+1,r,ne[a[r]].back(),a[r]);
                }
            }else{
                ne[b[r]].pop_back();
                ne[a[r]].pop_back();
                if(me[a[r]]==0){
                    upd(1,0,m+1,r,ne[a[r]].back(),a[r]);
                }
                me[a[r]]^=1;
                if(me[b[r]]==1){
                    upd(1,0,m+1,r,ne[b[r]].back(),b[r]);
                }
            }
        }
    }else{
        ll m=(l+r)>>1;
        solve(lc,l,m);
        solve(rc,m,r);
    }
    while(tmp--) un();
}
int main(){
    fast_io;
    cin >> n >> m;
    for(ll i=1; i<=n; i++) sz[i]=1;
    for(ll i=1; i<=m; i++){
        ll t,x1,y1,x2,y2;
        cin >> t >> x1 >> y1;
        if(t==2){
            qu[i]=1;
            c[i]={x1,y1};
            d[i]={x1%n+1,y1%n+1};
            continue;
        }
        if(x1>y1) swap(x1,y1);
        if(!mp[x1][y1]) mp[x1][y1]=++g,ed[g]={x1,y1};
        a[i]=mp[x1][y1];
        ne[a[i]].pb(i);
        x2=x1%n+1;
        y2=y1%n+1;
        if(x2>y2) swap(x2,y2);
        if(!mp[x2][y2]) mp[x2][y2]=++g,ed[g]={x2,y2};
        b[i]=mp[x2][y2];
        ne[b[i]].pb(i);
    }
    for(ll i=1; i<=g; i++){
        ne[i].pb(m+1);
        reverse(ne[i].begin(),ne[i].end());
    }
    solve(1,0,m+1);
    return 0;
}