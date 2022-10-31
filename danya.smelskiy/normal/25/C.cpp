#include <bits/stdc++.h>
using namespace std;


int n;
long long dp[305][305];
int m;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j)
            cin>>dp[i][j];
    }
    cin>>m;
    while (m--) {
        int x,y;
        long long z;
        cin>>x>>y>>z;
        dp[x][y]=dp[y][x]=min(dp[x][y],z);
        for (int i=1;i<=n;++i) {
            for (int j=1;j<=n;++j){
                dp[i][j]=min(dp[i][j],dp[i][x]+dp[x][y]+dp[y][j]);
                dp[i][j]=min(dp[i][j],dp[i][y]+dp[y][x]+dp[x][j]);
            }
        }
        long long ans=0;
        for (int i=1;i<=n;++i) {
            for (int j=1;j<=n;++j) {
                ans+=dp[i][j];
            }
        }
        cout<<ans/2ll<<" ";
    }
}