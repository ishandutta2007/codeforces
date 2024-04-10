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
const int N=1e6+10,LN=19,M=3e2+10,SQ=256,B=737,inf=1e9;
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
struct CHT{
    const ll INF=1e18;
    pair<ll, pll> A[N]; // {start, {m, h}}
    int L, R;
    CHT(){
        L=R=0;
        memset(A, 0, sizeof(A));
    }
    inline ll Intersect(pll a, pll b){ // a.first<=b.first
        if (a.first==b.first) return (a.second<=b.second?-INF:INF);
        return (a.second-b.second)/(b.first-a.first) + ((a.second-b.second)%(b.first-a.first)>0);
    }
    inline void Add(pll X){
        while (L<R && Intersect(A[R-1].second, X)<=A[R-1].first) R--;
        if (L==R) A[R++]={-INF, X};
        else A[R]={Intersect(A[R-1].second, X), X}, R++;
    }
    inline ll GetMax(ll x){
        while (L+1<R && A[L+1].first<=x) L++;
        return A[L].second.first*x + A[L].second.second;
    }
} cht;
ll n,dp[N],ans;
pair<pll,ll> p[N];
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i<=n; i++){
        cin >> p[i].F.F >> p[i].F.S >> p[i].S;
    }
    sort(p+1,p+n+1);
    ans=dp[1]=p[1].F.F*p[1].F.S-p[1].S;
    cht.Add({p[1].F.F,dp[1]});
    for(ll i=2; i<=n; i++){
        dp[i]=max(cht.GetMax(-p[i].F.S),0ll)+p[i].F.F*p[i].F.S-p[i].S;
        cht.Add({p[i].F.F,dp[i]});
        ans=max(ans,dp[i]);
    }
    cout << ans << '\n';
    return 0;
}