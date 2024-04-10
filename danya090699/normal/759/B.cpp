//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, inf=2e9;
    cin>>n;
    int ti[n], dp[n+1];
    dp[0]=0;
    for(int a=0; a<n; a++) ti[a]=inf;
    for(int a=1; a<=n; a++)
    {
        cin>>ti[a-1];
        dp[a]=dp[a-1]+20;
        int p=upper_bound(ti, ti+n, ti[a-1]-90)-ti;
        dp[a]=min(dp[a], dp[p]+50);
        p=upper_bound(ti, ti+n, ti[a-1]-1440)-ti;
        dp[a]=min(dp[a], dp[p]+120);
        cout<<dp[a]-dp[a-1]<<"\n";
    }
}