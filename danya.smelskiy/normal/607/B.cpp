#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;

int n;
int a[505];
int dp[505][505][5];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n-i+1;++j) {
            if (i==1) { dp[j][j][1]=1; dp[j][j][0]=1;}
            else if (i==2) {
                dp[j][j+1][0]=2;
                if (a[j]==a[j+1]) dp[j][j+1][1]=1;
            } else {
                dp[j][j+i-1][0]=inf;
                if (a[j]==a[j+i-1]) {
                    if (dp[j+1][i+j-2][1]) { dp[j][j+i-1][1]=dp[j+1][i+j-2][1]; dp[j][j+i-1][0]=min(dp[j][j+i-1][0],dp[j+1][i+j-2][1]); }
                    else { dp[j][j+i-1][1]=dp[j+1][i+j-2][0]+1; dp[j][j+i-1][0]=min(dp[j+1][j+i-1][0],dp[j+1][i+j-2][0]+1);}
                    int r=i+j-1;
                    for (int k=j+1;k<r;++k) {
                        if (dp[j+1][k][1]) {
                            int x=dp[j+1][k][1];
                            int  y=dp[k+1][r-1][0];
                            if (dp[k+1][r-1][1]) y=min(y,dp[k+1][r-1][1]);
                            dp[j][r][1]=min(dp[j][r][1],x+y);
                            dp[j][r][0]=min(dp[j][r][0],x+y);
                        }
                        if (dp[k+1][r-1][1]) {
                            int x=dp[j+1][k][0];
                            if (dp[j+1][k][1]) x=min(x,dp[j+1][k][1]);
                            int y=dp[k+1][r-1][0];
                            if (dp[k+1][r-1][1]) y=min(y,dp[k+1][r-1][1]);
                            dp[j][r][1]=min(dp[j][r][1],x+y);
                            dp[j][r][0]=min(dp[j][r][0],x+y);
                        }
                    }
                }
                dp[j][j+i-1][0]=dp[j+1][j+i-2][0]+2;
                for (int k=j;k<i+j-1;++k){
                    int x=dp[j][k][0];
                    if (dp[j][k][1]) x=min(x,dp[j][k][1]);
                    int y=dp[k+1][j+i-1][0];
                    if (dp[k+1][j+i-1][1]) y=min(y,dp[k+1][j+i-1][1]);
                    dp[j][j+i-1][0]=min(dp[j][j+i-1][0],x+y);
                }
            }
        }
    }
    if (dp[1][n][1]) cout<<min(dp[1][n][0],dp[1][n][1])<<'\n';
    else cout<<dp[1][n][0];
}