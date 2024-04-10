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
#define killshayan kill("done!")
#define killmashtali kill("Hello, World!")
const int N=1e2+10,LN=19,M=1e5+10,SQ=450,BS=737,inf=1e9,NSQ=N/SQ+1;
const ll INF=1e16;
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
ll n,a[N],t,b[N];
bool dp[N][N*N];
int main(){
    fast_io;
    cin >> t;
    while(t--){
        cin >> n;
        ll ans=0,s=0;
        memset(dp,0,sizeof dp);
        for(ll i=1; i<=n; i++){
            cin >> a[i];
            ans+=a[i]*a[i]*(n-2);
            s+=a[i];
        }
        dp[0][0]=1;
        for(ll i=1; i<=n; i++){
            cin >> b[i];
            s+=b[i];
            ans+=b[i]*b[i]*(n-2);
            ll x=abs(a[i]-b[i]);
            for(ll j=0; j<i*100; j++){
                if(!dp[i-1][j]) continue;
                dp[i][j+x]=1;
                dp[i][abs(j-x)]=1;
            }
        }
        ll f,g;
        for(ll i=0; i<n*100; i++) if(dp[n][i]){
            f=(s-i)/2;
            g=(s+i)/2;
            break;
        }
        ans+=f*f+g*g;
        cout << ans << '\n';
    }
    return 0;
}