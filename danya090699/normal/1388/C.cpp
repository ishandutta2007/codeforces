#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
vector <int> sv[sz];
int su[sz], h[sz], g[sz], ok;
void dfs(int v, int pr)
{
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            dfs(ne, v), su[v]+=su[ne];
        }
    }
    if(h[v]+su[v]<0) ok=0;
    else if((h[v]+su[v])&1) ok=0;
    else
    {
        g[v]=(h[v]+su[v])/2;
        if(g[v]>su[v]) ok=0;
    }
}
void dfs2(int v, int pr)
{
    int q=0;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            dfs2(ne, v), q+=g[ne];
        }
    }
    if(q>g[v]) ok=0;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        ok=1;
        int n, m;
        cin>>n>>m;
        for(int a=0; a<n; a++) scanf("%d", &su[a]);
        for(int a=0; a<n; a++) scanf("%d", &h[a]);
        for(int a=0; a<n-1; a++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            u--, v--;
            sv[u].push_back(v);
            sv[v].push_back(u);
        }
        dfs(0, 0);
        if(ok) dfs2(0, 0);
        printf(ok ? "YES\n" : "NO\n");

        for(int a=0; a<n; a++) sv[a].clear();
    }
}