#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#pragma GCC optimize("O2")
/*#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
//#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e3+10,LN=32,M=1e5+4,SQ=350,B=737,inf=1e9;
const ll INF=1e18;
const int MH=1000696969,MOD=/*1000000007*/ 998244353;
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
ll n,m,dp[N][N],x,y,z[2],t[2],a[N][N];
vector<ll> v;
vector<pll> q[N*N];
int main(){
    fast_io;
    cin >> n >> m;
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=m; j++){
            cin >> a[i][j];
            v.pb(a[i][j]);
        }
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=m; j++){
            a[i][j]=lower_bound(v.begin(),v.end(),a[i][j])-v.begin();
            q[a[i][j]].pb({i,j});
        }
    }
    for(auto [i,j] : q[0]){
        y++;
        z[0]=(z[0]+i*i)%MOD;
        z[1]=(z[1]+j*j)%MOD;
        t[0]+=i;
        t[1]+=j;
    }
    for(ll k=1; k<v.size(); k++){
        for(auto [i,j] : q[k]){
            dp[i][j]=(x+y*(i*i+j*j)+z[0]+z[1]-2*t[0]*i%MOD-2*t[1]*j%MOD+2*MOD)%MOD*pow(y,MOD-2,MOD)%MOD;
        }
        for(auto [i,j] : q[k]){
            x=(x+dp[i][j])%MOD;
            y++;
            z[0]=(z[0]+i*i)%MOD;
            z[1]=(z[1]+j*j)%MOD;
            t[0]+=i;
            t[1]+=j;
        }
    }
    ll r,c;
    cin >> r >> c;
    cout << dp[r][c] << '\n';
    return 0;
}