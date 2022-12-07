#include <bits/stdc++.h>
#define int long long
using namespace std;
struct el
{
    int s, f, c;
};
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, an=0;
    cin>>n>>m;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    vector <el> sp[n+1];
    for(int a=0; a<m; a++)
    {
        int s, f, c, r;
        scanf("%lld%lld%lld%lld", &s, &f, &c, &r);
        s--, f--;
        sp[r].push_back({s, f, c});
    }
    int dp[n][n], dp2[n][n];

    for(int a=0; a<n; a++) for(int b=a; b<n; b++) dp[a][b]=ar[b]-ar[a];

    for(int q=1; q<=n+1; q++)
    {
        for(int a=0; a<sp[q-1].size(); a++)
        {
            int s=sp[q-1][a].s, f=sp[q-1][a].f, c=sp[q-1][a].c;
            an=max(an, dp[s][f]*c);
        }
        for(int a=0; a<n; a++)
        {
            int yk=a;
            for(int b=a; b<n; b++)
            {
                while(yk<b)
                {
                    if(dp[a][yk+1]<=ar[b]-ar[yk+1]) yk++;
                    else break;
                }
                dp2[a][b]=max(dp[a][yk], ar[b]-ar[yk]);
                if(yk+1<=b) dp2[a][b]=min(dp2[a][b], max(dp[a][yk+1], ar[b]-ar[yk+1]));
            }
        }
        for(int a=0; a<n; a++) for(int b=0; b<n; b++) dp[a][b]=dp2[a][b];
    }
    cout<<an;
}