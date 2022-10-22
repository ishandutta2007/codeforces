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
const int N=2e5+10,LN=20,M=5e1+1,SQ=450,inf=1e9;
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
ll n,m,q,a[N];
string s,t;
int main(){
    fast_io;
    cin >> n >> m >> q >> s >> t;
    if(m>n){
        while(q--) cout << 0 << '\n';
        return 0;
    }
    for(ll i=0; i<=n-m; i++){
        bool f=1;
        for(ll j=i; j<i+m; j++) if(t[j-i]!=s[j]) f=0;
        a[i+1]=f;
        a[i+1]+=a[i];
    }
    for(ll i=n-m+2; i<=n; i++) a[i]=a[i-1];
    while(q--){
        ll l,r;
        cin >> l >> r;
        cout << max(0ll,a[max(0ll,r-m+1)]-a[l-1]) << '\n';
    }
    return 0;
}