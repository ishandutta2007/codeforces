#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, mod=1e9+7;
int dp[sz];
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int n2=max(n, m);
    dp[0]=1;
    for(int a=0; a<n2; a++)
    {
        dp[a+1]=(dp[a+1]+dp[a])%mod;
        if(a+2<=n2) dp[a+2]=(dp[a+2]+dp[a])%mod;
    }
    int an=(dp[m]+dp[n])%mod;
    an--;
    if(an<0) an+=mod;
    cout<<(an*2)%mod;
}