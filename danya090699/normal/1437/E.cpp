#include <bits/stdc++.h>
using namespace std;
const int inf=1e9+1e6;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    vector <pair <int, int> > sp;
    sp.push_back({-1, -inf});
    int ar[n];
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    for(int a=0; a<k; a++)
    {
        int p;
        scanf("%d", &p);
        p--;
        sp.push_back({p, ar[p]});
    }
    sp.push_back({n, inf});

    int dp[n+1], ma=0;
    dp[0]=-inf;
    for(int a=1; a<=n; a++) dp[a]=inf;
    for(int a=0; a+1<sp.size(); a++)
    {
        if(sp[a+1].second-sp[a].second<sp[a+1].first-sp[a].first)
        {
            cout<<-1;
            return 0;
        }
        for(int b=sp[a].first+1; b<sp[a+1].first; b++)
        {
            if(ar[b]>=sp[a].second+(b-sp[a].first) and ar[b]<=sp[a+1].second-(sp[a+1].first-b))
            {
                int p=upper_bound(dp, dp+n+1, ar[b]-b)-dp;
                dp[p]=ar[b]-b;
                ma=max(ma, p);
            }
        }
    }
    cout<<n-k-ma;
}