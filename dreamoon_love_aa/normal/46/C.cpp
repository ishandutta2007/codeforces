#include<stdio.h>
int dp[1024];
main(){
    int n,i,an=12024;
    char s[1024];
    scanf("%d",&n);
    scanf("%s",s+1);
    for(i=1;i<=n;i++){
        if(s[i]=='H')dp[i]=dp[i-1];
        else dp[i]=dp[i-1]+1;
    }
    for(i=dp[n];i<=n;i++)
        if(an>dp[n]-(dp[i]-dp[i-dp[n]]))an=dp[n]-(dp[i]-dp[i-dp[n]]);
    for(i=n-dp[n];i<=n;i++)
        if(an>dp[i]-dp[i-n+dp[n]])an=dp[i]-dp[i-n+dp[n]];
    printf("%d\n",an);
}