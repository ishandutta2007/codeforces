#include <bits/stdc++.h>
using namespace std;
int n,m;
long long dp[40][40];
long long ans;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    dp[0][0]=1;
    for (int i=1;i<=n;++i) {
        for (int z=1;z<=i;++z)
        for (int j=1;j<=i;++j) {
            long long res1=dp[z-1][j-1];
            for (int k=0;k<=j-1;++k)
                dp[i][j]=(dp[i][j]+res1*dp[i-z][k]);
            for (int k=0;k<j-1;++k)
                dp[i][j]=(dp[i][j]+dp[i-z][j-1]*dp[z-1][k]);
        }
    }
    for (int i=m;i<=n;++i)
        ans+=dp[n][i];
    cout<<ans;
}