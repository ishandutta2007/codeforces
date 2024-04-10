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
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10,LN=20,M=1e6+10,SQ=350,B=737,inf=1e9;
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
ll n,k,q,f[M],g[M],fc[N],iv[N],ans;
vector<ll> d[M];
ll C(ll n, ll k){
    if(k>n) return 0;
    return fc[n]*iv[k]%MOD*iv[n-k]%MOD;
}
int main(){
    fast_io;
    cin >> n >> k >> q;
    fc[0]=1;
    for(int i=1; i<=n+q; i++) fc[i]=i*fc[i-1]%MOD;
    iv[n+q]=pow(fc[n+q],MOD-2,MOD);
    for(int i=n+q; i; i--){
        iv[i-1]=iv[i]*i%MOD;
    }
    for(int i=1; i<=n; i++){
        ll x;
        cin >> x;
        g[x]++;
    }
    for(int i=1; i<M; i++){
        for(int j=i; j<M; j+=i){
            d[j].pb(i);
            if(j!=i) g[i]+=g[j];
        }
        f[i]=i;
        for(int j : d[i]){
            if(j!=i) f[i]-=f[j];
        }
        ans=(ans+C(g[i],k)*f[i])%MOD;
    }
    for(int i=1; i<=q; i++){
        ll x;
        cin >> x;
        for(int j : d[x]){
            ans=(ans+C(g[j],k-1)*f[j])%MOD;
            g[j]++;
        }
        cout << ans << '\n';
    }
    return 0;
}