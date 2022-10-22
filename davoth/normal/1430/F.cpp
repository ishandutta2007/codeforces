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
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define kill(x) cout << x << '\n';exit(0)
#define killshayan kill("done!")
#define killmashtali kill("Hello, World!")
const int N=2e3+10,LN=20,M=1e6+10,SQ=700,BS=737,inf=1.05e9,NSQ=N/SQ+3;
const ll INF=1e18;
const double pi=acos(-1);
const ld ep=1e-7;
const int MH=1000696969,MD=998244353,MOD=1000000007;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pii, null_type,greater<pii>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,k,l[N],r[N],a[N],ps[N];
pll dp[N][N];
ll get(ll l, ll r){
    ll ans=ps[r];
    if(l) ans-=ps[l-1];
    return ans;
}
int main(){
    fast_io;
    cin >> n >> k;
    dp[0][0]={0,1};
    for(ll i=1; i<=n; i++){
        cin >> l[i] >> r[i] >> a[i];
        ps[i]=a[i]+ps[i-1];
        ll wtf=a[i],tw=l[i],cmon=-1;
        wtf-=min(wtf,k);
        tw+=(wtf+k-1)/k;
        if(tw>r[i]){
            dp[i][i]={-1,-1};
        }else if(tw==r[i]){
            dp[i][i]={0,0};
        }else dp[i][i]={0,1};
        for(ll j=0; j<i; j++){
            if(dp[i-1][j].S==-1){
                dp[i][j]={-1,-1};
                continue;
            }
            ll x=(k-get(j,i-1)%k)%k,y=a[i],t=l[i];
            if(l[i]>r[i-1] || dp[i-1][j].S==1){
                if(cmon==-1 || x+dp[i-1][j].F<cmon) cmon=x+dp[i-1][j].F;
            }
            y-=min(x,y);
            t+=(y+k-1)/k;
            if(t>r[i]){
                dp[i][j]={-1,-1};
                continue;
            }
            dp[i][j].F=dp[i-1][j].F;
            dp[i][j].S=t<r[i];
        }
        if(cmon==-1) dp[i][i]={-1,-1};
        else if(dp[i][i].S!=-1) dp[i][i].F=cmon;
    }
    ll ans=-1;
    for(ll i=0; i<=n; i++) if(dp[n][i].F!=-1 && (ans==-1 || dp[n][i].F<ans)) ans=dp[n][i].F;
    if(ans==-1) cout << -1 << '\n';
    else cout << ps[n]+ans << '\n';
    return 0;
}