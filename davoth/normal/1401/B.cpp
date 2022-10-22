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
        ll x1,y1,z1,x2,y2,z2,ans=0,g;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        g=x1;
        x1=max(0ll,x1-z2);
        z2=max(0ll,z2-g);
        g=y1;
        y1=max(0ll,y1-x2);
        x2=max(0ll,x2-g);
        g=y1;
        y1=max(0ll,y1-y2);
        y2=max(0ll,y2-g);
        g=min(z1,y2);
        ans+=g;
        z1-=g;
        y2-=g;
        g=z1;
        z1=max(0ll,z1-z2);
        z2=max(0ll,z2-g);
        g=min(y1,z2);
        ans-=g;
        cout << ans*2 << '\n';
    }
    return 0;
}