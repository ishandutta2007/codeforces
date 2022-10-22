/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
using ld=long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
using point=complex<double>;
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
#define killmashtali kill("Hello, World!")
const int N=1e5+10,LN=19,M=3e2+10,SQ=256,B=737,inf=1e9;
const ll INF=1e18;
const double pi=acos(-1);
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
ll n,a[N],b[N],dp[N],L,R;
pair<ll,pll> A[N];
ll insc(pll x, pll y){
    if(x.F==y.F) return (x.S<=y.S?-INF:INF);
    return (x.S-y.S)/(y.F-x.F)+((x.S-y.S)%(y.F-x.F)>0);
}
void Add(pll x){
    while(R>L && insc(A[R-1].S,x)<=A[R-1].F) R--;
    if(L==R) A[R++]={-INF,x};
    else{
        A[R]={insc(A[R-1].S,x),x};
        R++;
    }
}
ll GetMin(ll x){
    while(L+1<R && A[L+1].F<=x) L++;
    return A[L].S.F*x+A[L].S.S;
}
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i<=n; i++) cin >> a[i];
    for(ll i=1; i<=n; i++) cin >> b[i];
    for(ll i=2; i<=n; i++){
        Add({b[i-1],dp[i-1]});
        dp[i]=GetMin(a[i]);
    }
    cout << dp[n] << '\n';
    return 0;
}