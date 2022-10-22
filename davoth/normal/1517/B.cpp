#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
//#pragma GCC optimize("O2")
/*#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
//#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e2+10,LN=32,M=1e5+4,SQ=350,B=737,inf=1e9;
const ll INF=1e18;
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
ll t,n,m,ans[N][N];
pll a[N];
vector<pll> b[N];
int main(){
    fast_io;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(ll i=1; i<=m; i++) a[i].F=INF,a[i].S=i;
        for(ll i=1; i<=n; i++){
            b[i].clear();
            for(ll j=1; j<=m; j++){
                ll x;
                cin >> x;
                b[i].pb({x,j});
            }
            sort(b[i].begin(),b[i].end());
            sort(a+1,a+m+1);
            for(ll j=1; j<=m; j++){
                a[j].F=min(b[i][m-j].F,a[j].F);
                ans[i][a[j].S]=b[i][m-j].F;
            }
        }
        for(ll i=1; i<=n; i++){
            for(ll j=1; j<=m; j++){
                cout << ans[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}