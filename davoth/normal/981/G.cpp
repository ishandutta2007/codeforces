#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e6+10,LN=20,SQ=550,M=5e4+10;
const ll INF=1e16;
const int MOD=/*1000000007*/ 998244353;
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
ll n,f[N*4],lz[N*4],q,lz2[4*N];
set<pll> st[N];
void shift(ll v, ll l, ll r){
    f[v]=(f[v]*lz2[v]+lz[v]*(r-l))%MOD;
    if(r-l>1){
        lz2[v*2]*=lz2[v],lz2[v*2+1]*=lz2[v];
        lz[v*2]*=lz2[v],lz[v*2+1]*=lz2[v];
        lz[v*2]+=lz[v],lz[v*2+1]+=lz[v];
        lz[v*2]%=MOD;
        lz[v*2+1]%=MOD;
        lz2[v*2]%=MOD;
        lz2[v*2+1]%=MOD;
    }
    lz[v]=0;
    lz2[v]=1;
}
void update(ll v, ll l, ll r, ll tl, ll tr, ll x){
    shift(v,l,r);
    if(tl>=tr) return;
    if(tl==l && tr==r){
        lz[v]+=x;
        lz[v]%=MOD;
        return shift(v,l,r);
    }
    ll m=(l+r)/2;
    update(v*2,l,m,tl,min(m,tr),x);
    update(v*2+1,m,r,max(m,tl),tr,x);
    f[v]=(f[v*2]+f[v*2+1])%MOD;
}
void Update(ll v, ll l, ll r, ll tl, ll tr, ll x){
    shift(v,l,r);
    if(tl>=tr) return;
    if(tl==l && tr==r){
        lz2[v]*=x;
        lz2[v]%=MOD;
        lz[v]*=x;
        lz[v]%=MOD;
        return shift(v,l,r);
    }
    ll m=(l+r)/2;
    Update(v*2,l,m,tl,min(m,tr),x);
    Update(v*2+1,m,r,max(m,tl),tr,x);
    f[v]=(f[v*2]+f[v*2+1])%MOD;
}
ll get(ll v, ll l, ll r, ll tl, ll tr){
    shift(v,l,r);
    if(tl>=tr) return 0;
    if(tl==l && tr==r) return f[v];
    ll m=(l+r)/2;
    return (get(v*2,l,m,tl,min(m,tr))+get(v*2+1,m,r,max(m,tl),tr))%MOD;
}
int main(){
    fast_io;
    cin >> n >> q;
    while(q--){
        ll t,L,R,X;
        cin >> t >> L >> R;
        if(t==2){
            cout << get(1,1,N,L,R+1) << '\n';
        }else{
            cin >> X;
            auto l=st[X].lower_bound({L,-1});
            if(l!=st[X].begin()){
                l--;
                if(l->S < L) l++;
            }
            auto r=l;
            ll cl=L,cr=R;
            while(r!=st[X].end()){
                if(r->F > R) break;
                cl=min(cl,r->F);
                cr=max(cr,r->S);
                Update(1,1,N,max(L,r->F),min(r->S,R)+1,2);
                update(1,1,N,max(L,r->F),min(r->S,R)+1,-1);
                r=st[X].erase(r);
            }
            if(cl<L) st[X].insert({cl,L-1});
            if(cr>R) st[X].insert({R+1,cr});
            st[X].insert({L,R});
            update(1,1,N,L,R+1,1);
        }
    }
    return 0;
}