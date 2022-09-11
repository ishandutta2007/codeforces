#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
int n;
long long dp[2001];
void Go(int x,int y){
    int i,k;
    for(i=n-1;i>=0;i--){
        if(dp[i]!=-1){
            k=min(i+x+1,n);
            if(dp[k]==-1||dp[k]>dp[i]+y)dp[k]=dp[i]+y;
        }
    }
}
main(){
    int i,x,y;
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&x,&y);
        Go(x,y);
    }
    cout<<dp[n]<<endl;
}