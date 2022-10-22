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
const int N=5e5+10,LN=20,M=1e6+10,SQ=750,B=737,inf=1e9;
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
ll n,q,b[SQ];
vector<pll> a[SQ];
int main(){
    fast_io;
    cin >> n >> q;
    for(ll i=0; i<n; i++){
        ll x;
        cin >> x;
        a[i/SQ].pb({x,i});
    }
    for(ll i=0; i<=(n-1)/SQ; i++) sort(a[i].begin(),a[i].end());
    while(q--){
        ll t;
        cin >> t;
        if(t==1){
            ll l,r,x,k,f;
            cin >> l >> r >> x;
            l--;
            r--;
            k=l/SQ;
            f=r/SQ;
            if(f==k){
                for(ll i=0; i<a[k].size(); i++){
                    if(a[k][i].S>=l && a[k][i].S<=r) a[k][i].F+=x;
                }
                sort(a[k].begin(),a[k].end());
            }else{
                for(ll i=0; i<a[k].size(); i++){
                    if(a[k][i].S>=l) a[k][i].F+=x;
                }
                sort(a[k].begin(),a[k].end());
                for(ll i=k+1; i<f; i++) b[i]+=x;
                for(ll i=0; i<a[f].size(); i++){
                    if(a[f][i].S<=r) a[f][i].F+=x;
                }
                sort(a[f].begin(),a[f].end());
            }
        }else{
            ll y,f=-1,g=-1;
            cin >> y;
            for(ll i=0; i*SQ<n; i++){
                auto it=lower_bound(a[i].begin(),a[i].end(),mp(y-b[i],0ll));
                if(it!=a[i].end() && it->F==y-b[i] && f==-1) f=it->S;
                it=lower_bound(a[i].begin(),a[i].end(),mp(y-b[i],n));
                if(it!=a[i].begin()){
                    it--;
                    if(it->F==y-b[i]) g=it->S;
                }
            }
            if(~f) cout << g-f << '\n';
            else cout << -1 << '\n';
        }
    }
    return 0;
}