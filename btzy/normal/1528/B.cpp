#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int MAXN = 1000001;
constexpr int MOD = 998244353;
int numfact[MAXN],dp[MAXN];
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;j+=i){
            ++numfact[j];
        }
    }
    int cumsum=0;
    for(int i=1;i<=n;++i){
        dp[i]=(cumsum+numfact[i])%MOD;
        cumsum+=dp[i];
        cumsum%=MOD;
    }
    cout<<dp[n]<<'\n';
}