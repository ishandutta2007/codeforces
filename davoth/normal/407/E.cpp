#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,fma")
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define lc v<<1
#define rc 1+(v<<1)
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10,LN=20,M=2e5+10,SQ=250,inf=1e9;
const ll INF=1e18;
const int MOD=1000000007 /*998244353*/;
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
ll n,k,d,a[N],f[N*4],lz[N*4];
pll ans={INF,INF};
map<ll,ll> mp;
vector<pll> vec;
void shift(ll v, ll l, ll r){
    f[v]+=lz[v];
    if(r-l>1){
        lz[lc]+=lz[v];
        lz[rc]+=lz[v];
    }
    lz[v]=0;
}
void upd(ll v, ll l, ll r, ll tl, ll tr, ll x){
    shift(v,l,r);
    if(tl>=tr) return;
    if(tl==l && tr==r){
        lz[v]+=x;
        return shift(v,l,r);
    }
    ll m=(l+r)>>1;
    upd(lc,l,m,tl,min(tr,m),x);
    upd(rc,m,r,max(tl,m),tr,x);
    f[v]=min(f[lc],f[rc]);
}
ll get(ll v, ll l , ll r){
    shift(v,l,r);
    if(r-l==1) return l;
    ll m=(l+r)>>1;
    shift(lc,l,m);
    shift(rc,m,r);
    if(f[rc]<=k) return get(rc,m,r);
    return get(lc,l,m);
}
int main(){
    fast_io;
    cin >> n >> k >> d;
    for(ll i=1; i<=n; i++){
        cin >> a[i];
        a[i]+=1e9+10;
    }
    if(d==0){
        ll ls=0,t=0,ans=0,l,g=1;
        for(ll i=1; i<=n; i++){
            if(a[i]==ls) t++;
            else{
                if(t>ans) ans=t,l=g;
                ls=a[i];
                g=i;
                t=1;
            }
        }
        if(t>ans) ans=t,l=g;
        cout << l << ' ' << l+ans-1 << '\n';
        return 0;
    }
    ll l=1;
    for(ll i=2; i<=n; i++){
        if(a[i]%d!=a[l]%d) vec.pb({l,i-1}),l=i;
    }
    vec.pb({l,n});
    for(ll i=1; i<=n; i++) a[i]/=d;
    for(auto [l,r] : vec){
        fill(f,f+(r-l+10)*4,1e10);
        fill(lz,lz+(r-l+10)*4,0);
        mp.clear();
        stack<pll> st[2];
        for(ll i=r; i>=l; i--){
            ll t=i;
            upd(1,l,r+1,i,i+1,-1e10);
            while(!st[0].empty() && st[0].top().F<=a[i]){
                auto [x,y]=st[0].top();
                upd(1,l,r+1,t+1,y+1,a[i]-x);
                t=y;
                st[0].pop();
            }
            st[0].push({a[i],t});
            t=i;
            while(!st[1].empty() && st[1].top().F>=a[i]){
                auto [x,y]=st[1].top();
                upd(1,l,r+1,t+1,y+1,x-a[i]);
                t=y;
                st[1].pop();
            }
            st[1].push({a[i],t});
            upd(1,l,r+1,i+1,r+1,-1);
            if(mp[a[i]]){
                upd(1,l,r+1,mp[a[i]],r+1,1e12);
            }
            mp[a[i]]=i;
            ll g=get(1,l,r+1);
            //cout << i << ' ' << g << '\n';
            if(g-i>ans.S-ans.F || (g-i==ans.S-ans.F && i<ans.F)) ans={i,g};
        }
    }
    cout << ans.F << ' ' << ans.S << '\n';
    return 0;
}