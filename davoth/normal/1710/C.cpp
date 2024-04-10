/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
using ld=long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
using point=complex<double>;
#define F first
#define S second
//#define X real()
//#define Y imag()
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define kill(x) cout << x << '\n';exit(0)
#define killshayan kill("done!")
#define killmashtali kill("Hello, World!")
const int N=2e5+10,LN=20,M=1e6+10,SQ=700,BS=737,inf=1.05e9,NSQ=N/SQ+3;
const ll INF=1e18;
const double pi=acos(-1);
const ld ep=1e-7;
const int MH=1000696969,MD=998244353,MOD=1000000007;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pii, null_type,greater<pii>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
string s;
ll dp[2][8][8],n,ans;
int main(){
    fast_io;
    cin >> s;
    n=s.size();
    dp[0][7][7]=1;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<8; j++){
            for(ll k=0; k<8; k++){
                for(ll bt=0; bt<8; bt++){
                    ll a=bt>>2,b=(bt>>1)&1,c=bt&1,x=(a^b)*4+(b^c)*2+(c^a);
                    if(s[i]=='0'){
                        if((a && (j&4)) || (b && (j&2)) || (c && (j&1))){
                            continue;
                        }
                    }
                    ll y=j&bt;
                    if(s[i]=='0') y=j;
                    if(x==0) x=7;
                    dp[1][y][k&x]=(dp[1][y][k&x]+dp[0][j][k])%MD;
                }
            }
        }
        for(ll j=0; j<8; j++){
            for(ll k=0; k<8; k++){
                dp[0][j][k]=dp[1][j][k];
                dp[1][j][k]=0;
            }
        }
    }
    for(ll i=0; i<8; i++) ans=(ans+dp[0][i][0])%MD;
    cout << ans << '\n';
    return 0;
}