#include <bits/stdc++.h>
using namespace std;

int n;
long long a[5005],b[5005],dp[5005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    dp[0]=1e18;
    for (int i=1;i<=n;++i){
        if (b[i]<=a[1]) dp[i]=a[1]-b[i];
    }
    for (int i=2;i<=n;++i) {
        long long mn=1e18;
        for (int j=1;j<=n;++j){
            mn=min(mn,dp[j]);
            if (b[j]<=a[i]) dp[j]+=a[i]-b[j];
            else {
                dp[j]+=b[j]-a[i];
                if (b[j]>=a[i] && b[j-1]<=a[i]) dp[j]=min(dp[j],dp[j-1]);
            }
            dp[j]=min(dp[j],dp[j-1]);
        }
    }
    long long ans=1e18;
    for (int i=1;i<=n;++i)
        ans=min(ans,dp[i]);
    cout<<ans;
}