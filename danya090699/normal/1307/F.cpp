#include <bits/stdc++.h>
using namespace std;
const int sz=4e5+10;
vector <int> sv[sz];
int di[sz], pr[sz], si[sz];
int get_rt(int v)
{
    if(pr[v]==-1) return -1;
    if(pr[v]!=v) pr[v]=get_rt(pr[v]);
    return pr[v];
}
void mer(int u, int v)
{
    u=get_rt(u), v=get_rt(v);
    if(u!=v)
    {
        if(si[u]<si[v]) swap(u, v);
        si[u]+=si[v];
        pr[v]=u;
    }
}
int tin[sz], h[sz], timer=0, up[sz][20];
void dfs(int v)
{
    tin[v]=timer++;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=up[v][0]) up[ne][0]=v, h[ne]=h[v]+1, dfs(ne);
    }
}
int lca(int u, int v)
{
    if(tin[v]<tin[u]) swap(u, v);
    for(int i=19; i>=0; i--)
    {
        if(tin[up[v][i]]>tin[u]) v=up[v][i];
    }
    if(v!=u) v=up[v][0];
    return v;
}
int n, k, r, m;
int go2(int v, int l)
{
    int i=0;
    while(l)
    {
        if(l&1) v=up[v][i];
        l>>=1, i++;
    }
    return v;
}
int go(int v, int u, int lc)
{
    if(h[v]-h[lc]>=k) return go2(v, k);
    else return go2(u, h[v]+h[u]-2*h[lc]-k);
}
main()
{
	//freopen("input.txt", "r", stdin);

    cin>>n>>k>>r;
    m=n-1;
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(n);
        sv[n].push_back(u);
        sv[v].push_back(n);
        sv[n++].push_back(v);
    }
    queue <int> qu;
    for(int a=0; a<n; a++) pr[a]=-1, di[a]=-1, si[a]=1;
    for(int a=0; a<r; a++)
    {
        int v;
        scanf("%d", &v);
        v--, pr[v]=v, di[v]=0, qu.push(v);
    }
    while(qu.size())
    {
        int v=qu.front();
        if(di[v]<k)
        {
            for(int a=0; a<sv[v].size(); a++)
            {
                int ne=sv[v][a];
                if(pr[ne]==-1)
                {
                    di[ne]=di[v]+1;
                    pr[ne]=ne;
                    qu.push(ne);
                }
                mer(v, ne);
            }
        }
        qu.pop();
    }
    dfs(0);
    for(int i=1; i<20; i++)
    {
        for(int a=0; a<n; a++) up[a][i]=up[up[a][i-1]][i-1];
    }
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        int lc=lca(u, v);
        if(h[u]+h[v]-2*h[lc]<=2*k) printf("YES\n");
        else
        {
            u=go(u, v, lc);
            v=go(v, u, lc);

            u=get_rt(u);
            v=get_rt(v);

            printf(u==v and u!=-1 ? "YES\n" : "NO\n");
        }
    }
}