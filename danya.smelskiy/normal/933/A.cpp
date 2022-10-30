#include <bits/stdc++.h>
using namespace std;

int n;
int a[2005];
int dp[2005][2005][2];
int cnt[2005][2];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
    }
    for (int i=1;i<=n;++i) {
        int c1=0,c2=0;
        for (int j=i;j<=n;++j) {
            if (a[j]==1) {
                ++c1;
                c2=max(c2,c1);
            } else ++c2;
            dp[i][j][0]=c1;
            dp[i][j][1]=c2;
        }
    }
    for (int i=n;i>0;--i) {
        int c1=0,c2=0;
        for (int j=i;j>0;--j) {
            if (a[j]==1) {
                ++c1;
                c2=max(c2,c1);
            } else ++c2;
            dp[i][j][0]=c1;
            dp[i][j][1]=c2;
        }
    }
    for (int i=n;i>0;--i) {
        cnt[i][0]=cnt[i+1][0];
        cnt[i][1]=cnt[i+1][1];
        if (a[i]==1) ++cnt[i][0];
        else ++cnt[i][1];
    }
    int ans=max(dp[1][n][0],dp[1][n][1]);
    for (int i=1;i<=n;++i) {
        for (int j=i;j<=n;++j) {
            int res;
            res=dp[1][i-1][0]+dp[j][i][0]+max(dp[j+1][n][0],dp[j+1][n][1]);
            ans=max(ans,res);
            res=dp[1][i-1][0]+dp[j][i][1]+cnt[j+1][1];
            ans=max(ans,res);
        }
    }
    cout<<ans;
}