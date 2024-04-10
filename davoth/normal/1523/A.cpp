#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
const int N=2e3+10,LN=18,M=3.5e7+10,SQ=350,BS=737,inf=1e9+10;
const ll INF=1e15;
const int MH=1000696969,MOD=1000000007,MD=998244353;
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
ll t,n,m;
string s;
int main(){
    fast_io;
    cin >> t;
    while(t--){
        ll d1[N],d2[N];
        memset(d1,63,sizeof d1);
        memset(d2,63,sizeof d2);
        cin >> n >> m >> s;
        for(ll i=0; i<n; i++){
            if(s[i]=='1'){
                for(ll j=0; j<n; j++){
                    ll w=abs(i-j);
                    if(w<=d1[j]) d2[j]=d1[j],d1[j]=w;
                    else if(w<d2[j]) d2[j]=w;
                }
            }
        }
        for(ll i=0; i<n; i++){
            if(d1[i]<=m && d1[i]!=d2[i]) cout << 1;
            else cout << 0;
        }
        cout << '\n';
    }
    return 0;
}