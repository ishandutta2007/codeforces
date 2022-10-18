#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=505;
const long long mdn=1000000007;

int n;
bool ok[maxn][maxn];
long long dp[maxn][maxn][2];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>ok[i][j];
        }
    }
    for(int i=1;i<=n;i++)dp[i][i][0]=dp[i][i][1]=1;
    for(int i=1;i<n;i++){
        if(ok[i][i+1])dp[i][i+1][0]=1;
    }
    for(int i=n;i>=1;i--){
        for(int j=i+1;j<=n;j++){
            for(int k=i;k<=j-1;k++){
                dp[i][j][1]=(dp[i][j][1]+dp[i][k][0]*dp[k+1][j][0])%mdn;
            }
            if(j>i+1){
                for(int k=i+1;k<=j;k++){
                    if(ok[i][k])dp[i][j][0]=(dp[i][j][0]+dp[i][k][1]*dp[k][j][0])%mdn;
                }
            }
            //cerr<<i<<j<<' '<<dp[i][j][0]<<'/'<<dp[i][j][1]<<endl;
        }
    }
    cout<<dp[1][n][0];
    return 0;
}