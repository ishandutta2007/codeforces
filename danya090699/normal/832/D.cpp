//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
int n, q, tin[sz], tout[sz], h[sz], pr[sz], up[17][sz], timer=0;
vector <int> sv[sz];
void dfs(int v, int he)
{
    h[v]=he, tin[v]=timer;
    timer++;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        dfs(ne, he+1);
    }
    tout[v]=timer, timer++;
}
bool is(int u, int v)
{
    return(tin[u]<=tin[v] and tout[u]>=tout[v]);
}
int lca(int u, int v)
{
    if(tin[u]>tin[v]) swap(u, v);
    if(tout[u]<tout[v])
    {
        for(int a=16; a>=0; a--)
        {
            int ne=up[a][u];
            if(tout[ne]<tout[v]) u=ne;
        }
        u=pr[u];
    }
    return u;
}
int ch(int s, int t, int f)
{
    if(is(f, s) and is(f, t))
    {
        int v=lca(s, t);
        return h[v]-h[f]+1;
    }
    else if(is(f, s)==0 and is(f, t)==0)
    {
        int u=lca(f, s), v=lca(f, t);
        if(u==v)
        {
            int x=lca(s, t);
            return (h[x]-h[u])+(h[f]-h[u]+1);
        }
        else return h[f]-max(h[u], h[v])+1;
    }
    else return 1;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>q;
    pr[0]=0;
    for(int a=1; a<n; a++)
    {
        scanf("%d", &pr[a]);
        pr[a]--, sv[pr[a]].push_back(a);
    }
    dfs(0, 0);
    for(int a=0; a<n; a++) up[0][a]=pr[a];
    for(int a=1; a<17; a++)
    {
        for(int b=0; b<n; b++) up[a][b]=up[a-1][up[a-1][b]];
    }
    for(int a=0; a<q; a++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        x--, y--, z--;
        int an=ch(y, z, x);
        an=max(an, ch(x, z, y));
        an=max(an, ch(x, y, z));
        cout<<an<<"\n";
    }
}