#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    pair <int, int> ar[n];
    for(int a=0; a<n; a++) cin>>ar[a].first>>ar[a].second;
    sort(ar, ar+n);
    int dp[m+1], dp2[m+1];
    for(int a=0; a<=m; a++) dp[a]=inf, dp2[a]=inf;
    dp[0]=0;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<=m; b++)
        {
            if(b+1<ar[a].first-ar[a].second)
            {
                dp2[b]=min(dp2[b], dp[b]);
                int add=ar[a].first-ar[a].second-(b+1), p=min(m, ar[a].first+ar[a].second+add);
                dp2[p]=min(dp2[p], dp[b]+add);
            }
            else
            {
                int p=max(b, ar[a].first+ar[a].second);
                p=min(p, m);
                dp2[p]=min(dp2[p], dp[b]);
            }
        }
        for(int b=0; b<=m; b++) dp[b]=dp2[b], dp2[b]=inf;
    }
    int an=inf;
    for(int a=0; a<=m; a++) an=min(an, dp[a]+m-a);
    cout<<an;
}