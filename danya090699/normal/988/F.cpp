#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int main()
{
    //freopen("input.txt", "r", stdin);
    int x, n, m;
    cin>>x>>n>>m;
    int ra[x], zo[x], dp[x+1], dp2[x+1];
    for(int a=0; a<x; a++)
    {
        ra[a]=0, zo[a]=inf;
    }
    for(int a=0; a<n; a++)
    {
        int l, r;
        cin>>l>>r;
        for(l; l<r; l++) ra[l]=1;
    }
    for(int a=0; a<m; a++)
    {
        int p, va;
        cin>>p>>va;
        if(p<x) zo[p]=min(zo[p], va);
    }
    for(int a=0; a<=x; a++)
    {
        dp[a]=inf, dp2[a]=inf;
    }
    dp[x]=0;
    for(int a=0; a<x; a++)
    {
        for(int b=0; b<x; b++)
        {
            if(dp[b]!=inf)
            {
                dp2[b]=min(dp2[b], dp[b]+zo[b]);
                if(zo[a]!=inf) dp2[a]=min(dp2[a], dp[b]+zo[a]);
                if(ra[a]==0) dp2[x]=min(dp2[x], dp[b]);
            }
        }
        if(dp[x]!=inf)
        {
            if(zo[a]!=inf) dp2[a]=min(dp2[a], dp[x]+zo[a]);
            if(ra[a]==0) dp2[x]=min(dp2[x], dp[x]);
        }
        for(int b=0; b<=x; b++)
        {
            dp[b]=dp2[b], dp2[b]=inf;
        }
    }
    int an=inf;
    for(int a=0; a<=x; a++) an=min(an, dp[a]);
    if(an!=inf) cout<<an;
    else cout<<-1;
}