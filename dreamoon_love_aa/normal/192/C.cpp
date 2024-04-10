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
int N,dp[26][26];
struct data{
    int x,y,len;
}a[1000000];
int main(){
    int i,j,k;
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        char s[222];
        scanf("%s",s);
        a[i]=(data){s[0]-'a',s[strlen(s)-1]-'a',strlen(s)};
    }
    memset(dp,-1,sizeof(dp));
    for(i=1;i<=N;i++){
        for(j=0;j<26;j++){
            if(dp[j][a[i].x]>=0)dp[j][a[i].y]=max(dp[j][a[i].y],dp[j][a[i].x]+a[i].len);
        }
        dp[a[i].x][a[i].y]=max(dp[a[i].x][a[i].y],a[i].len);
    }
    int an=0;
    for(i=0;i<26;i++)an=max(an,dp[i][i]);
    printf("%d\n",an);
    return 0;
}