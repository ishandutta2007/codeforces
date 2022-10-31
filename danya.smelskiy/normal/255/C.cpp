#include <bits/stdc++.h>
using namespace std;

int n,ans;
int dp[4001][4001];
int a[4001],b[4001];
int q[1000005];
int last;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    ans=min(2,n);
    for (int i=1;i<=n;++i){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    for (int i=1;i<=n;++i) {
        if (i==1 || b[i]!=b[i-1]) {
            ++last;
            q[b[i]]=last;
        }
    }
    for (int i=1;i<=n;++i){
        a[i]=q[a[i]];
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<i;++j)
            if (dp[a[j]][a[i]] && a[i]!=a[j]) dp[a[i]][a[j]]=max(dp[a[i]][a[j]],dp[a[j]][a[i]]+1);
        for (int j=1;j<i;++j) if (a[i]!=a[j])
            dp[a[i]][a[j]]=max(dp[a[i]][a[j]],2);
        dp[a[i]][a[i]]=dp[a[i]][a[i]]+1;
    }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
        ans=max(ans,dp[a[i]][a[j]]);
    cout<<ans;
}