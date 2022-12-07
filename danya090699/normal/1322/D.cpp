#include <bits/stdc++.h>
using namespace std;
const int sz=2e3+10, inf=2e9;
int dp[sz][sz], ma[sz];
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int ag[n], pr[n];
    for(int a=n-1; a>=0; a--) scanf("%d", &ag[a]);
    for(int a=n-1; a>=0; a--) scanf("%d", &pr[a]);

    int c[n+m+1], pref[n+m+1];
    pref[0]=0;
    for(int a=1; a<=n+m; a++)
    {
        scanf("%d", &c[a]);
        pref[a]=c[a]+pref[a-1];
    }
    for(int a=0; a<=m; a++)
    {
        ma[a]=-inf;
        for(int b=0; b<=n; b++) dp[a][b]=-inf;
    }
    dp[0][0]=0, ma[0]=0;
    for(int a=0; a<n; a++)
    {
        for(int b=ag[a]; b>=0; b--)
        {
            if(b+13<ag[a]) dp[ag[a]][1]=max(dp[ag[a]][1], ma[b]+c[ag[a]]-pr[a]);
            else
            {
                for(int mask=n; mask>=0; mask--)
                {
                    if(dp[b][mask]!=-inf)
                    {
                        int mask2=(mask>>(ag[a]-b))+1;
                        int add=pref[ag[a]+__builtin_ctz(mask2)]-pref[ag[a]-1]-pr[a];
                        dp[ag[a]][mask2]=max(dp[ag[a]][mask2], dp[b][mask]+add);
                    }
                }
            }
        }
        for(int mask=0; mask<=n; mask++) ma[ag[a]]=max(ma[ag[a]], dp[ag[a]][mask]);
    }
    int an=0;
    for(int a=0; a<=m; a++) an=max(an, ma[a]);
    cout<<an;
}