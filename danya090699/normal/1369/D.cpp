#include <bits/stdc++.h>
using namespace std;
const int sz=2e6+10, mod=1e9+7;
int dp[sz], flag[sz];
main()
{
    dp[3]=4, flag[3]=1;
    for(int a=4; a<sz; a++)
    {
        dp[a]=(0ll+dp[a-1]+dp[a-2]+dp[a-2])%mod;
        if(flag[a-1]==0 and flag[a-2]==0)
        {
            flag[a]=1;
            dp[a]=(dp[a]+4)%mod;
        }
    }
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
}