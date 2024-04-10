#include <bits/stdc++.h>
using namespace std;

int n,m,k1,k2;
long long dp[101][101][5];
int main(){
    cin>>n>>m>>k1>>k2;
    dp[0][0][0]=1;
    dp[0][0][1]=1;
    for (int i=0;i<=n;++i){
        for (int j=0;j<=m;++j) {
            for (int k=1;k<=k1;++k){
                if (k+i>n) break;
                dp[i+k][j][0]+=dp[i][j][1];
                dp[i+k][j][0]%=100000000;
            }
            for (int k=1;k<=k2;++k){
                if (k+j>m) break;
                dp[i][j+k][1]+=dp[i][j][0];
                dp[i][j+k][1]%=100000000;
            }
        }
    }
    cout<<(dp[n][m][0]+dp[n][m][1])%100000000;
}