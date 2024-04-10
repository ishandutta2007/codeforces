#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10,LN=20,SQ=547,M=1e6+10;
const ll INF=1e16;
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
ll n,q,t,f[4*N][5],lz[4*N],ls;
string s;
void shift(ll v, ll l, ll r){
    f[v][0]+=lz[v];
    f[v][1]+=lz[v];
    f[v][2]-=lz[v];
    f[v][3]-=lz[v];
    if(r-l>1) lz[v*2]+=lz[v],lz[v*2+1]+=lz[v];
    lz[v]=0;
}
void merge(ll v){
    f[v][4]=max({f[v*2][0]+f[v*2+1][3],f[v*2][2]+f[v*2+1][0],f[v*2][4],f[v*2+1][4]});
    f[v][0]=max(f[v*2][0],f[v*2+1][0]);
    f[v][1]=min(f[v*2][1],f[v*2+1][1]);
    f[v][2]=max({f[v*2][2],f[v*2+1][2],f[v*2][0]-2*f[v*2+1][1]});
    f[v][3]=max({f[v*2][3],f[v*2+1][3],f[v*2+1][0]-2*f[v*2][1]});
}
void update(ll v, ll l, ll r, ll tl, ll tr, ll x){
    shift(v,l,r);
    if(tl>=tr) return;
    if(l==tl && r==tr){
        lz[v]+=x;
        return shift(v,l,r);
    }
    ll m=(l+r)/2;
    update(v*2,l,m,tl,min(tr,m),x);
    update(v*2+1,m,r,max(tl,m),tr,x);
    merge(v);
}
int main(){
    fast_io;
    cin >> n >> q >> s;
    for(ll i=1; i<=2*n-2; i++){
        if(s[i-1]=='(') update(1,0,2*n-2,i,2*n-2,1);
        else update(1,0,2*n-2,i,2*n-2,-1);
    }
    cout << f[1][4] << '\n';
    while(q--){
        ll a,b;
        cin >> a >> b;
        if(s[a-1]!=s[b-1]){
            if(s[a-1]!='(') swap(a,b);
            update(1,0,2*n-2,a,2*n-2,-2);
            update(1,0,2*n-2,b,2*n-2,2);
            swap(s[a-1],s[b-1]);
        }
        cout << f[1][4] << '\n';
    }
    return 0;
}