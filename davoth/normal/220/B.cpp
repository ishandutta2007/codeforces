#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
using ld = long double;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10,LN=18,M=1.1e7+10,SQ=350,B=737,inf=1e9+10;
const ll INF=1e15;
const int MH=1000696969,MOD=/*1000000007*/ 998244353;
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
ll n,m,a[N],L[N],R[N],ans[N],s,pm[N];
vector<ll> qu,c;
bool cmp(ll a, ll b){
    if(L[a]/SQ==L[b]/SQ) return R[a]<R[b];
    else return L[a]<L[b];
}
int main(){
    fast_io;
    cin >> n >> m;
    for(ll i=1; i<=n; i++){
        cin >> a[i];
        c.pb(a[i]);
    }
    sort(c.begin(),c.end());
    c.resize(unique(c.begin(),c.end())-c.begin());
    for(ll i=1; i<=n; i++) a[i]=lower_bound(c.begin(),c.end(),a[i])-c.begin();
    for(ll i=1; i<=m; i++){
        cin >>L[i] >> R[i];
        qu.pb(i);
    }
    ll l=1,r=1;
    pm[a[1]]++;
    if(c[a[1]]==1) s++;
    sort(qu.begin(),qu.end(),cmp);
    for(ll i : qu){
        while(l<L[i]){
            if(pm[a[l]]==c[a[l]]) s--;
            pm[a[l]]--;
            if(pm[a[l]]==c[a[l]]) s++;
            l++;
        }
        while(l>L[i]){
            l--;
            if(pm[a[l]]==c[a[l]]) s--;
            pm[a[l]]++;
            if(pm[a[l]]==c[a[l]]) s++;
        }
        while(r>R[i]){
            if(pm[a[r]]==c[a[r]]) s--;
            pm[a[r]]--;
            if(pm[a[r]]==c[a[r]]) s++;
            r--;
        }
        while(r<R[i]){
            r++;
            if(pm[a[r]]==c[a[r]]) s--;
            pm[a[r]]++;
            if(pm[a[r]]==c[a[r]]) s++;
        }
        ans[i]=s;
    }
    for(ll i=1; i<=m; i++) cout << ans[i] << '\n';
    return 0;
}