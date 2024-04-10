#include <bits/stdc++.h>
using namespace std;
const int sz=70, inf=1e9;
int n, m, x, y, di[sz][1<<17], an[sz], sm[sz][sz], us[sz], cnu[sz], cq=0;
vector <int> qu[sz][sz], sp;
void dfs(int v)
{
    sp.push_back(v);
    us[v]=1;
    for(int a=0; a<n; a++)
    {
        if(sm[v][a]==x and us[a]==0) dfs(a);
    }
}
bool comp(pair <int, int> a, pair <int, int> b){return (a.first*x+a.second*y)<(b.first*x+b.second*y);}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m>>x>>y;
    for(int a=0; a<m; a++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        u--, v--;
        sm[u][v]=w, sm[v][u]=w;
    }
    for(int a=0; a<n; a++) cnu[a]=-1, an[a]=inf;
    for(int a=0; a<n; a++)
    {
        if(us[a]==0)
        {
            dfs(a);
            if(sp.size()>3)
            {
                for(int b=0; b<sp.size(); b++) cnu[sp[b]]=cq;
                cq++;
            }
            for(int b=0; b<sp.size(); b++)
            {
                for(int c=0; c<sp.size(); c++)
                {
                    if(sm[sp[b]][sp[c]]==y) sm[sp[b]][sp[c]]=0;
                }
            }
            sp.clear();
        }
    }
    vector <pair <int, int> > sv[n], p;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n; b++)
        {
            if(sm[a][b])
            {
                sv[a].push_back({b, sm[a][b]});
            }
            p.push_back({a, b});
        }
    }
    sort(p.begin(), p.end(), comp);

    for(int a=0; a<n; a++) for(int b=0; b<(1<<cq); b++) di[a][b]=inf;

    qu[0][0].push_back(0);

    for(int a=0; a<p.size(); a++)
    {
        int xq=p[a].first, yq=p[a].second, l=xq*x+yq*y;
        while(qu[xq][yq].size())
        {
            int s=qu[xq][yq].back(), v=s>>cq, mask=s&((1<<cq)-1);
            if(di[v][mask]==inf)
            {
                di[v][mask]=l;
                an[v]=min(an[v], l);
                for(int b=0; b<sv[v].size(); b++)
                {
                    int ne=sv[v][b].first, add=sv[v][b].second;
                    if(cnu[ne]==-1 or (mask&(1<<cnu[ne]))==0)
                    {
                        int nmask=mask, nxq=xq, nyq=yq;
                        if(cnu[v]!=-1 and cnu[v]!=cnu[ne]) nmask+=(1<<cnu[v]);
                        if(add==x) nxq++;
                        else nyq++;
                        qu[nxq][nyq].push_back(nmask+(ne<<cq));
                    }
                }
            }
            qu[xq][yq].pop_back();
        }
    }
    for(int a=0; a<n; a++) cout<<an[a]<<" ";
}