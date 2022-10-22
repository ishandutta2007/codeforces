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
const int N=3e5+10,LN=18,M=1e6+10,SQ=500,B=737,inf=1e9;
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
ll t,n,k,a[N],b[M],c[N],ans;
ordered_set st[N];
int main(){
    fast_io;
    cin >> t;
    for(ll i=2; i<M; i++){
        if(!b[i]){
            for(ll j=i; j<M; j+=i){
                b[j]=b[j/i]+1;
            }
        }
    }
    while(t--){
        ans=0;
        cin >> n >> k;
        for(ll i=1; i<=n; i++){
            cin >> a[i];
            c[i]=b[a[i]];
            if(i>k) c[i]+=c[i-k];
            else st[i%k].clear();
            ll x=i%k;
            ans+=st[x].order_of_key({c[i]-1,i})-st[x].order_of_key({c[i]-1,-1});
            if(i>k) st[x].insert({c[i-k],i-k});
            else st[x].insert({0,0});
        }
        cout << ans << '\n';
    }
    return 0;
}