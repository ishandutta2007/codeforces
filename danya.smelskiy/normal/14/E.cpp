#include <bits/stdc++.h>
using namespace std;

int n,t;
long long dp[25][25][25];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>t;
    dp[1][1][0]=dp[1][2][0]=dp[1][3][0]=dp[1][4][0]=1;
    for (int i=1;i<n;++i) {
        for (int j=1;j<=4;++j) {
            for (int k=0;k<=t+t;++k) if (dp[i][j][k]) {
                if (k&1) {
                    for (int to=1;to<=4;++to)
                        if (to>j) dp[i+1][to][k]+=dp[i][j][k];
                        else if (to<j && i>1) dp[i+1][to][k+1]+=dp[i][j][k];
                } else {
                    for (int to=1;to<=4;++to)
                        if (to>j) dp[i+1][to][k+1]+=dp[i][j][k];
                        else if (to<j && i>1) dp[i+1][to][k]+=dp[i][j][k];
                }
            }
        }
    }
    long long ans=0;
    for (int i=1;i<=4;++i)
        ans+=dp[n][i][t+t];
    cout<<ans;
}