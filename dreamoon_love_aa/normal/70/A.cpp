#include<stdio.h>
#define MOD 1000003
#define SIZE 1024
int dp[SIZE];
main(){
    int n,i;
    dp[0]=1;
    dp[1]=1;
    for(i=2;i<SIZE;i++)
        dp[i]=(dp[i-1]*3)%MOD;
    scanf("%d",&n);
    printf("%d\n",dp[n]);
}