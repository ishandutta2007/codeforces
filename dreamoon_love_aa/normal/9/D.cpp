#include<iostream>
using namespace std;
long long dp[36][36];
main(){
    int n,h,i,j,k,l;
    dp[0][0]=1;
    for(i=1;i<36;i++){
        for(j=1;j<=i;j++)
            for(k=0;k<i;k++)dp[i][j]+=dp[k][j-1]*dp[i-k-1][(i-k-1==0)?0:1]+dp[k][(k==0)?0:1]*dp[i-k-1][j-1]-dp[k][j-1]*dp[i-k-1][j-1];
        dp[i][0]=dp[i][1];
    }
    cin>>n>>h;
    cout<<dp[n][h]<<endl;
}