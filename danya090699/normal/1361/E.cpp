#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
vector <int> sv[sz];
int us[sz], h[sz], mi[sz][2];
bool dfs(int v)
{
    us[v]=1;
    mi[v][0]=v, mi[v][1]=v;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(us[ne]==2) return false;
        if(us[ne]==1)
        {
            if(h[ne]<h[mi[v][0]]) mi[v][1]=mi[v][0], mi[v][0]=ne;
            else if(h[ne]<h[mi[v][1]]) mi[v][1]=ne;
        }
        if(us[ne]==0)
        {
            h[ne]=h[v]+1;
            if(!dfs(ne)) return false;
            for(int i=0; i<2; i++)
            {
                int u=mi[ne][i];
                if(h[u]<h[mi[v][0]]) mi[v][1]=mi[v][0], mi[v][0]=u;
                else if(h[u]<h[mi[v][1]]) mi[v][1]=u;
            }
        }
    }
    us[v]=2;
    return true;
}
bool ok[sz];
vector <int> an;
void dfs2(int v)
{
    us[v]=1;
    if(mi[v][0]!=v and mi[v][1]==v and ok[mi[v][0]])
    {
        ok[v]=1;
        an.push_back(v+1);
    }
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(!us[ne]) dfs2(ne);
    }
}
mt19937 rnd(time(0));
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int n, m;
        cin>>n>>m;
        for(int a=0; a<m; a++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            u--, v--;
            sv[u].push_back(v);
        }
        for(int i=0; i<40; i++)
        {
            int rt=rnd()%n;
            for(int a=0; a<n; a++) us[a]=0;
            h[rt]=0;
            if(dfs(rt))
            {
                for(int a=0; a<n; a++) ok[a]=0, us[a]=0;
                ok[rt]=1, an.push_back(rt+1);
                dfs2(rt);
                break;
            }
        }
        if(an.size()==0 or an.size()*5<n) printf("-1\n");
        else
        {
            sort(an.begin(), an.end());
            for(int a=0; a<an.size(); a++) printf("%d ", an[a]);
            printf("\n");
        }

        an.clear();
        for(int a=0; a<n; a++) sv[a].clear();
    }
}