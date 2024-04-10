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
const int N=2e3+10,LN=19,M=14348907,SQ=350,BS=737,inf=1e9+10;
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
ll n;
void f(ll x, ll y){
    cout << x << ' ' << y << '\n';
}
int main(){
    fast_io;
    cin >> n;
    if(n%4==2 || n%4==3) return cout << "NO\n", 0;
    cout << "YES\n";
    if(n%4==0){
        for(ll i=0; i<n; i+=4){
            f(i+3,i+4);
            f(i+1,i+3);
            f(i+2,i+4);
            f(i+2,i+3);
            f(i+1,i+4);
            f(i+1,i+2);
        }
    }else{
        for(ll i=0; i<n-1; i+=4){
            f(i+3,n);
            f(i+3,i+4);
            f(i+4,n);
            f(i+1,i+3);
            f(i+2,i+4);
            f(i+2,i+3);
            f(i+1,i+4);
            f(i+1,n);
            f(i+1,i+2);
            f(i+2,n);
        }
    }
    n-=n%4;
    for(ll i=0; i<n; i+=4){
        for(ll j=i+4; j<n; j+=4){
            f(i+4,j+3);
            f(i+3,j+3);
            f(i+4,j+2);
            f(i+1,j+2);
            f(i+2,j+4);
            f(i+3,j+4);
            f(i+2,j+3);
            f(i+2,j+2);
            f(i+4,j+1);
            f(i+4,j+4);
            f(i+1,j+3);
            f(i+1,j+4);
            f(i+3,j+1);
            f(i+3,j+2);
            f(i+2,j+1);
            f(i+1,j+1);
        }
    }
    return 0;
}