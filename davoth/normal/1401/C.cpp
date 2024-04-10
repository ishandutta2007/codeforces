#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#pragma GCC optimize("O2")
/*#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e6+10,LN=20,M=1e3+10,SQ=600,inf=1e9;
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
ll t;
int main(){
    fast_io;
    cin >> t;
    while(t--){
        ll n,f=1;
        cin >> n;
        ll a[n],b[n];
        map<ll,ll> l,r;
        for(ll i=0; i<n; i++){
            cin >> a[i];
            b[i]=a[i];
        }
        sort(b,b+n);
        for(ll i=0; i<n; i++) r[b[i]]=i;
        for(ll i=n; i--;) l[b[i]]=i;
        for(ll i=0; i<n; i++) if(a[i]%b[0] && (i>r[a[i]] || i<l[a[i]])) f=0;
        if(f) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}