#include <bits/stdc++.h>
using namespace std;
long long n,p,q,r;
long long a[100005];
long long dp[100005][3];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>p>>q>>r;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
    }
    dp[n][0]=a[n]*r;
    dp[n][1]=a[n]*r+a[n]*q;
    dp[n][2]=a[n]*r+a[n]*q+a[n]*p;
    long long ans=dp[n][2];
    for (int i=n-1;i>0;--i) {
        dp[i][0]=max(a[i]*r,dp[i+1][0]);
        dp[i][1]=max(a[i]*r+a[i]*q,max(dp[i+1][0]+a[i]*q,dp[i+1][1]));
        dp[i][2]=max(a[i]*r+a[i]*q+a[i]*p,dp[i+1][2]);
        dp[i][2]=max(dp[i][2],dp[i+1][0]+a[i]*q+a[i]*p);
        dp[i][2]=max(dp[i][2],dp[i+1][1]+a[i]*p);
        ans=max(ans,dp[i][2]);
    }
    cout<<ans;

}