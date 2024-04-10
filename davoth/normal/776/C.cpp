#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
using ld = long double;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10,LN=18,M=1.1e7+10,SQ=350,BS=737,inf=1e9+10;
const ll INF=1e15;
const int MH=1000696969,MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
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
ll n,k,a[N],ans,s,x;
vector<ll> pw;
map<ll,ll> pm;
int main(){
    fast_io;
    pm[0]=1;
    cin >> n >> k;
    pw.pb(1);
    if(k==-1) pw.pb(-1);
    else if(k!=1){
        for(ll i=k; abs(i)<=1e15; i*=k) pw.pb(i);
    }
    for(ll i=1; i<=n; i++){
        cin >> x;
        s+=x;
        for(ll j : pw) ans+=pm[s-j];
        pm[s]++;
    }
    cout << ans << '\n';
    return 0;
}