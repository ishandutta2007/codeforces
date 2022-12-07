#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=1e5+10, sz2=210, inf=1e18;
int dp[sz][sz2];
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k;
    cin>>n>>m>>k;
    vector <pair <int, int> > ins[n+1], del[n+1];
    for(int a=0; a<k; a++)
    {
        int s, t, d, w;
        scanf("%lld%lld%lld%lld", &s, &t, &d, &w);
        s--, d--;
        ins[s].push_back({w, d});
        del[t].push_back({w, d});
    }
    for(int a=0; a<=n; a++) for(int b=0; b<=m; b++) dp[a][b]=inf;
    dp[0][0]=0;
    multiset <pair <int, int>, greater <pair <int, int> > > se;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<ins[a].size(); b++) se.insert(ins[a][b]);
        for(int b=0; b<del[a].size(); b++) se.erase(se.find(del[a][b]));
        int w=0, d=a;
        if(se.size())
        {
            w=(*se.begin()).first, d=(*se.begin()).second;
        }
        for(int b=0; b<=m; b++)
        {
            if(dp[a][b]!=inf)
            {
                if(b<m) dp[a+1][b+1]=min(dp[a+1][b+1], dp[a][b]);
                dp[d+1][b]=min(dp[d+1][b], dp[a][b]+w);
            }
        }
    }
    int an=inf;
    for(int a=0; a<=m; a++) an=min(an, dp[n][a]);
    cout<<an;
}