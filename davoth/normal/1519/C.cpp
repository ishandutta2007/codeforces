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
const int N=2e5+10,LN=20,M=1e5+4,SQ=350,B=737,inf=1e9;
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
ll t,n,u[N],cnt[N];
vector<ll> s[N],p[N];
int main(){
    fast_io;
    cin >> t;
    while(t--){
        cin >> n;
        vector<pll> cp;
        for(ll i=1; i<=n; i++) cnt[i]=0,s[i]={},p[i]={};
        for(ll i=1; i<=n; i++){
            cin >> u[i];
            cnt[u[i]]++;
        }
        for(ll i=1; i<=n; i++) cp.pb({cnt[u[i]],u[i]});
        sort(cp.begin(),cp.end());
        cp.resize(unique(cp.begin(),cp.end())-cp.begin());
        for(ll i=1; i<=n; i++){
            ll x;
            cin >> x;
            s[lower_bound(cp.begin(),cp.end(),mp(cnt[u[i]],u[i]))-cp.begin()+1].pb(x);
        }
        for(ll i=1; i<=cp.size(); i++){
            s[i].pb(0);
            ll x=0;
            sort(s[i].begin(),s[i].end());
            p[i].pb(0);
            for(ll j=1; j<s[i].size(); j++){
                x+=s[i][j];
                p[i].pb(x);
            }
        }
        ll l=1;
        for(ll i=1; i<=n; i++){
            ll x=0;
            while(l<=cp.size() && s[l].size()<i) l++;
            for(ll j=l; j<=cp.size(); j++){
                x+=p[j][s[j].size()-1]-p[j][(s[j].size()-1)%i];
            }
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}