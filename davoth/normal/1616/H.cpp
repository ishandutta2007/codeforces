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
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define kill(x) cout << x << '\n';exit(0)
#define killshayan kill("done!")
#define killmashtali kill("Hello, World!")
const int N=2e5+10,LN=60,M=1e6+10,SQ=700,BS=737,inf=1.05e9,NSQ=N/SQ+3;
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
ll n,k;
vector<ll> vec;
ll s2(ll i, ll x, vector<ll> a, vector<ll> b){
    if(a.empty() || b.empty()) return 0;
    if(i==-1) return (pow(2,a.size(),MD)-1)*(pow(2,b.size(),MD)-1)%MD;
    ll ans=0;
    vector<ll> A[2],B[2];
    for(ll t : a) A[t>>i&1].pb(t&((1<<i)-1));
    for(ll t : b) B[t>>i&1].pb(t&((1<<i)-1));
    if(x>>i&1){
        ll wa[2]={pow(2,A[0].size(),MD),pow(2,A[1].size(),MD)},wb[2]={pow(2,B[0].size(),MD),pow(2,B[1].size(),MD)};
        ans=(ans+(s2(i-1,x^(1<<i),A[0],B[1])+wa[0]+wb[1]-1)*(s2(i-1,x^(1<<i),A[1],B[0])+wa[1]+wb[0]-1)-wa[0]*wa[1]%MD-wb[0]*wb[1]%MD+2*MD+1)%MD;
    }else{
        ans=(ans+s2(i-1,x,A[0],B[0]))%MD;
        ans=(ans+s2(i-1,x,A[1],B[1]))%MD;
    }
    return ans;
}
ll s1(ll i, ll x, vector<ll> v){
    if(v.empty()) return 0;
    if(i==-1) return pow(2,v.size(),MD)-1;
    ll ans=0;
    vector<ll> V[2];
    for(ll t : v) V[t>>i&1].pb(t&((1<<i)-1));
    if(x>>i&1){
        ans=(ans+pow(2,V[0].size(),MD)+pow(2,V[1].size(),MD)-2)%MD;
        ans=(ans+s2(i-1,x^(1<<i),V[0],V[1]))%MD;
    }else{
        ans=(ans+s1(i-1,x,V[0]))%MD;
        ans=(ans+s1(i-1,x,V[1]))%MD;
    }
    return ans;
}
int main(){
    fast_io;
    cin >> n >> k;
    for(ll i=1; i<=n; i++){
        ll x;
        cin >> x;
        vec.pb(x);
    }
    cout << s1(30,k,vec)<< '\n';
    return 0;
}