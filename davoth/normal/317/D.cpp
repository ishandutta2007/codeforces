#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
/*#pragma comment(linker, "/stack:200000000")
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
//#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e6+10,LN=20,M=5e6,SQ=350,B=737,inf=1e9+10;
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
//short int dp[(1<<29)];
ll dp[30]={0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12};
ll n,f[N],ans,s,x;
/*void pre(){
    for(int i=1; i<(1<<29); i++){
        vector<int> vec;
        for(int j=i; j; j-=j&-j){
            int k=__builtin_ctz(j&-j),x=i;
            for(int t=k+1; t<30; t+=k+1) x-=x&(1<<(t-1));
            vec.pb(dp[x]);
        }
        sort(vec.begin(),vec.end());
        vec.resize(unique(vec.begin(),vec.end())-vec.begin());
        dp[i]=vec.size();
        for(int j=0; j<vec.size(); j++){
            if(vec[j]!=j){
                dp[i]=j;
                break;
            }
        }
    }
    for(int i=1; i<=29; i++) cout << dp[(1<<i)-1] << '\n';
}*/
int main(){
    fast_io;
    //pre();
    cin >> n;
    for(ll i=2; i*i<=n; i++){
        if(f[i]) continue;
        x=0;
        for(ll j=i; j<=n; j*=i){
            if(j<N) f[j]=1;
            x++;
            s++;
        }
        ans^=dp[x];
    }
    ans^=(n-s)%2;
    if(ans) cout << "Vasya\n";
    else cout << "Petya\n";
    return 0;
}