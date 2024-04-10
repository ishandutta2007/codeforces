#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e5+10,LN=30,SQ=550,M=1e6+10;
const ll INF=1e16;
const int MOD=1000000007 /*998244353*/;
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
ll n,f[N],k,sz[N];
string s;
vector<pll> ans;
int main(){
    fast_io;
    cin >> s;
    n=s.size();
    sz[1]=1;
    for(ll i=2; i<=n; i++){
        while(k && s[k]!=s[i-1]) k=f[k];
        if(s[k]==s[i-1]) k++;
        sz[i]=1;
        f[i]=k;
    }
    for(ll i=n; i>=2; i--) sz[f[i]]+=sz[i];
    ll x=n;
    while(x){
        ans.emplace_back(x,sz[x]);
        x=f[x];
    }
    cout << ans.size() << '\n';
    for(ll i=ans.size()-1; i>=0; i--) cout << ans[i].F << ' ' << ans[i].S << '\n';
    return 0;
}