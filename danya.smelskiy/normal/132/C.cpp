#include <bits/stdc++.h>
using namespace std;

string s;
int n;
int dp[150][150][2];
int dp2[150][150][2];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>n;
    int m=s.size();
    for (int i=0;i<=m;++i)
    for (int j=0;j<=n;++j) {
        dp[i][j][0]=dp[i][j][1]=-1e9;
        dp2[i][j][0]=dp2[i][j][1]=1e9;
    }
    dp[0][0][0]=dp[0][0][1]=0;
    dp2[0][0][0]=dp2[0][0][1]=0;
    for (int i=0;i<m;++i)
    for (int j=0;j<=n;++j) {
    for (int k=0;k<=1;++k) if (abs(dp[i][j][k])!=1e9) {
        if (s[i]=='F') {
            if (k==0) dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]+1);
            else dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]-1);
            dp[i+1][j+1][1-k]=max(dp[i+1][j+1][1-k],dp[i][j][k]);
        } else {
            dp[i+1][j][1-k]=max(dp[i+1][j][1-k],dp[i][j][k]);
            if (k==0) dp[i+1][j+1][k]=max(dp[i+1][j+1][k],dp[i][j][k]+1);
            else dp[i+1][j+1][k]=max(dp[i+1][j+1][k],dp[i][j][k]-1);
        }
    }
    }
    for (int i=0;i<m;++i)
    for (int j=0;j<=n;++j) {
    for (int k=0;k<=1;++k) if (abs(dp2[i][j][k])!=1e9) {
        if (s[i]=='F') {
            if (k==0) dp2[i+1][j][k]=min(dp2[i+1][j][k],dp2[i][j][k]+1);
            else dp2[i+1][j][k]=min(dp2[i+1][j][k],dp2[i][j][k]-1);
            dp2[i+1][j+1][1-k]=min(dp2[i+1][j+1][1-k],dp2[i][j][k]);
        } else {
            dp2[i+1][j][1-k]=min(dp2[i+1][j][1-k],dp2[i][j][k]);
            if (k==0) dp2[i+1][j+1][k]=min(dp2[i+1][j+1][k],dp2[i][j][k]+1);
            else dp2[i+1][j+1][k]=min(dp2[i+1][j+1][k],dp2[i][j][k]-1);
        }
    }
    }
    int ans=0;
    for (int i=0;i<=n;++i) if (i%2==n%2){
        if (abs(dp[m][i][0])!=1e9) ans=max(ans,abs(dp[m][i][0]));
        if (abs(dp[m][i][1])!=1e9) ans=max(ans,abs(dp[m][i][1]));
        if (abs(dp2[m][i][0])!=1e9) ans=max(ans,abs(dp2[m][i][1]));
        if (abs(dp2[m][i][1])!=1e9) ans=max(ans,abs(dp2[m][i][0]));
    }
    cout<<ans;
}