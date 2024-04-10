#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=2e5+10;
int n, k, dp[sz][5], prq[sz], ans=0;
vector <int> *sv;
void dfs(int v, int pr)
{
    prq[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            dfs(ne, v);
            prq[v]+=prq[ne];
        }
    }
    ans+=prq[v]*(n-prq[v]);
}
void dfs2(int v, int pr)
{
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            dfs2(ne, v);
            int dp2[k];
            for(int b=0; b<k; b++) dp2[b]=0;
            for(int b=0; b<k; b++) dp2[(b+1)%k]+=dp[ne][b];
            dp2[1%k]++;
            for(int b=0; b<k; b++)
            {
                for(int c=0; c<k; c++)
                {
                    int ost=(b+c)%k;
                    if(ost!=0) ans+=(k-ost)*dp2[b]*dp[v][c];
                }
            }
            for(int b=0; b<k; b++) dp[v][(b+1)%k]+=dp[ne][b];
            dp[v][1%k]++;
        }
    }
    for(int a=1; a<k; a++) ans+=(k-a)*dp[v][a];
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>k;
    sv=new vector <int> [n];
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<k; b++) dp[a][b]=0;
    }
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        cin>>u>>v;
        u--, v--;
        sv[u].push_back(v), sv[v].push_back(u);
    }
    dfs(0, -1);
    dfs2(0, -1);
    cout<<ans/k;
}