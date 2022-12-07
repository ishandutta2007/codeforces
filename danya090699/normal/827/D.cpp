#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+5;
struct re{int to, va, nu;};
re nre;
vector <re> sv[sz], in[sz];
int n, m, di[sz], fr[sz], tin[sz], tout[sz], an[sz], inf=1e9+10, timer=0;
int up[18][sz], ma[18][sz], mi[18][sz];
bool us[sz];
void dfs(int v)
{
    tin[v]=timer, timer++;
    for(int a=0; a<in[v].size(); a++) dfs(in[v][a].to);
    tout[v]=timer, timer++;
}
int go(int v, int u, int va)
{
    if(tin[v]<tin[u] and tout[v]>tout[u]) return 0;
    int an=0;
    for(int a=17; a>=0; a--)
    {
        int ne=up[a][v], ok=0;
        if(tin[v]<tin[u])
        {
            if(tout[ne]<tout[u]) ok=1;
        }
        else
        {
            if(tin[ne]>tin[u]) ok=1;
        }
        if(ok)
        {
            an=max(an, ma[a][v]);
            mi[a][v]=min(mi[a][v], va);
            v=ne;
        }
    }
    an=max(an, ma[0][v]);
    mi[0][v]=min(mi[0][v], va);
    return an;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for(int a=0; a<m; a++)
    {
        int u, v, va;
        scanf("%d%d%d", &u, &v, &va);
        u--, v--;
        nre.to=v, nre.va=va, nre.nu=a;
        sv[u].push_back(nre);
        nre.to=u;
        sv[v].push_back(nre);
    }
    for(int a=1; a<n; a++)
    {
        di[a]=inf, us[a]=0;
    }
    di[0]=0, fr[0]=0;
    set <pair <int, int> > se;
    se.insert(make_pair(0, 0));
    for(int a=0; a<n; a++)
    {
        int v=(*se.begin()).second;
        se.erase(se.begin());
        if(v!=0)
        {
            nre.to=v, nre.va=di[v];
            in[fr[v]].push_back(nre);
        }
        us[v]=1;
        for(int a=0; a<sv[v].size(); a++)
        {
            int ne=sv[v][a].to, va=sv[v][a].va;
            if(us[ne]==0 and di[ne]>va)
            {
                se.erase(make_pair(di[ne], ne));
                di[ne]=va, fr[ne]=v;
                se.insert(make_pair(di[ne], ne));
            }
        }
    }
    dfs(0);
    for(int a=0; a<n; a++)
    {
        up[0][a]=fr[a], ma[0][a]=di[a];
    }
    for(int a=1; a<18; a++)
    {
        for(int b=0; b<n; b++)
        {
            up[a][b]=up[a-1][up[a-1][b]];
            ma[a][b]=max(ma[a-1][b], ma[a-1][up[a-1][b]]);
        }
    }
    for(int a=0; a<18; a++) for(int b=0; b<n; b++) mi[a][b]=inf;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<sv[a].size(); b++)
        {
            int ne=sv[a][b].to, va=sv[a][b].va, nu=sv[a][b].nu;
            if(fr[a]!=ne and fr[ne]!=a) an[nu]=max(go(a, ne, va), go(ne, a, va))-1;
        }
    }
    for(int a=17; a>0; a--)
    {
        for(int b=0; b<n; b++)
        {
            mi[a-1][b]=min(mi[a-1][b], mi[a][b]);
            mi[a-1][up[a-1][b]]=min(mi[a-1][up[a-1][b]], mi[a][b]);
        }
    }
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<sv[a].size(); b++)
        {
            int ne=sv[a][b].to, nu=sv[a][b].nu;
            if(fr[a]==ne)
            {
                if(mi[0][a]==inf) an[nu]=-1;
                else an[nu]=mi[0][a]-1;
            }
        }
    }
    for(int a=0; a<m; a++) cout<<an[a]<<" ";
}