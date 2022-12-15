#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#define hash hassh
using namespace std;
char s[100005];
long long dp[100005];
int main() {
    scanf("%s",s);
    int f=1,l=strlen(s);
    for(int i=0;i<l;i++)
        if(s[i]=='m'||s[i]=='w')
            f=0;
    if(!f){
        puts("0");
        return 0;
    }
    dp[0]=1,dp[1]=1,dp[2]=2;
    long long mod=1e9+7;
    for(int i=3;i<=l;i++) dp[i]=dp[i-1]+dp[i-2],dp[i]%=mod;
    int cnt=(s[0]=='n');
    long long ans=1;
    for(int i=1;i<=l;i++){
        if(i==l||s[i]!='n'){
            ans=ans*dp[cnt]%mod;
            cnt=0;
        }
        else cnt++;
    }
    cnt=(s[0]=='u');
    for(int i=1;i<=l;i++){
        if(i==l||s[i]!='u'){
            ans=ans*dp[cnt]%mod;
            cnt=0;
        }
        else cnt++;
    }
    cout<<ans<<endl;
    return 0;
}