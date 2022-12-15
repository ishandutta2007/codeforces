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
long long mod=1000000007,dp[1005][1005];
int n,k;
long long dfs(int rest,int age){
    if(dp[rest][age]!=-1) return dp[rest][age];
    if(rest==0||age==1) return dp[rest][age]=1;
    return dp[rest][age]=(dfs(rest-1,age)+dfs(n-rest,age-1))%mod;
}
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        scanf("%d%d",&n,&k);
        for(int i=0;i<=n;i++)
            for(int j=0;j<=k;j++)
                dp[i][j]=-1;
        printf("%lld\n",dfs(n,k));
    }
    return 0;
}
//
/// 
//01
// 
//
//dp