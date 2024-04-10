#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=1e5+10, inf=1e18;
set <int> se[sz];
vector <pair <int, int> > sv[sz], sp;
vector <int> tr[sz];
int nu[sz];
void dfs(int v, int h)
{
    int be=v;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, w=sv[v][a].second;
        dfs(ne, h+w);
        if(se[nu[ne]].size()>se[be].size()) be=nu[ne];
    }
    vector <pair <int, int> > ve;
    for(int a=0; a<sv[v].size(); a++)
    {
        int i=nu[sv[v][a].first];
        if(i!=be)
        {
            for(auto it=se[i].begin(); it!=se[i].end(); it++)
            {
                ve.push_back({*it, i});
            }
        }
    }

    if(sv[v].size())
    {
        if(nu[sv[v].back().first]==be) se[be].insert(-h);
        else ve.push_back({-h, nu[sv[v].back().first]});
    }
    sort(ve.begin(), ve.end());
    for(int a=0; a<ve.size(); a++)
    {
        int l1=(a) ? ve[a-1].first : -inf, r1=(a+1<ve.size()) ? ve[a+1].first : inf, l2=-inf, r2=inf;

        auto it=se[be].insert(ve[a].first).first;

        if(it!=se[be].begin())
        {
            it--, l2=(*it), it++;
        }
        it++;
        if(it!=se[be].end()) r2=(*it);
        it--;

        if(l2>l1)
        {
            sp.push_back({l2+1+h, ve[a].first+h});
        }
        else if(l1!=-inf and ve[a-1].second!=ve[a].second)
        {
            sp.push_back({l1+1+h, ve[a].first+h});
        }

        if(r2<r1)
        {
            sp.push_back({ve[a].first+1+h, r2+h});
        }
    }
    se[be].erase(-h);
    for(int a=0; a<tr[v].size(); a++) se[be].insert(tr[v][a]);
    nu[v]=be;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    for(int a=0; a<n-1; a++)
    {
        int u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        u--, v--;
        sv[u].push_back({v, w});
    }
    for(int a=0; a<m; a++)
    {
        int v, t;
        scanf("%lld%lld", &v, &t);
        v--, tr[v].push_back(t);
    }
    dfs(0, 0);
    int t=0, yk=0;
    sort(sp.begin(), sp.end());
    multiset <int> se;
    while(yk<sp.size() or se.size())
    {
        t++;
        if(se.size()==0) t=sp[yk].first;
        while(yk<sp.size() and sp[yk].first==t) se.insert(sp[yk++].second);

        if(*se.begin()<t)
        {
            t--;
            cout<<t<<" ";
            int q=0;
            for(int a=0; a<sp.size(); a++) if(sp[a].second<t) q++;
            cout<<q;
            return 0;
        }
        se.erase(se.begin());
    }
    cout<<"-1 "<<sp.size();
}