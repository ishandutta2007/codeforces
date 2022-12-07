#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
vector <int> sv[sz], svr[sz], tout;
bool us[sz];
int cnu[sz], csi[sz], cq=0;
void dfs(int v)
{
    us[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(us[ne]==0) dfs(ne);
    }
    tout.push_back(v);
}
void dfs2(int v)
{
    cnu[v]=cq, csi[cq]++;
    for(int a=0; a<svr[v].size(); a++)
    {
        int ne=svr[v][a];
        if(cnu[ne]==-1) dfs2(ne);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, h;
    cin>>n>>m>>h;
    int va[n];
    for(int a=0; a<n; a++) scanf("%d", &va[a]);
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        if((va[u]+1)%h==va[v])
        {
            sv[u].push_back(v);
            svr[v].push_back(u);
        }
        if((va[v]+1)%h==va[u])
        {
            sv[v].push_back(u);
            svr[u].push_back(v);
        }
    }
    for(int a=0; a<n; a++) if(us[a]==0) dfs(a);
    reverse(tout.begin(), tout.end());
    for(int a=0; a<n; a++) cnu[a]=-1;
    for(int a=0; a<n; a++)
    {
        int v=tout[a];
        if(cnu[v]==-1)
        {
            dfs2(v), cq++;
        }
    }
    int be=1e9, bnu;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<sv[a].size(); b++)
        {
            int ne=sv[a][b];
            if(cnu[a]!=cnu[ne]) us[cnu[a]]=0;
        }
    }
    for(int a=0; a<cq; a++)
    {
        if(us[a] and csi[a]<be)
        {
            be=csi[a], bnu=a;
        }
    }
    cout<<be<<"\n";
    for(int a=0; a<n; a++) if(cnu[a]==bnu) printf("%d ", a+1);
}