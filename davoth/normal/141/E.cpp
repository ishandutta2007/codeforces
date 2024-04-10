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
const int N=1e5+10,LN=20,M=1e6+10,SQ=350,B=737,inf=1e9;
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
ll n,m,V[N],U[N],C[N],p[N],t;
vector<ll> ans;
ll gp(ll x){
    return p[x]?p[x]=gp(p[x]):x;
}
bool uni(ll i){
    ll v=gp(V[i]),u=gp(U[i]);
    if(v==u) return 0;
    p[u]=v;
    return 1;
}
int main(){
    fast_io;
    cin >> n >> m;
    if(n%2==0){
        cout << -1 << '\n';
        return 0;
    }
    t=n;
    for(int i=1; i<=m; i++){
        char c;
        cin >> V[i] >> U[i] >> c;
        if(c=='S') C[i]=1;
        else{
            t-=uni(i);
        }
    }
    if(t-1>n/2){
        cout << -1 << '\n';
        return 0;
    }
    for(int i=1; i<=m; i++){
        if(C[i]){
            if(uni(i)){
                t--;
                ans.pb(i);
            }
        }
    }
    if(t!=1){
        cout << -1 << '\n';
        return 0;
    }
    memset(p,0,sizeof p);
    t=n;
    for(int i : ans){
        uni(i);
        t--;
    }
    for(int i=1; i<=m; i++){
        if(t>n/2+1 && C[i]){
            if(uni(i)){
                t--;
                ans.pb(i);
            }
        }
    }
    if(t!=n/2+1){
        cout << -1 << '\n';
        return 0;
    }
    for(int i=1; i<=m; i++){
        if(!C[i]){
            if(uni(i)){
                t--;
                ans.pb(i);
            }
        }
    }
    if(ans.size()!=n-1){
        cout << -1 << '\n';
        return 0;
    }
    cout << n-1 << '\n';
    for(int i : ans) cout << i << ' ';
    cout << '\n';
    return 0;
}