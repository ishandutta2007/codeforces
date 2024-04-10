#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
vector <int> sv[sz];
int c[sz], dp[sz][2], di;
void dfs(int v, int pr)
{
    int be[2]={0, 0};
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            dfs(ne, v);
            for(int i=0; i<2; i++)
            {
                for(int j=0; j<2; j++)
                {
                    int su=dp[ne][j]+be[i];
                    if(c[v]==-1)
                    {
                        if(i==j) su--;
                    }
                    else
                    {
                        su++;
                        if(i==c[v]) su--;
                        if(j==c[v]) su--;
                    }
                    di=max(di, su);
                }
                be[i]=max(be[i], dp[ne][i]);
            }
        }
    }
    for(int i=0; i<2; i++)
    {
        if(c[v]==-1) dp[v][i]=be[i];
        else if(c[v]==i) dp[v][i]=max(be[i], be[i^1]+1);
        else dp[v][i]=0;
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int a=0; a<n; a++)
        {
            scanf("%d", &c[a]);
            c[a]--;
        }
        for(int a=0; a<n-1; a++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            u--, v--;
            sv[u].push_back(v);
            sv[v].push_back(u);
        }
        di=0;
        dfs(0, 0);
        printf("%d\n", di/2+1);

        for(int a=0; a<n; a++) sv[a].clear();
    }
}