#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
vector <int> sv[sz];
int di, dis, dp[sz], A, B, da, db;
void dfs(int v, int pr)
{
    dp[v]=0;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            dfs(ne, v), di=max(di, dp[v]+dp[ne]+1);
            dp[v]=max(dp[v], dp[ne]+1);
        }
    }
}
void dfs2(int v, int pr, int h)
{
    if(v==B) dis=h;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            dfs2(ne, v, h+1);
        }
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
        scanf("%d%d%d%d%d", &n, &A, &B, &da, &db);
        A--, B--;
        for(int a=0; a<n-1; a++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            u--, v--;
            sv[u].push_back(v);
            sv[v].push_back(u);
        }
        di=0, dfs(0, 0), dfs2(A, A, 0);
        if(dis>da and da*2<db and di>=da*2+1) printf("Bob\n");
        else printf("Alice\n");

        for(int a=0; a<n; a++) sv[a].clear();
    }
}