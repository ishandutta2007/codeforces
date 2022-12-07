#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int ar[m];
    for(int a=0; a<m; a++) cin>>ar[a];
    sort(ar, ar+m);
    int g, r;
    cin>>g>>r;
    int dp[m][g+1];
    for(int a=0; a<m; a++) for(int b=0; b<=g; b++) dp[a][b]=inf;
    dp[0][g]=-1;
    for(int a=0; a<m; a++)
    {
        queue <pair <int, int> > qu;
        for(int b=0; b<m; b++)
        {
            if(dp[b][g]!=inf and dp[b][0]==inf)
            {
                dp[b][0]=a, qu.push({b, 0});
            }
        }
        while(qu.size())
        {
            int p=qu.front().first, s=qu.front().second;
            if(p and s+ar[p]-ar[p-1]<=g and dp[p-1][s+ar[p]-ar[p-1]]==inf)
            {
                dp[p-1][s+ar[p]-ar[p-1]]=a;
                qu.push({p-1, s+ar[p]-ar[p-1]});
            }
            if(p+1<m and s+ar[p+1]-ar[p]<=g and dp[p+1][s+ar[p+1]-ar[p]]==inf)
            {
                dp[p+1][s+ar[p+1]-ar[p]]=a;
                qu.push({p+1, s+ar[p+1]-ar[p]});
            }
            qu.pop();
        }
    }
    int an=inf;
    for(int a=0; a<=g; a++)
    {
        if(dp[m-1][a]!=inf) an=min(an, dp[m-1][a]*(g+r)+a);
    }
    if(an==inf) cout<<-1;
    else cout<<an;
}