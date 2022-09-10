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
#define SIZE 100010
using namespace std;
int n,a[SIZE];
long long dp[SIZE][2][4];
void fresh(long long &x,long long v){
    if(x<v)x=v;
}
int main(){
    int i,j,k;
    long long an=0;
    scanf("%d",&n);
    for(i=1;i<n;i++)cin>>a[i];
    memset(dp,-1,sizeof(dp));
    dp[0][0][0]=0;
    for(i=1;i<n;i++){
        fresh(dp[i][0][0],0);
        for(j=0;j<2;j++)
            for(k=0;k<3;k++){
                int flag1=(j^a[i])&1;
                if(dp[i-1][j][k]!=-1){
                    fresh(dp[i][a[i]&1][k+flag1],dp[i-1][j][k]+a[i]);
                }
                if(a[i]!=1){
                    int flag2=(j^(a[i]-1))&1;
                    if(dp[i-1][j][k]!=-1){
                        fresh(dp[i][(a[i]&1)^1][k+flag2],dp[i-1][j][k]+a[i]-1);
                    }
                }
            }
        for(j=0;j<2;j++)
            for(k=0;k<3;k++)fresh(an,dp[i][j][k]);
    }
    cout<<an<<endl;
    return 0;
}