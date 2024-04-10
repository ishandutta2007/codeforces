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
#define SIZE 2048
#define MOD 1000000007
char s1[SIZE],s2[SIZE];
int eequal[SIZE];
long long dp[200000][2];
int main(){
    int i,j,k,n,len,cnt=0;
    scanf("%s%s%d",s1,s2,&k);
    len=strlen(s1);
    for(i=0;i<len;i++)s1[i+len]=s1[i];
    for(i=0;i<len;i++){
        if(strncmp(s1+i,s2,len)==0)eequal[i]=1,cnt++;
    }
    dp[0][0]=1;
    for(i=1;i<=k;i++){
        dp[i][0]=dp[i-1][1]*(len-1);
        dp[i][1]=dp[i-1][0]+dp[i-1][1]*(len-2);
        dp[i][0]%=MOD;
        dp[i][1]%=MOD;
    }
    long long res=dp[k][0]*(eequal[0]==1)+dp[k][1]*(cnt-(eequal[0]==1));
    res%=MOD;
    cout<<res<<endl;
    return 0;
}