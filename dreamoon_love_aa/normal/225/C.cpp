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
char s[1001][1002];
int a[1001][2],dp[1001][2];
int main(){
    int i,j,k,n,m,x,y;
    scanf("%d%d%d%d",&n,&m,&x,&y);
    for(i=0;i<n;i++)scanf("%s",s[i]);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            if(s[i][j]=='#')a[j][0]++;
            else a[j][1]++;
        }
    dp[m][0]=dp[m][1]=0;
    for(i=m-1;i>=0;i--){
        dp[i][0]=dp[i][1]=100000000;
        int cnt=0;
        for(j=0;i+j<m&&j<y;j++){
            cnt+=a[i+j][0];
            if(j+1>=x)dp[i][0]=min(dp[i][0],cnt+dp[i+j+1][1]);
        }
        cnt=0;
        for(j=0;i+j<m&&j<y;j++){
            cnt+=a[i+j][1];
            if(j+1>=x)dp[i][1]=min(dp[i][1],cnt+dp[i+j+1][0]);
        }
    }
    printf("%d\n",min(dp[0][0],dp[0][1]));
    return 0;
}