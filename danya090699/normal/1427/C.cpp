#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int r, n;
    cin>>r>>n;
    int x[n+1], y[n+1], t[n+1], dp[n+1], pref[n+1];
    x[0]=1, y[0]=1, t[0]=0, dp[0]=0, pref[0]=0;
    for(int a=1; a<=n; a++)
    {
        scanf("%d%d%d", &t[a], &x[a], &y[a]);
        dp[a]=-1;
        if(a-r*2>=0)
        {
            dp[a]=pref[a-r*2]+1;
        }
        for(int b=max(0, a-r*2); b<a; b++)
        {
            if(t[b]+abs(x[a]-x[b])+abs(y[a]-y[b])<=t[a])
            {
                if(dp[b]!=-1) dp[a]=max(dp[a], dp[b]+1);
            }
        }
        pref[a]=max(dp[a], pref[a-1]);
    }
    cout<<pref[n];
}