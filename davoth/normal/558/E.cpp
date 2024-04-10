#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e5+10,LN=30,SQ=550,M=1e6+10;
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
ll n,q,a[26][4*N],lz[26][4*N],z[26];
string s;
void update(ll c, ll v, ll l, ll r, ll tl, ll tr, ll x){
    if(tl>=tr) return;
    if(l==tl && r==tr){
        a[c][v]=x*(r-l);
        lz[c][v]=x;
        return;
    }
    ll m=(l+r)/2;
    if(lz[c][v]!=-1){
        a[c][v*2]=lz[c][v]*(m-l);
        a[c][v*2+1]=lz[c][v]*(r-m);
        lz[c][v*2+1]=lz[c][v*2]=lz[c][v];
    }
    lz[c][v]=-1;
    update(c,v*2,l,m,tl,min(m,tr),x);
    update(c,v*2+1,m,r,max(m,tl),tr,x);
    a[c][v]=a[c][v*2]+a[c][v*2+1];
}
ll get(ll c, ll v, ll l, ll r, ll tl, ll tr){
    if(tl>=tr) return 0;
    if(l==tl && r==tr) return a[c][v];
    ll m=(l+r)/2;
    if(lz[c][v]!=-1){
        a[c][v*2]=lz[c][v]*(m-l);
        a[c][v*2+1]=lz[c][v]*(r-m);
        lz[c][v*2+1]=lz[c][v*2]=lz[c][v];
    }
    lz[c][v]=-1;
    return get(c,v*2,l,m,tl,min(m,tr))+get(c,v*2+1,m,r,max(m,tl),tr);
}
int main(){
    fast_io;
    cin >> n >> q >> s;
    memset(lz,-1,sizeof lz);
    for(ll i=1; i<=n; i++) update(s[i-1]-'a',1,1,n+1,i,i+1,1);
    while(q--){
        ll l,r,k;
        cin >> l >> r >> k;
        memset(z,0,sizeof z);
        for(ll i=0; i<26; i++) z[i]=get(i,1,1,n+1,l,r+1),update(i,1,1,n+1,l,r+1,0);
        if(k){
            ll j=0;
            for(ll i=0; i<26; i++) update(i,1,1,n+1,l+j,l+j+z[i],1),j+=z[i];
        }else{
            ll j=0;
            for(ll i=25; i>=0; i--) update(i,1,1,n+1,l+j,l+j+z[i],1),j+=z[i];
        }
    }
    for(ll i=1; i<=n; i++){
        for(ll j=0; j<26; j++) if(get(j,1,1,n+1,i,i+1)) cout << (char)('a'+j);
    }
    cout << '\n';
    return 0;
}