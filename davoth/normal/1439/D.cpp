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
using point=complex<ld>;
#define F first
#define S second
//#define X real()
//#define Y imag()
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define kill(x) cout << x << '\n';exit(0)
#define killshayan kill("done!\n")
const int N=5e2+10,LN=19,M=1e8+10,SQ=256,B=737,inf=1e9;
const ll INF=1e18;
const ld ep=1e-7;
const int MH=1000696969,MD=998244353/*,MOD=1000000007*/;
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
ll n,m,MOD,f[N],iv[N],ans;
ll C(ll n, ll k){
    if(n<k || k<0) return 0;
    return f[n]*iv[k]%MOD*iv[n-k]%MOD;
}
int main(){
    fast_io;
    //kill("Hello, World!");
    cin >> n >> m >> MOD;
    f[0]=iv[0]=1;
    for(ll i=1; i<=n; i++){
        f[i]=f[i-1]*i%MOD;
        iv[i]=pow(f[i],MOD-2,MOD);
    }
    for(ll i=1; i<m; i++){
        for(ll j=0; j+i<m; j++){
            ll x=1;
            if(j) x=pow(n-i,j-1,MOD)*pow(2,j,MOD)%MOD*(n-i-j)%MOD;
            ans=(ans+pow(i+1,i-1,MOD)*pow(2,i,MOD)%MOD*x%MOD*C(i+j,i)%MOD*i*(i+1)%MOD*(n+1)%MOD*pow(n+1,m-i-j-1,MOD)%MOD*pow(2,m-i-j-1,MOD))%MOD;
        }
    }
    cout << ans*(n-m+1)%MOD*pow(n+1,MOD-2,MOD)%MOD << '\n';
    return 0;
}