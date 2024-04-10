#include <bits/stdc++.h>
using namespace std;

long long n,x,y,dp[10000005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>x>>y;
    dp[1]=x;
    for (int i=2;i<=n;++i) {
        if (i&1) dp[i]=min(dp[i-1]+x,min(dp[i/2]+x+y,dp[i/2+1]+x+y));
        else dp[i]=min(dp[i-1]+x,dp[i/2]+y);
    }
    cout<<dp[n];
}