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
char s[100010];
bool ban[26][26];
int dp[26];
int main(){
    int i,j,k,n,len,an=0;
    scanf("%s%d",s+1,&n);
    len=strlen(s+1);
    for(i=0;i<n;i++){
        char tmp[8];
        scanf("%s",tmp);
        ban[tmp[0]-'a'][tmp[1]-'a']=1;
        ban[tmp[1]-'a'][tmp[0]-'a']=1;
    }
    for(i=1;i<=len;i++){
        int now=0;
        for(j=0;j<26;j++){
            if(!ban[s[i]-'a'][j]){
                now=max(now,dp[j]+1);
            }
        }
        dp[s[i]-'a']=max(dp[s[i]-'a'],now);
        an=max(dp[s[i]-'a'],an);
    }
    cout<<len-an<<endl;
    return 0;
}