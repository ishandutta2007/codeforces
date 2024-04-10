#include <bits/stdc++.h>
using namespace std;

int n,x,ans;
int dp[100005];
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x;
        int now=1;
        for (int j=1;j<=sqrt(x);++j) if (x%j==0) {
            if (j-1) now=max(now,dp[j]+1);
            if (x/j-1) now=max(now,dp[x/j]+1);
        }
        for (int j=1;j<=sqrt(x);++j) if (x%j==0) {
            dp[j]=max(dp[j],now);
            dp[x/j]=max(dp[x/j],now);
        }
        ans=max(ans,now);
    }
    cout<<ans;
}