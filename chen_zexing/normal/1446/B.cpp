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
#include <unordered_set>
#define hash hassh
using namespace std;
char a[5005],b[5005];
long long dp[5005][5005],ans;
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",a+1);
    scanf("%s",b+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            dp[i][j]=max(dp[i][j],dp[i-1][j]-1);
            dp[i][j]=max(dp[i][j],dp[i][j-1]-1);
            if(a[i]==b[j]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+2);
            ans=max(ans,dp[i][j]);
        }
    printf("%lld\n",ans);
    return 0;
}