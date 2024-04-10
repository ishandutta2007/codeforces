#include <bits/stdc++.h>
using namespace std;

int n,m,p;
long long a[2005];
long long b[2005];
long long dp[2005][2005];
bool used[2005][2005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>p;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=m;++i)
        cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    for (int i=0;i<=m;++i)
        used[0][i]=true;
    for (int i=1;i<=n;++i)
    for (int j=1;j<=m;++j) {
        dp[i][j]=1e18;
        if (used[i][j-1]) {
            used[i][j]=true;
            dp[i][j]=dp[i][j-1];
        }
        if (used[i-1][j-1]) {
                used[i][j]=true;
                dp[i][j]=min(dp[i][j],max(dp[i-1][j-1],abs(a[i]-b[j])+abs(b[j]-p)));
        }
    }
    long long ans=1e18;
    for (int i=1;i<=m;++i)
        if (used[n][i]) ans=min(ans,dp[n][i]);
    cout<<ans;
}