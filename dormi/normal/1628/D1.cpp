#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=2001;
const ll mod=1e9+7;
ll fp(ll a, ll b){
    ll ans=1;
    for(ll i=1;i<=b;i<<=1){
        if(b&i)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
ll dp[MN][MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    ll div2=fp(2,mod-2);
    while(t--){
        int n,m;
        ll k;
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=min(i,m);j++){
                if(j==i){
                    dp[i][j]=(dp[i-1][j-1]+k)%mod;
                }
                else {
                    dp[i][j] = (((dp[i - 1][j] - dp[i - 1][j - 1] + mod) % mod) * div2 % mod + dp[i - 1][j - 1]) % mod;
                }
            }
        }
        printf("%lli\n",dp[n][m]);
    }
    return 0;
}