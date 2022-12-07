#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=3e5+10;
vector <pair <int, int> > sv[sz], sv2[sz];
int tin[sz], fup[sz], timer=1;
void dfs(int v, int pr)
{
    tin[v]=timer, fup[v]=timer++;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first;
        if(ne!=pr)
        {
            if(tin[ne]) fup[v]=min(fup[v], tin[ne]);
            else dfs(ne, v), fup[v]=min(fup[v], fup[ne]);
        }
    }
}
int c[sz], s[sz], k;
int cq=1, nu[sz], c2[sz], su[sz];
void dfs2(int v, int i)
{
    nu[v]=i, c2[i]+=c[v], su[i]+=s[v];
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, w=sv[v][a].second;
        if(nu[ne]==-1)
        {
            if(tin[v]<fup[ne])
            {
                sv2[i].push_back({cq, w});
                dfs2(ne, cq++);
            }
            else dfs2(ne, i);
        }
    }
}
int dow[sz];
void dfs3(int v, int w)
{
    dow[v]=c2[v];
    for(int a=0; a<sv2[v].size(); a++)
    {
        int ne=sv2[v][a].first;
        dfs3(ne, sv2[v][a].second);
        su[v]+=su[ne], dow[v]+=dow[ne];
    }
    if(su[v]!=0 and su[v]!=k) dow[v]=max(0ll, dow[v]-w);
}
int up[sz], an[sz];
void dfs4(int v)
{
    an[v]=c2[v]+up[v];
    for(int a=0; a<sv2[v].size(); a++)
    {
        int ne=sv2[v][a].first;
        an[v]+=dow[ne];
    }
    for(int a=0; a<sv2[v].size(); a++)
    {
        int ne=sv2[v][a].first, w=sv2[v][a].second;
        if(su[ne]==0 or su[ne]==k) up[ne]=an[v]-dow[ne];
        else up[ne]=max(0ll, an[v]-dow[ne]-w);
        dfs4(ne);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m>>k;
    for(int a=0; a<k; a++)
    {
        int v;
        scanf("%lld", &v);
        v--, s[v]=1;
    }
    for(int a=0; a<n; a++) scanf("%lld", &c[a]);
    int w[m];
    for(int a=0; a<m; a++) scanf("%lld", &w[a]);
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        sv[u].push_back({v, w[a]});
        sv[v].push_back({u, w[a]});
    }
    dfs(0, 0);
    for(int a=0; a<n; a++) nu[a]=-1;
    dfs2(0, 0);
    dfs3(0, 0);
    dfs4(0);
    for(int a=0; a<n; a++) printf("%lld ", an[nu[a]]);
}