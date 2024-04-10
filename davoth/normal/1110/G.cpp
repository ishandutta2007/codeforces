#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
using ld = long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define F first
#define S second
#define pb push_back
//#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e6+10,LN=19,M=5e6,SQ=350,B=737,inf=1e9+10;
const ll INF=1e18;
const ld ep=1e-7;
const int MH=1000696969,MD=1000000007,MOD=998244353;
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
ll t,n,m,d;
string s;
vector<ll> adj[N];
bool solve(){
    cin >> n;
    m=n;
    for(ll i=1; i<=n*4; i++) adj[i]={};
    for(ll i=1; i<n; i++){
        ll v,u;
        cin >> v >> u;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    cin >> s;
    for(ll i=1; i<=n; i++){
        if(s[i-1]=='W'){
            adj[i].pb(m+1);
            adj[m+1].pb(i);
            adj[m+1].pb(m+2);
            adj[m+2].pb(m+1);
            adj[m+1].pb(m+3);
            adj[m+3].pb(m+1);
            m+=3;
        }
    }
    n=m;
    d=0;
    for(ll i=1; i<=n; i++){
        if(adj[i].size()>3) return true;
        if(adj[i].size()==3){
            d++;
            ll x=0;
            for(ll j : adj[i]) if(adj[j].size()>1) x++;
            if(x>1) return true;
        }
    }
    return (d==2 && n%2);
}
int main(){
    fast_io;
    cin >> t;
    while(t--){
        if(solve()) cout << "White\n";
        else cout << "Draw\n";
    }
    return 0;
}