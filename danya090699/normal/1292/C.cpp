#include <bits/stdc++.h>
using namespace std;
const int sz=3e3+10;
vector <int> sv[sz];
int n, pr[sz], si[sz];
void dfs(int v)
{
    //cout<<v<<" ";
    si[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr[v]) pr[ne]=v, dfs(ne), si[v]+=si[ne];
    }
}
int f(int v, int v2)
{
    if(pr[v]==v2) return si[v];
    else return n-si[v2];
}
int ne[sz][sz];
long long dp[sz][sz];
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    queue <pair <int, int> > qu;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        cin>>u>>v;
        u--, v--;
        if(u>v) swap(u, v);
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0);
    for(int a=0; a<n; a++) for(int b=0; b<n; b++) ne[a][b]=-1;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<sv[a].size(); b++)
        {
            int u=a, v=sv[a][b];
            if(u<v)
            {
                dp[u][v]=f(u, v)*f(v, u);
                ne[u][v]=v, ne[v][u]=u;
                qu.push({u, v});
            }
        }
    }
    long long an=0;
    while(qu.size())
    {
        int v[2]={qu.front().first, qu.front().second};
        int pr[2]={ne[v[0]][v[1]], ne[v[1]][v[0]]};
        an=max(an, dp[v[0]][v[1]]);

        for(int i=0; i<2; i++)
        {
            for(int a=0; a<sv[v[i]].size(); a++)
            {
                int v2=sv[v[i]][a];
                if(v2!=pr[i])
                {
                    int add=f(v2, v[i])*f(v[i^1], pr[i^1]);
                    int nv1=v2, nv2=v[i^1], npr1=v[i], npr2=pr[i^1];
                    if(nv1>nv2) swap(nv1, nv2), swap(npr1, npr2);

                    dp[nv1][nv2]=max(dp[nv1][nv2], dp[v[0]][v[1]]+add);

                    if(ne[nv1][nv2]==-1)
                    {
                        ne[nv1][nv2]=npr1;
                        ne[nv2][nv1]=npr2;
                        qu.push({nv1, nv2});
                    }
                }
            }
        }
        qu.pop();
    }
    cout<<an;
}