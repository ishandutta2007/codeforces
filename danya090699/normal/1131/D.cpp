#include <bits/stdc++.h>
using namespace std;
const int sz=2e3+10;
vector <int> sv[sz], tout;
int nu[sz], us[sz], cq=0;
void dfs(int v)
{
    nu[v]=cq;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(nu[ne]==-1) dfs(ne);
    }
}
void dfs2(int v)
{
    us[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(us[ne]==0) dfs2(ne);
    }
    tout.push_back(v);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    char s[n][m+2];
    for(int a=0; a<n; a++)
    {
        scanf("%s", s[a]);
        for(int b=0; b<m; b++)
        {
            if(s[a][b]=='=')
            {
                sv[a].push_back(b+n);
                sv[b+n].push_back(a);
            }
        }
    }
    for(int a=0; a<n+m; a++) nu[a]=-1;
    for(int a=0; a<n+m; a++)
    {
        if(nu[a]==-1) dfs(a), cq++;
    }
    for(int a=0; a<n+m; a++) sv[a].clear();
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++)
        {
            int u=nu[a], v=nu[b+n];
            if(s[a][b]=='>') sv[u].push_back(v);
            if(s[a][b]=='<') sv[v].push_back(u);
        }
    }
    int val[cq];
    for(int a=0; a<cq; a++)
    {
        val[a]=-1;
        if(us[a]==0) dfs2(a);
    }
    bool ok=1;
    for(int a=0; a<cq; a++)
    {
        int v=tout[a], be=1;
        for(int b=0; b<sv[v].size(); b++)
        {
            int ne=sv[v][b];
            if(val[ne]==-1) ok=0;
            else be=max(be, val[ne]+1);
        }
        val[v]=be;
    }
    if(ok)
    {
        cout<<"Yes\n";
        for(int a=0; a<n; a++) cout<<val[nu[a]]<<" ";
        cout<<"\n";
        for(int b=0; b<m; b++) cout<<val[nu[b+n]]<<" ";
    }
    else cout<<"No";
}