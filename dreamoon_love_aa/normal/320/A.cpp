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
int dp[12];
int main(){
    int i,j,k,n;
    char s[12];
    gets(s+1);
    dp[0]=1;
    for(i=1;i<=strlen(s+1);i++){
        if(s[i]=='1'&&dp[i-1])dp[i]=1;
        else if(i>=2&&s[i-1]=='1'&&s[i]=='4'&&dp[i-2])dp[i]=1;
        else if(i>=3&&s[i-2]=='1'&&s[i-1]=='4'&&s[i]=='4'&&dp[i-3])dp[i]=1;
    }
    puts(dp[strlen(s+1)]?"YES":"NO");
    return 0;
}