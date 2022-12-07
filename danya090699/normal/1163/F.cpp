#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=2e5+10, inf=1e18;
int ro[sz][3], way[sz], h[sz];
vector <pair <int, int> > tr[sz];
void dfs(int v)
{
    for(int a=0; a<tr[v].size(); a++)
    {
        int ne=tr[v][a].first, i=tr[v][a].second;
        h[ne]=h[v]+way[i], dfs(ne);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, q;
    cin>>n>>m>>q;
    vector <pair <int, int> > sv[n];
    for(int a=0; a<m; a++)
    {
        int u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        u--, v--;
        sv[u].push_back({v, a});
        sv[v].push_back({u, a});
        ro[a][0]=u, ro[a][1]=v, ro[a][2]=w;
    }
    int di[n], pr[n], di2[n];
    set <pair <int, int> > se;
    for(int a=0; a<n; a++) di[a]=inf;
    di[0]=0;
    se.insert({0, 0});
    while(se.size())
    {
        int v=(*se.begin()).second;
        if(v)
        {
            int pre=ro[pr[v]][0];
            if(pre==v) pre=ro[pr[v]][1];

            tr[pre].push_back({v, pr[v]});
        }
        se.erase(se.begin());
        for(int a=0; a<sv[v].size(); a++)
        {
            int ne=sv[v][a].first, i=sv[v][a].second, w=ro[i][2];
            if(di[ne]>di[v]+w)
            {
                se.erase({di[ne], ne});
                di[ne]=di[v]+w, pr[ne]=i;
                se.insert({di[ne], ne});
            }
        }
    }

    int v=n-1;
    while(v)
    {
        int i=pr[v];
        way[i]=1;
        if(v!=ro[i][0]) v=ro[i][0];
        else v=ro[i][1];
    }

    dfs(0);

    for(int a=0; a<n; a++) di2[a]=inf;
    di2[n-1]=0;
    se.insert({0, n-1});
    while(se.size())
    {
        int v=(*se.begin()).second;
        se.erase(se.begin());
        for(int a=0; a<sv[v].size(); a++)
        {
            int ne=sv[v][a].first, i=sv[v][a].second, w=ro[i][2];
            if(di2[ne]>di2[v]+w)
            {
                se.erase({di2[ne], ne});
                di2[ne]=di2[v]+w;
                se.insert({di2[ne], ne});
            }
        }
    }

    vector <int> add[n+1], del[n+1];

    for(int a=0; a<m; a++)
    {
        if(way[a]==0)
        {
            int u=ro[a][0], v=ro[a][1], w=ro[a][2];
            if(h[u]>h[v]) swap(u, v);
            add[h[u]].push_back(di[u]+w+di2[v]);
            del[h[v]].push_back(di[u]+w+di2[v]);
        }
    }

    multiset <int> sp;
    int be[n];
    for(int a=0; a<n; a++)
    {
        while(add[a].size()) sp.insert(add[a].back()), add[a].pop_back();

        while(del[a].size()) sp.erase(sp.find(del[a].back())), del[a].pop_back();

        if(sp.size()) be[a]=(*sp.begin());
        else be[a]=inf;
    }

    for(int a=0; a<q; a++)
    {
        int i, x, an;
        scanf("%lld%lld", &i, &x);
        i--;
        if(way[i])
        {
            int u=ro[i][0], v=ro[i][1], w=ro[i][2];
            if(h[u]>h[v]) swap(u, v);
            an=min(di[n-1]-w+x, be[h[u]]);
        }
        else
        {
            an=di[n-1];
            int u=ro[i][0], v=ro[i][1];
            an=min(an, di[u]+di2[v]+x);
            an=min(an, di[v]+di2[u]+x);
        }
        printf("%lld\n", an);
    }
}