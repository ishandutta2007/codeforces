#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=5e3+10,LN=20,SQ=547,M=1e6+10;
const ll INF=1e16;
const int MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<pair<pll,ll>, null_type,less<pair<pll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,dp[N][26],su[N],ans,C[N][N];
string s;
ll ch(ll x, ll y){
    if(C[x][y]!=-1) return C[x][y];
    if(y==0) return C[x][y]=1;
    if(x==y) return C[x][y]=1;
    if(y>x) return C[x][y]=0;
    return C[x][y]=(ch(x-1,y)+ch(x-1,y-1))%MOD;
}
int main(){
    fast_io;
    cin >> n >> s;
    memset(C,-1,sizeof C);
    su[0]=1;
    for(ll i=1; i<=n; i++){
        for(ll j=i; j>0; j--){
            su[j]=(su[j]+MOD-dp[j][s[i-1]-'a'])%MOD;
            dp[j][s[i-1]-'a']=(su[j-1]-dp[j-1][s[i-1]-'a']+MOD)%MOD;
            su[j]=(su[j]+dp[j][s[i-1]-'a'])%MOD;
        }
    }
    for(ll i=1; i<=n; i++){
        for(ll j=0; j<26; j++) ans=(ans+dp[i][j]*ch(n-1,i-1)%MOD)%MOD;
    }
    cout << ans << '\n';
    return 0;
}