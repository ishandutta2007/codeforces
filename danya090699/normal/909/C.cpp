#include <bits/stdc++.h>
using namespace std;
const int sz=5e3+10, mod=1e9+7;
int dp[sz][sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    dp[0][0]=1;
    for(int a=0; a<n; a++)
    {
        char sy;
        cin>>sy;
        if(sy=='f')
        {
            for(int b=0; b<sz; b++)
            {
                if(dp[a][b])
                {
                    dp[a+1][b+1]+=dp[a][b];
                    if(dp[a+1][b+1]>=mod) dp[a+1][b+1]-=mod;
                }
            }
        }
        else
        {
            int su=0;
            for(int b=sz-1; b>=0; b--)
            {
                su+=dp[a][b];
                if(su>=mod) su-=mod;
                dp[a+1][b]+=su;
                if(dp[a+1][b]>=mod) dp[a+1][b]-=mod;
            }
        }
    }
    cout<<dp[n][0];
}