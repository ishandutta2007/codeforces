#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
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
const int N=2e5+10,LN=19,M=5e6,SQ=350,BS=737,inf=1e9+10;
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
string s;
ll n,k,t,a[N],c[23][23],d[23],dp[M],ans,cn[23],y;
int main(){
    fast_io;
    cin >> n >> k >> t >> s;
    for(ll i=1; i<=n; i++){
        a[i]=s[i-1]-'A';
        cn[a[i]]++;
    }
    for(ll i=0; i<k; i++) if(cn[i]) y++;
    for(ll i=0; i<k; i++) cin >> d[i];
    for(ll i=0; i<k; i++){
        for(ll j=0; j<k; j++){
            cin >> c[i][j];
            ll ms=0,f=0;
            for(ll x=1; x<=n; x++){
                if(a[x]==j && f){
                    dp[ms]+=c[i][j];
                    dp[ms|(1<<i)|(1<<j)]+=c[i][j];
                    dp[ms|(1<<i)]-=c[i][j];
                    dp[ms|(1<<j)]-=c[i][j];
                    f=0;
                }
                if(a[x]==i){
                    f=1;
                    ms=0;
                }
                if(a[x]!=i && a[x]!=j) ms|=(1<<a[x]);
            }
        }
    }
    for(ll i=0; i<k; i++){
        for(ll j=0; j<(1<<k); j++){
            if(j&(1<<i)) dp[j]+=dp[j^(1<<i)];
        }
    }
    for(ll i=0; i<(1<<k); i++){
        for(ll j=i; j; j-=j&-j){
            ll x=j&-j;
            x=__builtin_ctzll(x);
            if(!cn[x]) dp[i]=t+1;
            dp[i]+=d[x];
        }
        if(__builtin_popcountll(i)>=y) dp[i]=t+1;
        if(dp[i]<=t) ans++;
    }
    cout << ans << '\n';
    return 0;
}