#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const ll N=3e3+10,LN=20,SQ=550,M=5e4+10;
const ll INF=1e16;
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
ll t,n,q;
string s;
int main(){
    fast_io;
    cin >> t;
    while(t--){
        cin >> n >> q >> s;
        for(ll i=0; i<q; i++){
            ll l,r;
            bool b=0;
            cin >> l >> r;
            char c=s[r-1];
            for(ll j=r; j<n; j++) if(s[j]==c) b=1;
            c=s[l-1];
            for(ll j=0; j<l-1; j++) if(s[j]==c) b=1;
            if(b) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}