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
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e6+10,LN=20,M=1.1e7+10,SQ=350,B=737,inf=1e9;
const ll INF=1e18;
const int MH=1000696969,MOD=1000000007  /*998244353*/;
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
ll t,n,l,r,x;
vector<ll> ans;
int main(){
    fast_io;
    cin >> t;
    while(t--){
        ans={};
        x=0;
        cin >> n >> l >> r;
        for(ll i=1; i<n; i++){
            if(l>x+(n-i)*2 || x>=r) x+=(n-i)*2;
            else{
                for(ll j=i+1; j<=n; j++){
                    x++;
                    if(x>=l && x<=r) ans.pb(i);
                    x++;
                    if(x>=l && x<=r) ans.pb(j);
                }
            }
        }
        x++;
        if(x>=l && x<=r) ans.pb(1);
        for(ll i : ans) cout << i << ' ';
        cout << '\n';
    }
    return 0;
}