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
const int N=5e5+10,LN=18,M=3.5e7+10,SQ=350,BS=737,inf=1e9+10;
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
ll n,m,p,ans,an,dp[20][N],a[N];
mt19937 rng(time(0));
string ns;
vector<ll> vec;
int main(){
    fast_io;
    cin >> n >> m >> p;
    for(ll i=1; i<=n; i++){
        string s;
        cin >> s;
        for(ll j=0; j<m; j++){
            if(s[j]=='1') a[i]+=(1ll<<j);
        }
    }
    srand(time(0));
    for(ll t=1; t<=40; t++){
        ll k=rng()%n+1,f;
        vec={};
        for(ll i=0; i<m; i++) if((a[k]&(1ll<<i))) vec.pb(i);
        f=vec.size();
        if(!f) continue;
        memset(dp,0,sizeof dp);
        for(ll i=1; i<=n; i++){
            ll x=0;
            for(ll j=0; j<f; j++){
                if((a[i]&(1ll<<vec[j]))) x+=(1ll<<j);
            }
            dp[0][x]++;
        }
        for(ll i=0; i<f; i++){
            for(ll j=0; j<(1ll<<f); j++){
                if((j&(1ll<<i))) dp[i+1][j]=dp[i][j];
                else dp[i+1][j]=dp[i][j]+dp[i][(j^(1ll<<i))];
            }
        }
        for(ll i=0; i<(1ll<<f); i++){
            if(dp[f][i]*2>=n){
                ll x=0,y=0;
                for(ll j=0; j<f; j++){
                    if(((1ll<<j)&i)){
                        x+=(1ll<<vec[j]);
                        y++;
                    }
                }
                if(y>an) ans=x,an=y;
            }
        }
    }
    for(ll i=0; i<m; i++){
        if(((1ll<<i)&ans)) ns.pb('1');
        else ns.pb('0');
    }
    cout << ns << '\n';
    return 0;
}