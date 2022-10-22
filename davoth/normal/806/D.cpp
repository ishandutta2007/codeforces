#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
/*#pragma comment(linker, "/stack:200000000")
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
//#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e3+10,LN=20,M=5e6,SQ=350,B=737,inf=1e9+10;
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
ll n,a[N][N],d[N],m=inf,f[N];
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i<n; i++){
        for(ll j=i+1; j<=n; j++){
            cin >> a[i][j];
            m=min(m,a[j][i]=a[i][j]);
        }
    }
    for(ll i=1; i<=n; i++){
        d[i]=inf*2;
        for(ll j=1; j<=n; j++){
            if(j!=i){
                a[i][j]-=m;
                d[i]=min(d[i],a[i][j]*2);
            }
        }
    }
    for(ll i=1; i<=n; i++){
        ll k=0;
        for(ll j=1; j<=n; j++) if(!f[j] && (!k || d[j]<d[k])) k=j;
        f[k]=1;
        for(ll j=1; j<=n; j++) if(a[k][j]+d[k]<d[j]) d[j]=d[k]+a[k][j];
    }
    for(ll i=1; i<=n; i++) cout << d[i]+(n-1)*m << '\n';
    return 0;
}