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
const int N=1e3+10,LN=18,M=1e6+10,SQ=350,BS=737,inf=1.05e9,NSQ=N/SQ+1;
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
ll n,q,f[4][N][N];
void upd(ll c, ll a, ll b, ll x){
    a+=2;
    b+=2;
    for(ll i=a; i<N; i+=i&-i)
        for(ll j=b; j<N; j+=j&-j)
            f[c][i][j]^=x;
}
ll gt(ll c, ll a, ll b, ll x=0){
    a+=2;
    b+=2;
    for(ll i=a; i; i-=i&-i)
        for(ll j=b; j; j-=j&-j)
            x^=f[c][i][j];
    return x;
}
ll get(ll x, ll y){
    ll c=(x&1)*2+(y&1);
    return gt(c,x/2,y/2);
}
void update(ll x, ll y, ll k){
    ll c=(x&1)*2+(y&1);
    upd(c,x/2,y/2,k);
}
int main(){
    fast_io;
    cin >> n >> q;
    while(q--){
        ll t,x1,y1,x2,y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        if(t==1){
            cout << (get(x2,y2)^get(x2,y1-1)^get(x1-1,y2)^get(x1-1,y1-1)) << '\n';
        }else{
            ll x;
            cin >> x;
            update(x1,y1,x);
            update(x1,y2+1,x);
            update(x2+1,y1,x);
            update(x2+1,y2+1,x);
        }
    }
    return 0;
}