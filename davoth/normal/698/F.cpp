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
const int N=1e6+10,LN=24,M=1e7+10,SQ=500,B=737,inf=1e9;
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
ll n,sq,cm[N],ct[N],m[N],f[N],ls[N],to[N],fr[N],ans=1;
void sw(ll a, ll b){
    if(!to[a]){
        to[a]=b;
        ct[n/a]--;
    }
    if(!fr[b]) fr[b]=a;
    if(fr[b]!=a || to[a]!=b){
        cout << 0 << '\n';
        exit(0);
    }
}
int main(){
    fast_io;
    cin >> n;
    f[0]=1;
    for(ll i=1; i<=n; i++) f[i]=f[i-1]*i%MOD;
    sq=sqrt(n);
    fill(m+1,m+n+1,1);
    cm[1]=1;
    for(ll i=2; i<=n; i++){
        if(m[i]==1 && i*2<=n){
            ct[n/i]++;
            for(ll j=i; j<=n; j+=i){
                m[j]*=i;
                ls[j]=i;
            }
        }
        cm[m[i]]++;
    }
    for(ll i=1; i<=n; i++){
        ll x;
        cin >> x;
        if(!x) continue;
        if(m[i]!=m[x]){
            if(m[i]==1 || m[x]==1 || ls[i]<=sq || ls[x]<=sq || m[i]/ls[i]!=m[x]/ls[x]) return cout << 0 << '\n', 0;
            sw(ls[i],ls[x]);
        }else if(ls[i]>sq) sw(ls[i],ls[i]);
        cm[m[i]]--;
    }
    ct[1]=0;
    for(ll i=1; i<=n; i++) ans=ans*f[ct[i]]%MOD*f[cm[i]]%MOD;
    cout << ans << '\n';
    return 0;
}