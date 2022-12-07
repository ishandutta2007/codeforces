#include <bits/stdc++.h>
using namespace std;
const int sz=4e3+10, inf=1e9;
int s, t;
struct re
{
    int to, cap;
};
vector <int> sv[sz];
vector <re> edges;
void add_edge(int u, int v, int cap)
{
    sv[u].push_back(edges.size());
    edges.push_back({v, cap});
    sv[v].push_back(edges.size());
    edges.push_back({u, 0});// {v, u, cap} for bidirectional
}
bool us[sz];
int dfs(int v, int flow)
{
    us[v]=1;
    if(v==t) return flow;
    for(int a=0; a<sv[v].size(); a++)
    {
        int i=sv[v][a];
        int ne=edges[i].to;
        if(edges[i].cap>0 and us[ne]==0)
        {
            int re=dfs(ne, min(flow, edges[i].cap));
            if(re)
            {
                edges[i].cap-=re;
                edges[i^1].cap+=re;
                return re;
            }
        }
    }
    return 0;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n1, n2, m, k=inf;
    cin>>n1>>n2>>m;
    for(int a=0; a<m; a++)
    {
        int u, v;
        cin>>u>>v;
        u--, v--;
        add_edge(u, v+n1, 1);
    }
    for(int a=0; a<n1+n2; a++) k=min(k, int(sv[a].size()));
    s=n1+n2, t=s+1;
    for(int a=0; a<n1; a++) add_edge(s, a, sv[a].size()-k);
    for(int a=0; a<n2; a++) add_edge(a+n1, t, sv[a+n1].size()-k);
    vector <int> an[k+1];
    for(int a=k; a>=0; a--)
    {
        for(int b=0; b<n1+n2+2; b++) us[b]=0;
        while(dfs(s, inf))
        {
            for(int b=0; b<n1+n2+2; b++) us[b]=0;
        }
        for(int b=0; b<n1; b++)
        {
            for(int c=0; c<sv[b].size(); c++)
            {
                int i=sv[b][c];
                if(edges[i].to!=s and edges[i].cap) an[a].push_back(i>>1);
            }
        }
        for(int b=0; b<sv[s].size(); b++)
        {
            int i=sv[s][b];
            edges[i].cap++;
        }
        for(int b=0; b<sv[t].size(); b++)
        {
            int i=sv[t][b];
            edges[i^1].cap++;
        }
    }
    for(int a=0; a<=k; a++)
    {
        printf("%d ", an[a].size());
        for(int b=0; b<an[a].size(); b++) printf("%d ", an[a][b]+1);
        printf("\n");
    }
}