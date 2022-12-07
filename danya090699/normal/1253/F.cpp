#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e18;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k, q;
    cin>>n>>m>>k>>q;
    vector <pair <int, int> > sv[n];
    for(int a=0; a<m; a++)
    {
        int u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        u--, v--;
        sv[u].push_back({v, w});
        sv[v].push_back({u, w});
    }
    int di[n], pr[n];
    for(int a=0; a<n; a++) di[a]=inf;
    set <pair <int, int> > se;
    for(int a=0; a<k; a++)
    {
        di[a]=0, pr[a]=a, se.insert({0, a});
    }
    while(se.size())
    {
        int v=(*se.begin()).second;
        se.erase(se.begin());
        for(int a=0; a<sv[v].size(); a++)
        {
            int ne=sv[v][a].first, w=di[v]+sv[v][a].second;
            if(w<di[ne])
            {
                se.erase({di[ne], ne});
                di[ne]=w, pr[ne]=pr[v];
                se.insert({di[ne], ne});
            }
        }
    }
    vector <pair <int, pair <int, int> > > re;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<sv[a].size(); b++)
        {
            int u=a, v=sv[a][b].first, w=sv[a][b].second;
            if(u<v and pr[u]!=pr[v]) re.push_back({di[u]+di[v]+w, {pr[u], pr[v]}});
        }
    }
    sort(re.begin(), re.end());

    vector <int> sp[k];
    vector <pair <int, int> > zap[k];
    int nu[k], si[k], an[q];

    for(int a=0; a<k; a++) sp[a].push_back(a), nu[a]=a, si[a]=1;

    for(int a=0; a<q; a++)
    {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        zap[u].push_back({v, a});
        zap[v].push_back({u, a});
    }

    for(int a=0; a<re.size(); a++)
    {
        int u=nu[re[a].second.first], v=nu[re[a].second.second], w=re[a].first;
        if(nu[u]!=nu[v])
        {
            if(si[u]<si[v]) swap(u, v);
            for(int b=0; b<sp[v].size(); b++)
            {
                int v2=sp[v][b];
                for(int c=0; c<zap[v2].size(); c++)
                {
                    int v3=zap[v2][c].first, i=zap[v2][c].second;
                    if(nu[v3]==u) an[i]=w;
                }
            }
            while(sp[v].size())
            {
                int v2=sp[v].back();
                nu[v2]=u, sp[u].push_back(v2);
                sp[v].pop_back();
            }
            si[u]+=si[v];
        }
    }
    for(int a=0; a<q; a++) printf("%lld\n", an[a]);
}