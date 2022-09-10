#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
#define MOD  7340033
using namespace std;
int dp[31][4][1001];
int main(){
    int i,j,k,n,q;
    for(i=0;i<4;i++)dp[0][i][0]=1;
    for(i=1;i<31;i++){
        dp[i][0][0]=1;
        for(j=1;j<=1000;j++)dp[i][0][j]=dp[i-1][3][j-1];
        for(j=1;j<4;j++){
            for(k=0;k<=1000;k++)
                for(int k2=0;k2<=k;k2++){
                    dp[i][j][k]+=(long long)dp[i][j-1][k2]*dp[i][0][k-k2]%MOD;
                    if(dp[i][j][k]>=MOD)dp[i][j][k]-=MOD;
                }
        }
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&n,&k);
        j=0;
        while(n!=1&&n%2==1){
            j++;
            n/=2;
        }
        printf("%d\n",dp[j][0][k]);
    }
    return 0;
}