#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
const int mod = 1e9+7;
int dp[maxn];
int sum[maxn];
int main(){
    int t,k;
    scanf("%d%d",&t,&k);
    dp[0] = 1;
    for (int i=1;i<maxn;i++){
        //red
        (dp[i] += dp[i-1])%= mod;
        //white
        if (i-k >=0)
            (dp[i] += dp[i-k])%= mod;

        sum[i] = (sum[i-1] + dp[i]) % mod;
    }
    while (t--){
        int a,b;
        scanf("%d%d",&a,&b);
        int ans = (sum[b] - sum[a-1])%mod;
        (ans += mod) %= mod;
        printf("%d\n",ans);
    }
    return 0;
}