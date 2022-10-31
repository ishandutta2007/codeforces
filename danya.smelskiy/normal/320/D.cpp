#include <bits/stdc++.h>
using namespace std;
int n,sz,q[100005],dp[100005],a[100005];
int ans;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    int sz=0;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        dp[i]=1;
        while (sz && q[sz]<a[i]) {
            dp[i]=max(dp[i],dp[sz]+1);
            --sz;
        }
        ++sz;
        q[sz]=a[i];
        dp[sz]=dp[i];
        if (sz==1) dp[sz]=0;
        ans=max(ans,dp[sz]);
    }
    cout<<ans;
}