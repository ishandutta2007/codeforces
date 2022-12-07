#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10;
vector <int> sv[sz], rsv[sz];
int us[sz], tout;
void dfs(int v)
{
    us[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(us[ne]==0) dfs(ne);
    }
    tout=v;
}
void dfs2(int v)
{
    us[v]=0;
    for(int a=0; a<rsv[v].size(); a++)
    {
        int ne=rsv[v][a];
        if(us[ne]) dfs2(ne);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n, m;
        scanf("%d%d", &n, &m);
        for(int a=0; a<m; a++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            u--, v--;
            sv[u].push_back(v);
            rsv[v].push_back(u);
        }
        for(int a=0; a<n; a++) if(us[a]==0) dfs(a);
        dfs2(tout);
        vector <int> an[2];
        for(int a=0; a<n; a++) an[us[a]^1].push_back(a+1);
        if(an[0].size())
        {
            printf("Yes\n%d %d\n", an[0].size(), an[1].size());
            for(int i=0; i<2; i++)
            {
                for(int a=0; a<an[i].size(); a++) printf("%d ", an[i][a]);
                printf("\n");
            }
        }
        else printf("No\n");

        for(int a=0; a<n; a++)
        {
            us[a]=0, sv[a].clear(), rsv[a].clear();
        }
    }
}