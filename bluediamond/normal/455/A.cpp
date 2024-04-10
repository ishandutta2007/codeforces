#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e5;
int n , ap[nmax+5];
long long dp[nmax+5] , ans;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        ap[a]++;
    }
    for(int i=1;i<=nmax;i++)
    {
        if(ap[i])
            dp[i]=dp[i-2]+1ll*ap[i]*i;
        dp[i]=max(dp[i],dp[i-1]);
        ans=max(ans,dp[i]);
    }
    cout<<ans;
    return 0;
}
/**
**/