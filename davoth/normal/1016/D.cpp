#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e2+10,LN=20,M=5e1+1,SQ=450,inf=1e9;
const ll INF=1e18;
const int MH=1000696969,MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,m,a[N],b[N],c[N][N],d;
void solve(ll n, ll m){
    if(n==1) for(ll i=1; i<=m; i++) c[1][i]^=b[i];
    else if(m==1) for(ll i=1; i<=n; i++) c[i][1]^=a[i];
    else{
        c[n][m]^=a[n]^b[m];
        c[n][m-1]^=b[m];
        b[m-1]^=c[n][m-1];
        c[n-1][m]^=a[n];
        a[n-1]^=c[n-1][m];
        solve(n-1,m-1);
    }
}
int main(){
    fast_io;
    cin >> n >> m;
    for(ll i=1; i<=n; i++){
        cin >> a[i];
        d^=a[i];
    }
    for(ll i=1; i<=m; i++){
        cin >> b[i];
        d^=b[i];
    }
    if(d) return cout << "NO\n", 0;
    cout << "YES\n";
    solve(n,m);
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=m; j++){
            cout << c[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}