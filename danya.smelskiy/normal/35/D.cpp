#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[305];
int dp[100005];
int ans;


int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        a[i]*=(n-i+1);
    }
    for (int i=1;i<=n;++i) {
        for (int j=m;j>=a[i];--j)
            dp[j]=max(dp[j],dp[j-a[i]]+1);
    }
    for (int i=1;i<=m;++i)
        ans=max(ans,dp[i]);
    cout<<ans;
}