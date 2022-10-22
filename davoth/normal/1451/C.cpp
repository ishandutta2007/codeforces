#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const ll N=1e6+10,LN=20,SQ=550,M=5e4+10;
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
ll t,n,k,a[26],b[26];
int main(){
    fast_io;
    cin >> t;
    while(t--){
        cin >> n >> k;
        bool d=1;
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        for(ll i=0; i<n; i++){
            char c;
            cin >> c;
            ll x=c-'a';
            a[x]++;
        }
        for(ll i=0; i<n; i++){
            char c;
            cin >> c;
            ll x=c-'a';
            b[x]++;
        }
        for(ll i=0; i<26; i++){
            //cout << i << ' ' << a[i] << ' ' << b[i] << '\n';
            if(a[i]<b[i] || (a[i]-b[i])%k!=0) d=0;
            else a[i+1]+=a[i]-b[i];
        }
        if(d) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}