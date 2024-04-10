#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10;
multiset <int> sv[sz];
set <int> sv2[sz];
vector <int> sp;
int st[sz];
void dfs(int v)
{
    while(sv[v].size())
    {
        int ne=*sv[v].begin();
        sv[v].erase(sv[v].begin());
        sv[ne].erase(sv[ne].find(v));
        dfs(ne);
    }
    sp.push_back(v);
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].insert(v), sv[v].insert(u);
        st[u]++, st[v]++;
        sv2[u].insert(v), sv2[v].insert(u);
    }
    int pr=-1;
    for(int a=0; a<n; a++)
    {
        if(st[a]&1)
        {
            if(pr==-1) pr=a;
            else
            {
                sv[a].insert(pr), sv[pr].insert(a);
                pr=-1;
            }
        }
    }
    vector <pair <int, int> > an;
    for(int a=0; a<n; a++)
    {
        if(sv[a].size())
        {
            dfs(a);
            for(int b=0; b+1<sp.size(); b++)
            {
                if(b&1)
                {
                    int u=sp[b], v=sp[b+1];
                    if(sv2[v].count(u))
                    {
                        sv2[u].erase(v), sv2[v].erase(u);
                        an.push_back({u, v});
                    }
                }
            }
            sp.clear();
        }
    }
    for(int a=0; a<n; a++)
    {
        if(sv2[a].size()*2>st[a])
        {
            int ne=*sv2[a].begin();
            sv2[a].erase(ne), sv2[ne].erase(a);
            an.push_back({a, ne});
        }
    }
    cout<<an.size()<<"\n";
    for(int a=0; a<an.size(); a++)
    {
        printf("%d %d\n", an[a].first+1, an[a].second+1);
    }
}