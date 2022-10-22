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
const int N=1e5+10,LN=20,M=1e6+10,SQ=350,B=737,inf=1e9;
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
ll n,k,a[N],f[2][N],s,l,r,ans;
vector<ll> cp;
void upd(ll c, ll t, ll x){
    while(t<N) f[c][t]+=x,t+=t&-t;
}
ll get(ll c, ll t, ll x=0){
    while(t) x+=f[c][t],t-=t&-t;
    return x;
}
void add(){
    l++;
    upd(0,a[l],1);
    s+=l-get(0,a[l])+get(1,a[l]-1);
}
void ADD(){
    r--;
    upd(1,a[r],1);
    s+=l-get(0,a[r])+get(1,a[r]-1);
}
void rem(){
    s-=l-get(0,a[l])+get(1,a[l]-1);
    upd(0,a[l],-1);
    l--;
}
void REM(){
    s-=l-get(0,a[r])+get(1,a[r]-1);
    upd(1,a[r],-1);
    r++;
}
int main(){
    fast_io;
    cin >> n >> k;
    r=n+1;
    for(ll i=1; i<=n; i++){
        cin >> a[i];
        cp.pb(a[i]);
    }
    sort(cp.begin(),cp.end());
    cp.resize(unique(cp.begin(),cp.end())-cp.begin());
    for(ll i=1; i<=n; i++) a[i]=lower_bound(cp.begin(),cp.end(),a[i])-cp.begin()+1;
    for(int i=1; i<=n; i++) ADD();
    for(int i=1; i<=n; i++){
        if(r-l==1){
            REM();
        }
        add();
        while(s>k && r<=n) REM();
        ans+=n+1-r;
    }
    cout << ans << '\n';
    return 0;
}