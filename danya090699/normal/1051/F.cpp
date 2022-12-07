#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=1e5+10;
vector <pair <int, int> > sv[sz];
bool us[sz], bad[sz];
int up[sz][40], h[sz], tin[sz], timer=0;
int sm[42][42], be[sz][42];
vector <pair <int, pair <int, int> > > re;
void dfs(int v)
{
    us[v]=1, tin[v]=timer, timer++;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, va=sv[v][a].second;
        if(ne!=up[v][0])
        {
            if(us[ne]==0)
            {
                h[ne]=h[v]+va, up[ne][0]=v, dfs(ne);
            }
            else
            {
                //cout<<v<<" "<<ne<<"\n";
                bad[v]=1, bad[ne]=1, re.push_back(make_pair(va, make_pair(v, ne)));
            }
        }
    }
}
int lca(int u, int v)
{
    if(tin[u]<tin[v]) swap(u, v);
    for(int i=19; i>=0; i--)
    {
        int ne=up[u][i];
        if(tin[ne]>tin[v]) u=ne;
    }
    if(tin[u]>tin[v]) u=up[u][0];
    return u;
}
int dis(int u, int v)
{
    int u2=lca(u, v);
    return (h[u]-h[u2])+(h[v]-h[u2]);
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    for(int a=0; a<m; a++)
    {
        int u, v, va;
        scanf("%lld%lld%lld", &u, &v, &va);
        u--, v--;
        sv[u].push_back(make_pair(v, va));
        sv[v].push_back(make_pair(u, va));
    }
    h[0]=0, dfs(0);
    vector <int> sp;
    for(int a=0; a<n; a++) if(bad[a]) sp.push_back(a);
    //cout<<sp.size();
    for(int i=1; i<20; i++)
    {
        for(int a=0; a<n; a++) up[a][i]=up[up[a][i-1]][i-1];
    }
    for(int a=0; a<sp.size(); a++)
    {
        for(int b=0; b<n; b++) be[b][a]=dis(b, sp[a]);
        for(int b=0; b<sp.size(); b++) sm[a][b]=dis(sp[a], sp[b]);
    }
    for(int a=0; a<re.size(); a++)
    {
        int u=re[a].second.first, v=re[a].second.second, va=re[a].first;
        int u2, v2;
        for(int b=0; b<sp.size(); b++)
        {
            if(sp[b]==u) u2=b;
            if(sp[b]==v) v2=b;
        }
        for(int b=0; b<sp.size(); b++)
        {
            for(int c=0; c<sp.size(); c++) sm[b][c]=min(sm[b][c], sm[b][u2]+va+sm[v2][c]);
        }
        //cout<<u<<" "<<v<<" "<<va<<" "<<sm[0][5]<<"\n";
    }
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        int an=dis(u, v);
        for(int b=0; b<sp.size(); b++)
        {
            for(int c=0; c<sp.size(); c++)
            {
                /*if(be[u][b]+sm[b][c]+be[v][c]==4)
                {
                    cout<<sp[b]<<" "<<sp[c]<<"\n";
                }*/
                an=min(an, be[u][b]+sm[b][c]+be[v][c]);
            }
        }
        printf("%lld\n", an);
    }
}