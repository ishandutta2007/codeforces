#include <bits/stdc++.h>
using namespace std;
int dp[2001][2001];
int n,m;
long long ans;
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        dp[1][i]=1;
    for (int j=1;j<m;++j)
    for (int i=1;i<=n;++i){
        if (dp[j][i]!=0){
            int x=1;
            while (i*x<=n){
                dp[j+1][i*x]=(dp[j][i]+dp[j+1][i*x])%1000000007;
                ++x;
            }
        }
    }
    for (int i=1;i<=n;++i){
        ans=(ans+dp[m][i])%1000000007;
    }
    cout<<ans;
}