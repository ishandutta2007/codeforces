#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
/*#pragma comment(linker, "/stack:200000000")
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
//#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e6+10,LN=20,M=5e6,SQ=350,B=737,inf=1e9+10;
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
ll t,n;
string s;
int main(){
    fast_io;
    cin >> t;
    while(t--){
        cin >> n >> s;
        ll x=-1;
        for(ll i=0; i<n; i++){
            if(s[i]!='?'){
                x=i;
                break;
            }
        }
        if(x==-1){
            for(ll i=1; i<=n; i++){
                if(i&1){
                    cout << 'B';
                }else cout << 'R';
            }
            cout << '\n';
        }else{
            if(x&1){
                if(s[x]=='B') s[0]='R';
                else s[0]='B';
            }else s[0]=s[x];
            for(ll i=1; i<n; i++) if(s[i]=='?'){
                if(s[i-1]=='B') s[i]='R';
                else s[i]='B';
            }
            cout << s << '\n';
        }
    }
    return 0;
}