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
const int N=1e6+10,LN=24,M=1e7+10,SQ=500,B=737,inf=1e9;
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
ll n,k;
vector<ll> wut;
string s,ans;
void solve(vector<ll> v){
    if(v.empty()) return;
    vector<ll> t[26];
    for(ll i : v) if(i<n) t[s[i]-'a'].pb(i+1);
    for(ll i=0; i<26; i++){
        ans.pb('a'+i);
        k-=t[i].size();
        if(k<=0){
            cout << ans << '\n';
            exit(0);
        }
        solve(t[i]);
        ans.pop_back();
    }
}
int main(){
    fast_io;
    cin >> s >> k;
    n=s.size();
    if(k>n*(n+1)/2){
        cout << "No such line.\n";
        return 0;
    }
    for(ll i=0; i<n; i++) wut.pb(i);
    solve(wut);
    return 0;
}