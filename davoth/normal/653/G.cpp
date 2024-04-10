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
const int N=3e5+10,LN=19,M=3e2+10,SQ=450,BS=737,inf=1e9,NSQ=N/SQ+1;
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
ll n,f[N],iv[N],p[N],ps[N],cnt[N][LN],fl[N],a[N],ans;
ll C(ll n, ll k){
    if(k>n || k<0) return 0;
    return f[n]*iv[k]%MOD*iv[n-k]%MOD;
}
ll get(ll l, ll r){
    if(l==0) return ps[r];
    return (ps[r]-ps[l-1]+MOD)%MOD;
}
int main(){
    fast_io;
    cin >> n;
    f[0]=iv[0]=1;
    for(ll i=1; i<N; i++){
        f[i]=f[i-1]*i%MOD;
        iv[i]=pow(f[i],MOD-2,MOD);
    }
    for(ll i=1; i<n; i++){
        p[i]=(p[i-1]+C(n-1,i))%MOD;
        ps[i]=(ps[i-1]+p[i])%MOD;
    }
    for(ll i=2; i<N; i++){
        if(fl[i]) continue;
        cnt[i][0]=n;
        for(ll j=i; j<N; j+=i) fl[j]=i;
    }
    for(ll i=1; i<=n; i++){
        ll x;
        cin >> x;
        while(x>1){
            ll t=fl[x],k=0;
            while(x%t==0){
                k++;
                x/=t;
            }
            cnt[t][0]--;
            cnt[t][k]++;
        }
    }
    for(ll i=2; i<N; i++){
        if(fl[i]!=i) continue;
        ll l=0;
        for(ll j=0; j<LN; j++){
            ll k=cnt[i][j];
            ans=(ans+get(l,l+k-1)*j%MOD-get(n-l-k,n-l-1)*j%MOD+MOD)%MOD;
            l+=k;
        }
    }
    cout << ans << '\n';
    return 0;
}