#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    string s;
    cin>>n>>m>>s;
    int sm[m][m];
    for(int a=0; a<m; a++) for(int b=0; b<m; b++) sm[a][b]=0;
    for(int a=0; a+1<n; a++)
    {
        int u=s[a]-'a', v=s[a+1]-'a';
        sm[u][v]++, sm[v][u]++;
    }
    int to[m][1<<m], dp[1<<m];
    for(int a=0; a<m; a++)
    {
        to[a][0]=0;
        for(int mask=1; mask<(1<<m); mask++)
        {
            int i=__builtin_ctz(mask);
            to[a][mask]=to[a][mask-(1<<i)]+sm[a][i];
        }
    }
    for(int a=0; a<(1<<m); a++) dp[a]=inf;
    dp[0]=0;
    for(int mask=0; mask<(1<<m); mask++)
    {
        int add=0;
        for(int i=0; i<m; i++)
        {
            if((mask&(1<<i))==0) add+=to[i][mask];
        }
        for(int i=0; i<m; i++)
        {
            if((mask&(1<<i))==0)
            {
                dp[mask+(1<<i)]=min(dp[mask+(1<<i)], dp[mask]+add);
            }
        }
    }
    cout<<dp[(1<<m)-1];
}