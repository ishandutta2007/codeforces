#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
vector <int> sv[sz];
int tin[sz], timer=0, h[sz], up[sz][20];
void dfs(int v)
{
    tin[v]=timer++;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=up[v][0]) h[ne]=h[v]+1, up[ne][0]=v, dfs(ne);
    }
}
int lca(int u, int v)
{
    if(tin[u]>tin[v]) swap(u, v);
    for(int i=19; i>=0; i--)
    {
        int ne=up[v][i];
        if(tin[ne]>tin[u]) v=ne;
    }
    if(v!=u) v=up[v][0];
    return v;
}
int di(int u, int v)
{
    int u2=lca(u, v);
    return h[u]+h[v]-2*h[u2];
}
main()
{
	//freopen("input.txt", "r", stdin);
	int n;
	cin>>n;
	for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
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
        int x, y, u, v, k, ok=0, t;
        scanf("%d%d%d%d%d", &x, &y, &u, &v, &k);
        x--, y--, u--, v--;
        t=di(u, v);
        if(t<=k and (t&1)==(k&1)) ok=1;
        for(int i=0; i<2; i++)
        {
            t=di(u, x)+1+di(v, y);
            if(t<=k and (t&1)==(k&1)) ok=1;
            swap(x, y);
        }
        printf(ok ? "YES\n" : "NO\n");
    }
}