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
const int N=1e5+10,LN=18,M=1e8+10,SQ=256,B=737,inf=1e9;
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
ll n,q,a[N],f[LN][N],g[LN][N],p[N];
int main(){
    fast_io;
    cin >> n >> q;
    for(ll i=1; i<=n; i++){
        cin >> a[i];
        ll s=0;
        p[i]=(pow(2,i,MOD)*(a[i]+MOD)%MOD+p[i-1])%MOD;
        for(ll j=0; i-j>0; j++){
            s=s*2+a[i-j];
            if(s>1e9){
                break;
            }else if(s<=0){
                f[0][i]=i-j-1;
                break;
            }else if(j && i-j-f[0][i-j]>=30) break;
        }
        g[0][i]=(p[i]-p[f[0][i]]+MOD)%MOD*pow(pow(2,f[0][i],MOD),MOD-2,MOD)%MOD;
    }
    for(ll i=1; i<LN; i++){
        for(ll j=1; j<=n; j++){
            f[i][j]=f[i-1][f[i-1][j]];
            g[i][j]=(g[i-1][j]+g[i-1][f[i-1][j]])%MOD;
        }
    }
    while(q--){
        ll l,r,ans=0;
        cin >> l >> r;
        ans=(a[l]+MOD)%MOD;
        for(ll i=LN; i--; ){
            if(f[i][r]>=l){
                ans=(ans+g[i][r])%MOD;
                r=f[i][r];
            }
        }
        ans=(ans+(p[r]-p[l]+MOD)%MOD*pow(pow(2,l,MOD),MOD-2,MOD))%MOD;
        cout << ans << '\n';
    }
    return 0;
}