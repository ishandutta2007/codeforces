#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[1005];
int dp[(int)1e6+5];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=1e6;++i)
        dp[i]=k+1;
    for (int i=2;i<=n;++i) {
        a[i]=a[i]-a[1];
        if (i>2 && a[i]==a[i-1]) continue;
        for (int j=a[i];j<=a[i]*k;++j)
            dp[j]=(min(dp[j],dp[j-a[i]]+1));
    }
    for (int i=0;i<=1e6;++i)
        if (dp[i]<=k)
        cout<<k*a[1]+i<<" ";
}