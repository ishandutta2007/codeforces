#include <bits/stdc++.h>
using namespace std;
const int sz=5e5+10;
vector <pair <int, int> > sv[sz];
int pre[sz], prdi[sz], tin[sz], timer=0, pr[sz], si[sz], mi[sz];
long long an=0;
int find_se(int v)
{
    if(pr[v]!=v) pr[v]=find_se(pr[v]);
    return pr[v];
}
void merge(int u, int v)
{
    u=find_se(u), v=find_se(v);
    if(v!=u)
    {
        if(si[u]<si[v]) swap(u, v);
        si[u]+=si[v];
        pr[v]=u;
        if(tin[mi[v]]<tin[mi[u]]) mi[u]=mi[v];
    }
}
void dfs(int v)
{
    tin[v]=timer, timer++;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, d=sv[v][a].second;
        if(ne!=pre[v])
        {
            pre[ne]=v, prdi[ne]=d, dfs(ne);
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, m;
    cin>>n>>k>>m;
    int rq=n-1;
    for(int a=0; a<n; a++)
    {
        pr[a]=a, si[a]=1;
    }
    for(int a=0; a<k; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(make_pair(v, 0));
        sv[v].push_back(make_pair(u, 0));
        merge(u, v);
    }
    int re[m][3];
    for(int a=0; a<m; a++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        u--, v--;
        if(find_se(u)==find_se(v))
        {
            re[a][0]=u, re[a][1]=v, re[a][2]=w;
        }
        else
        {
            re[a][0]=-1;
            sv[u].push_back(make_pair(v, 1));
            sv[v].push_back(make_pair(u, 1));
            rq--, merge(u, v);
        }
    }
    dfs(0);
    for(int a=0; a<n; a++)
    {
        pr[a]=a, si[a]=1, mi[a]=a;
    }
    for(int a=0; a<m; a++)
    {
        int u=re[a][0], v=re[a][1], w=re[a][2];
        if(u!=-1)
        {
            if(tin[u]>tin[v]) swap(u, v);
            u=mi[find_se(u)], v=mi[find_se(v)];
            while(tin[v]>tin[u])
            {
                if(prdi[v]==0)
                {
                    an+=w, rq--;
                }
                merge(v, pre[v]);
                v=mi[find_se(v)];
            }
            while(tin[u]>tin[v])
            {
                if(prdi[u]==0)
                {
                    an+=w, rq--;
                }
                merge(u, pre[u]);
                u=mi[find_se(u)];
            }
        }
    }
    if(rq) cout<<-1;
    else cout<<an;
}