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
char s[1000000];
int dp[1000000];
int get(int id){
    if(id<0)return 0;
    return dp[id];
}
int main(){
    int i,j,k,n;
    scanf("%s",s);
    n=strlen(s);
    for(i=0;s[i];i++){
        if(s[i]==s[i+1])dp[i]=1;
        else dp[i]=0;
    }
    for(i=1;i<n;i++)dp[i]+=dp[i-1];
    scanf("%d",&n);
    while(n--){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",get(y-2)-get(x-2));
    }
    return 0;
}