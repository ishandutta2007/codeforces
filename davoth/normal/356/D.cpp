#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll=long long int;
using ld=long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=7e4+10,LN=20,M=1e6+10,SQ=350,B=737,inf=1e9;
const ll INF=1e18;
const ld ep=1e-7;
const int MH=1000696969,MD=998244353,MOD=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
int n,s,f[N];
vector<int> ans[N];
pll a[N];
bitset<N> d,b;
int main(){
    fast_io;
    cin >> n >> s;
    for(int i=1; i<=n; i++){
        cin >> a[i].F;
        a[i].S=i;
    }
    sort(a+1,a+n+1);
    s-=a[n].F;
    if(s<0){
        cout << -1 << '\n';
        return 0;
    }
    d[0]=1;
    for(int i=1; i<n; i++){
        b=d;
        d|=(d<<a[i].F);
        b^=d;
        for(int j=b._Find_first(); j<N; j=b._Find_next(j)){
            f[j]=i;
        }
        if(f[s]) break;
    }
    if(s && !f[s]){
        cout << -1 << '\n';
        return 0;
    }
    for(int i=s; i; i-=a[f[i]].F){
        int j=f[i];
        ans[a[j].S].pb(a[j].F);
    }
    int ls=-1;
    for(int i=1; i<=n; i++){
        if(!ans[a[i].S].empty()) continue;
        if(ls==-1){
            ans[a[i].S].pb(a[i].F);
        }else{
            ans[a[i].S].pb(a[i].F-a[ls].F);
            ans[a[i].S].pb(a[ls].S);
        }
        ls=i;
    }
    for(int i=1; i<=n; i++){
        cout << ans[i][0] << ' ' << ans[i].size()-1;
        if(ans[i].size()==2) cout << ' ' << ans[i][1];
        cout << '\n';
    }
    return 0;
}