#include <bits/stdc++.h>
using namespace std;

int n;
int dp[5005];
int a[5005];
int f[5005];
int l[5005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        if (f[a[i]]==0) f[a[i]]=i;
        l[a[i]]=i;
    }
    for (int i=1;i<=n;++i) {
        int ll=i;
        int res=0;
        for (int j=i;j>0;--j) {
            ll=min(ll,f[a[j]]);
            if (j==l[a[j]]) res^=a[j];
            else if (l[a[j]]>i) break;
            if (j==ll) dp[i]=max(dp[i],res+dp[j-1]);
        }
        dp[i]=max(dp[i],dp[i-1]);
    }
    cout<<dp[n];
}