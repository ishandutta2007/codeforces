#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=205;
int n[3];
int x[3][maxn];

int dp[maxn][maxn][maxn];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n[0]>>n[1]>>n[2];
    for(int i=0;i<3;i++){
        for(int j=1;j<=n[i];j++)cin>>x[i][j];
        sort(x[i]+1,x[i]+1+n[i],greater<int>());
    }
    for(int i=0;i<=n[0];i++){
        for(int j=0;j<=n[1];j++){
            for(int k=0;k<=n[2];k++){
                if(i==0&&j==0&&k==0)dp[i][j][k]=0;
                else{
                    if(i)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]);
                    if(j)dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]);
                    if(k)dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]);
                    if(i&&j)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+x[0][i]*x[1][j]);
                    if(j&&k)dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k-1]+x[2][k]*x[1][j]);
                    if(i&&k)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+x[0][i]*x[2][k]);
                }
            }
        }
    }
    cout<<dp[n[0]][n[1]][n[2]];
    return 0;
}