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
using namespace std;
int dp[201][40001][2],d[201];
bool fresh(int &x,int v){
    if(v==-1)return 0;
    if(x==-1||x>v){
        x=v;
        return 1;
    }
    return 0;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,k,n,a,b,sum=0;
    memset(dp,-1,sizeof(dp));
    scanf("%d",&n);
    scanf("%d%d",&a,&b);
    for(i=1;i<=n;i++){scanf("%d",&d[i]);sum+=d[i];}
    dp[1][0][0]=dp[1][d[1]][1]=0;
    for(i=1;i<n;i++){
        for(j=0;j<=a;j++){
            if(dp[i][j][1]!=-1){
                fresh(dp[i+1][j+d[i+1]][1],dp[i][j][1]);
                fresh(dp[i+1][j][0],dp[i][j][1]+min(d[i],d[i+1]));
            }
            if(dp[i][j][0]!=-1){
                fresh(dp[i+1][j][0],dp[i][j][0]);
                fresh(dp[i+1][j+d[i+1]][1],dp[i][j][0]+min(d[i],d[i+1]));
            }
        }
    }
    int an=-1;
    for(i=0;i<=a;i++){
        if(sum-i<=b){
            fresh(an,dp[n][i][0]);
            fresh(an,dp[n][i][1]);
        }
    }
    printf("%d\n",an);
    return 0;
}