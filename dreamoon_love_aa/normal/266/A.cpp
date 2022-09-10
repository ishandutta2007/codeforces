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
char s[64];
int dp[64];
int main(){
    int i,j,k,n,an=0;
    scanf("%d",&n);
    scanf("%s",s+1);
    dp[0]=0;
    for(i=1;i<=n;i++){
        dp[i]=1;
        for(j=0;j<i;j++)
            if(s[i]!=s[j])dp[i]=max(dp[i],dp[j]+1);
        an=max(an,dp[i]);
    }
    printf("%d\n",n-an);
    return 0;
}