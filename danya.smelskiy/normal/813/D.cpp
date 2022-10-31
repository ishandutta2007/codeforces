#include <bits/stdc++.h>
using namespace std;


int n;
int a[5005];
int f1[8];
int f2[100005];
int dp[5005][5005];
int ans;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=0;i<=n;++i) {
        for (int j=0;j<7;++j)
            f1[j]=0;
        for (int j=0;j<=n;++j)
            f2[a[j]]=0;
        for (int j=1;j<=n;++j) {
            if (j==i) continue;
            if (j<i) {
                f1[a[j]%7]=max(f1[a[j]%7],dp[i][j]);
                f2[a[j]]=max(f2[a[j]],dp[i][j]);
                continue;
            }
            dp[j][i]=max(dp[j][i],f1[a[j]%7]+1);
            dp[j][i]=max(dp[j][i],f2[a[j]-1]+1);
            dp[j][i]=max(dp[j][i],f2[a[j]+1]+1);
            dp[j][i]=max(dp[j][i],dp[i][0]+1);
            ans=max(ans,dp[j][i]);
            f1[a[j]%7]=max(f1[a[j]%7],dp[j][i]);
            f2[a[j]]=max(f2[a[j]],dp[j][i]);
        }
    }
    cout<<ans;
}