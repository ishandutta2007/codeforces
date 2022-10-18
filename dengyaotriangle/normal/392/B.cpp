#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int m=3;
const int maxn=44;

long long w[m][m],dp[maxn][m][m];
int n;

int main(){
    memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<m;i++)for(int j=0;j<m;j++)cin>>w[i][j];
    for(int i=0;i<m;i++)for(int j=0;j<m;j++)for(int k=0;k<m;k++)dp[1][i][j]=min(dp[1][i][j],w[i][k]+w[k][j]);
    cin>>n;
    for(int i=2;i<=n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<m;k++){
                if(j==k)dp[i][j][k]=0;
                else{
                    int s;for(int t=0;t<m;t++){if(t!=j&&t!=k)s=t;}
                    dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][s]+dp[i-1][s][k]+w[j][k]);
                    dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][k]+dp[i-1][k][j]+dp[i-1][j][k]+w[j][s]+w[s][k]);
                }
            }
        }
    }
    cout<<dp[n][0][2];
    return 0;
}