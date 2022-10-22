#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=3e5+10,LN=20,SQ=550,M=5e4+10;
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
ll n,q,a[N];
map<ll,ll> mp;
int main(){
    fast_io;
    cin >> q;
    while(q--){
        cin >> n;
        for(ll i=1; i<=n; i++) cin >> a[i];
        ll l=1,r=n+1;
        while(r-l>1){
            bool c=true;
            ll m=(l+r)/2;
            deque<ll> dq;
            mp.clear();
            for(ll i=1; i<m; i++){
                while(!dq.empty() && a[dq.back()]>=a[i]) dq.pop_back();
                dq.push_back(i);
            }
            for(ll i=m; i<=n; i++){
                while(!dq.empty() && i-dq.front()>=m) dq.pop_front();
                while(!dq.empty() && a[dq.back()]>=a[i]) dq.pop_back();
                dq.push_back(i);
                if(mp[a[dq.front()]] || a[dq.front()]>n-m+1) c=false;
                mp[a[dq.front()]]=1;
                //cout << i << ' ' << m << ' ' << a[dq.front()] << '\n';
            }
            if(c) r=m;
            else l=m;
        }
        mp.clear();
        bool d=true;
        for(ll i=1; i<=n; i++){
            if(mp[a[i]]) d=false;
            mp[a[i]]=1;
        }
        cout << d;
        for(ll i=2; i<=n; i++) cout << (i>=r);
        cout << '\n';
    }
    return 0;
}