#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
int pr[sz], h[sz];
vector <pair <int, int> > sv[sz];
int p[sz], si[sz], be[sz], ty[sz];
int find_se(int v)
{
    if(p[v]!=v) p[v]=find_se(p[v]);
    return p[v];
}
void merge(int u, int v)
{
    u=find_se(u), v=find_se(v);
    if(u!=v)
    {
        if(si[u]<si[v]) swap(u, v);
        si[u]+=si[v], p[v]=u;
        if(h[be[v]]<h[be[u]]) be[u]=be[v];
    }
}
void dfs(int v, int pre)
{
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, nu=sv[v][a].second;
        if(ne!=pre)
        {
            if(pr[ne]==-1)
            {
                h[ne]=h[v]+1, pr[ne]=nu, be[nu]=v, dfs(ne, v);
            }
            else
            {
                if(h[ne]<h[v])
                {
                    int u=v;
                    vector <int> re;
                    re.push_back(nu);
                    be[nu]=ne;
                    while(h[u]>h[ne])
                    {
                        int i=find_se(pr[u]);
                        re.push_back(i), u=be[i];
                    }
                    int cty=0;
                    for(int b=0; b<re.size(); b++)
                    {
                        if(si[re[b]]>1) cty=1;
                        merge(re[0], re[b]);
                    }
                    ty[find_se(re[0])]=cty;
                }
            }
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(make_pair(v, a));
        sv[v].push_back(make_pair(u, a));
        p[a]=a, si[a]=1, ty[a]=0;
    }
    for(int a=0; a<n; a++) pr[a]=-1;
    for(int a=0; a<n; a++)
    {
        if(pr[a]==-1)
        {
            pr[a]=-2, h[a]=0, dfs(a, -1);
        }
    }
    vector <int> an;
    for(int a=0; a<m; a++)
    {
        int v=find_se(a);
        if(si[v]>1 and ty[v]==0) an.push_back(a+1);
    }
    cout<<an.size()<<"\n";
    for(int a=0; a<an.size(); a++) printf("%d ", an[a]);
}