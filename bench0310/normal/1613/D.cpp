#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        const int mod=998244353;
        auto add=[&](int a,int b){return a+b-(a+b>=mod?mod:0);};
        vector<array<int,2>> dp(n+1,{0,0});
        dp[0][0]=1;
        int res=0;
        for(int i=0;i<n;i++)
        {
            int x;
            cin >> x;
            for(int j=max(0,x-1);j<=min(n,x+1);j++)
            {
                res=add(res,dp[j][0]);
                if(j!=x)
                {
                    res=add(res,dp[j][1]);
                    dp[j][1]=add(dp[j][1],dp[j][1]);
                }
            }
            if(x<n) dp[x+1][0]=add(add(dp[x+1][0],dp[x+1][0]),dp[x][0]);
            if(x>0) dp[x-1][1]=add(dp[x-1][1],dp[x-1][0]);
        }
        cout << res << "\n";
    }
    return 0;
}