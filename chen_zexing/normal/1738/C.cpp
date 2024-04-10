#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int dp[105][105][2][2];
int dfs(int odd,int even,int p,int now){
    if(dp[odd][even][p][now]!=-1) return dp[odd][even][p][now];
    if(odd==0&&even==0) return dp[odd][even][p][now]=now;
    if(p==0){
        dp[odd][even][p][now]=1;
        if(odd) dp[odd][even][p][now]&=dfs(odd-1,even,p^1,now^1);
        if(even) dp[odd][even][p][now]&=dfs(odd,even-1,p^1,now);
    }
    else{
        dp[odd][even][p][now]=0;
        if(odd) dp[odd][even][p][now]|=dfs(odd-1,even,p^1,now);
        if(even) dp[odd][even][p][now]|=dfs(odd,even-1,p^1,now);
    }
    return dp[odd][even][p][now];
}
int main() {
    memset(dp,-1,sizeof(dp));
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,cnt[2]={};
        scanf("%d",&n);
        for(int i=1,x;i<=n;i++) scanf("%d",&x),cnt[((x%2)+2)%2]++;
        puts(dfs(cnt[1],cnt[0],0,0)?"Bob":"Alice");
    }
    return 0;
}