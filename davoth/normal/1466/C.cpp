#include <bits/stdc++.h>
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10,LN=20,SQ=550,M=5e4+10;
const ll INF=2e18;
const int MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<pair<pll,ll>, null_type,less<pair<pll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
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
        string s;
        cin >> s;
        ll n=s.size(),ans=0;
        for(ll i=0; i<n; i++){
            if(i>0 && s[i]==s[i-1]) s[i]='#',ans++;
            if(i>1 && s[i]==s[i-2] && s[i]!='#') s[i]='#',ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}