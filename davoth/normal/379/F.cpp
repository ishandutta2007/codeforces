#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#pragma GCC optimize("O2")
/*#pragma GCC optimize("unroll-loops")
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
const int N=1e6+10,LN=20,M=3.5e7+10,SQ=350,BS=737,inf=1e9+10;
const ll INF=1e15;
const ld ep=1e-7;
const int MH=1000696969,MOD=1000000007,MD=998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
ll q,p[LN][N],ans=2,n=4,h[N],f[N];
vector<ll> vec={2,3,4};
ll lca(ll v, ll u){
    if(h[u]<h[v]) swap(v,u);
    for(ll i=LN; i--;){
        if(h[p[i][u]]>=h[v]) u=p[i][u];
    }
    for(ll i=LN; i--;){
        if(p[i][u]!=p[i][v]) u=p[i][u],v=p[i][v];
    }
    return p[0][v];
}
int main(){
    fast_io;
    cin >> q;
    h[2]=h[3]=h[4]=f[2]=f[3]=f[4]=p[0][2]=p[0][3]=p[0][4]=1;
    for(ll i=1; i<LN; i++){
        for(ll j=2; j<5; j++){
            p[i][j]=p[i-1][p[i-1][j]];
        }
    }
    while(q--){
        ll v;
        cin >> v;
        p[0][n+1]=p[0][n+2]=v;
        h[n+1]=h[n+2]=h[v]+1;
        for(ll i=1; i<LN; i++){
            for(ll j=n+1; j<=n+2; j++){
                p[i][j]=p[i-1][p[i-1][j]];
            }
        }
        if(h[n+1]==h[vec[0]]){
            f[n+1]=f[n+2]=1;
            vec.pb(n+1);
            vec.pb(n+2);
        }else if(f[v]){
            for(ll i : vec) f[i]=0;
            vec={n+1,n+2};
            f[n+1]=f[n+2]=1;
            ans++;
        }
        ans=max(ans,h[n+2]+h[vec[0]]-2*h[lca(n+2,vec[0])]);
        cout << ans << '\n';
        n+=2;
    }
    return 0;
}