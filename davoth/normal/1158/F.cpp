#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
using ld = long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define F first
#define S second
#define pb push_back
//#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=3e3+10,LN=19,M=14348907,SQ=350,BS=737,inf=1e9+10;
const ll INF=1e18;
const ld ep=1e-7;
const int MH=1000696969,MD=1000000007,MOD=998244353;
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
ll n,c,a[N],dp[N][N],k,ans[N],vi[N],iv[N];
void s1(){
    ll pd[N][N];
    ll cnt[N][N];
    for(ll i=0; i<c; i++){
        for(ll j=1; j<=n; j++){
            cnt[i][j]=cnt[i][j-1]+(a[j]==i);
        }
    }
    memset(pd,0,sizeof pd);
    for(ll i=1; i<=n; i++){
        ll x=c,g=1;
        for(ll j=i; j<=n; j++){
            ll y=cnt[a[j]][j]-cnt[a[j]][i-1];
            if(y==1){
                x--;
            }else{
                g=g*iv[y]%MOD*vi[y-1]%MOD;
            }
            if(!x) pd[i][j]=g*vi[y]%MOD;
        }
    }
    dp[0][0]=1;
    for(ll j=1; j<=n; j++){
        for(ll q=0; q<j; q++){
            for(ll i=1; i<=k; i++){
                dp[i][j]=(dp[i][j]+dp[i-1][q]*pd[q+1][j])%MOD;
            }
        }
    }
}
void s2(){
    ll xd[2][8200];
    memset(xd,0,sizeof xd);
    dp[0][0]=1;
    for(ll i=0; i<k; i++){
        xd[0][0]=dp[i][0];
        for(ll ms=1; ms<(1<<c); ms++) xd[0][ms]=0;
        for(ll j=1; j<=n; j++){
            xd[1][0]=(dp[i][j]+xd[0][0])%MOD;
            ll x=1<<a[j];
            for(ll ms=1; ms<(1<<c); ms++){
                if(ms&x){
                    xd[1][ms]=(2*xd[0][ms]+xd[0][ms^x])%MOD;
                }else{
                    xd[1][ms]=xd[0][ms];
                }
            }
            dp[i+1][j]=xd[0][(1<<c)-1-x];
            for(ll ms=0; ms<(1<<c); ms++) xd[0][ms]=xd[1][ms];
        }
    }
}
int main(){
    fast_io;
    cin >> n >> c;
    k=n/c;
    for(ll i=0; i<=n; i++){
        iv[i]=pow(2,i,MOD)-1;
        vi[i]=pow(iv[i],MOD-2,MOD);
    }
    for(ll i=1; i<=n; i++){
        cin >> a[i];
        a[i]--;
    }
    if(c<=12) s2();
    else s1();
    for(ll i=0; i<=k; i++){
        for(ll j=0; j<=n; j++){
            ans[i]=(ans[i]+dp[i][j]*(iv[n-j]+1))%MOD;
        }
    }
    ans[0]--;
    for(ll i=0; i<n; i++) ans[i]=(ans[i]-ans[i+1]+MOD)%MOD;
    for(ll i=0; i<=n; i++) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}