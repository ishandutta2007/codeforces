#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[4005],b[4005];
int dp[4005][4005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>a[i]>>b[i];
    ++n;
    a[n]=86401; b[n]=1;
    for (int i=0;i<=n;++i)
    for (int j=0;j<=m;++j)
        dp[i][j]=1e9;
    dp[0][0]=1;
    int ans=0;
    for (int i=0;i<n;++i)
        for (int j=0;j<=m;++j) if (dp[i][j]<=86400) {
            if (a[i+1]>=dp[i][j]) ans=max(ans,a[i+1]-dp[i][j]);
            dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
            int nxt;
            if (dp[i][j]<=a[i+1]) nxt=a[i+1]+b[i+1];
            else nxt=dp[i][j]+b[i+1];
            dp[i+1][j]=min(dp[i+1][j],nxt);
        }
    cout<<ans;
}