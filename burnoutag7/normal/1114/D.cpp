#include<bits/stdc++.h>
using namespace std;

int n;
int c[5005];
int dp[5005][5005][2];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j][1]=dp[i][j][0]=1e9;
        }
        dp[i][i][1]=dp[i][i][0]=0;
    }
    for(int i=n;i>=1;i--){
        for(int j=i+1;j<=n;j++){
            dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][0]+(c[i]!=c[i+1]));
            dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][1]+(c[i]!=c[j]));
            dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][0]+(c[j]!=c[i]));
            dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][1]+(c[j]!=c[j-1]));
        }
    }
    cout<<min(dp[1][n][0],dp[1][n][1])<<endl;

    return 0;
}