#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#pragma GCC optimize("O2")
/*#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=3e5+10,LN=20,M=5e1+1,SQ=600,inf=1e9;
const ll INF=1e18;
const int MH=1000696969,MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,f[N],iv[N],cnt[N],dp[10][N];
int main(){
    fast_io;
    f[0]=iv[0]=1;
    for(ll i=1; i<N; i++) f[i]=i*f[i-1]%MOD,iv[i]=pow(f[i],MOD-2,MOD);
    cin >> n;
    for(ll i=1; i<=n; i++){
        ll t;
        cin >> t;
        cnt[t]++;
    }
    for(ll i=1; i<N; i++){
        for(ll j=i*2; j<N; j+=i){
            cnt[i]+=cnt[j];
        }
    }
    for(ll i=1; i<10; i++){
        for(ll j=N-1; j>=1; j--){
            if(cnt[j]>=i) dp[i][j]=f[cnt[j]]*iv[i]%MOD*iv[cnt[j]-i]%MOD;
            for(ll k=j*2; k<N; k+=j){
                dp[i][j]=(MOD+dp[i][j]-dp[i][k])%MOD;
            }
        }
        if(dp[i][1]>0){
            cout << i << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}