#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=3e5+10,LN=22,SQ=550,M=5e4+10;
const ll INF=1e18;
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
ll t,n,q,a[N],p[N];
map<ll,ll> mp;
void dfs(ll l, ll r){
    ll tl=lower_bound(a+1,a+n+1,l)-a,tr=upper_bound(a+1,a+n+1,r)-a-1;
    if(tl>tr) return;
    //cout << l << ' ' << r << endl;
    mp[p[tr]-p[tl-1]]=1;
    r=a[tr];
    l=a[tl];
    if(r==l) return;
    ll m=(l+r)/2;
    dfs(l,m);
    dfs(m+1,r);
}
int main(){
    fast_io;
    cin >> t;
    while(t--){
        cin >> n >> q;
        mp.clear();
        memset(a,0,n+10);
        memset(p,0,n+10);
        for(ll i=1; i<=n; i++) cin >> a[i];
        sort(a+1,a+n+1);
        for(ll i=1; i<=n; i++) p[i]=a[i]+p[i-1];
        dfs(a[1],a[n]);
        while(q--){
            ll s;
            cin >> s;
            if(mp[s]) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}