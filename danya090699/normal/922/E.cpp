#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=1e4+10;
int dp[sz], dp2[sz];
main()
{
    //freopen("input.txt", "r", stdin);
    int n, w, bo, x;
    cin>>n>>w>>bo>>x;
    int q[n], pr[n];
    for(int a=0; a<n; a++) cin>>q[a];
    for(int a=0; a<n; a++) cin>>pr[a];
    for(int a=0; a<sz; a++)
    {
        dp[a]=-1, dp2[a]=-1;
    }
    dp[0]=w;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<sz; b++)
        {
            if(dp[b]!=-1)
            {
                for(int c=0; c<=q[a]; c++)
                {
                    if(dp[b]>=c*pr[a])
                    {
                        dp2[b+c]=max(dp2[b+c], dp[b]-c*pr[a]);
                    }
                }
            }
        }
        for(int b=0; b<sz; b++)
        {
            dp[b]=dp2[b], dp2[b]=-1;
            if(dp[b]!=-1) dp[b]=min(w+b*bo, dp[b]+x);
        }
    }
    for(int a=sz-1; a>=0; a--)
    {
        if(dp[a]!=-1)
        {
            cout<<a;
            break;
        }
    }
}