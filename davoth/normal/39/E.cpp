#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
//#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e5+10,LN=18,M=3.5e7+10,SQ=350,BS=737,inf=1e9+10;
const ll INF=1e15;
const int MH=1000696969,MOD=1000000007,MD=998244353;
mt19937 rng(time(0));
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
ll n,k,a,b,ans[N][31];
int main(){
    fast_io;
    cin >> a >> b >> k;
    n=N-1;
    for(ll i=n; i>1; i--){
        ll t=1;
        for(ll j=1; j<=30; j++){
            if(t*i>=k) ans[i][j]=1;
            else t*=i;
        }
    }
    if(!ans[n][1] && k%2==n%2) ans[n][1]=1;
    for(ll i=n; i>1; i--){
        for(ll j=30; j; j--){
            if(i!=n && !ans[i+1][j]) ans[i][j]=1;
            if(j!=30 && !ans[i][j+1]) ans[i][j]=1;
        }
    }
    if(a==1){
        for(ll j=b; j<=30; j++){
            if(!ans[2][j]){
                if(j%2==b%2) cout << "Masha\n";
                else cout << "Stas\n";
                return 0;
            }
        }
        cout << "Missing\n";
    }else if(a>n){
        if(k%2==a%2) cout << "Masha\n";
        else cout << "Stas\n";
    }else{
        if(ans[a][b]) cout << "Masha\n";
        else cout << "Stas\n";
    }
    return 0;
}