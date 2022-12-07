#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
int va[sz], pr[sz];
vector <int> tr[sz], sv2[sz];
long long an=0, add=0;
void dfs(int v, long long su)
{
    add=max(add, su+va[v]);
    for(int a=0; a<tr[v].size(); a++)
    {
        int ne=tr[v][a];
        dfs(ne, su+va[v]);
    }
}
void dfs2(int v, int pr, long long su)
{
    an=max(an, su+va[v]);
    for(int a=0; a<sv2[v].size(); a++)
    {
        int ne=sv2[v][a];
        if(ne!=pr) dfs2(ne, v, su+va[v]);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, s;
    cin>>n>>m;
    for(int a=0; a<n; a++) scanf("%d", &va[a]), pr[a]=-1;
    set <int> sv[n];
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].insert(v), sv[v].insert(u);
        sv2[u].push_back(v);
        sv2[v].push_back(u);
    }
    cin>>s;
    s--;
    set <pair <int, int> > se;
    for(int a=0; a<n; a++) se.insert({sv[a].size(), a});
    //cout<<1;
    while(se.size() and (*se.begin()).first<2)
    {
        int v=(*se.begin()).second;
        se.erase(se.begin());
        if(sv[v].size())
        {
            int u=*sv[v].begin();
            sv[v].erase(u);
            se.erase({sv[u].size(), u});
            sv[u].erase(v);
            se.insert({sv[u].size(), u});
            pr[v]=u, tr[u].push_back(v);
        }

    }
    if(se.size())
    {
        for(auto it=se.begin(); it!=se.end(); it++)
        {
            int v=(*it).second;
            an+=va[v], va[v]=0;
        }
        if(pr[s]!=-1)
        {
            while(pr[s]!=-1) an+=va[s], va[s]=0, s=pr[s];
        }
        for(int a=0; a<n; a++)
        {
            if(pr[a]==-1) dfs(a, 0);
        }
        an+=add;
    }
    else dfs2(s, -1, 0);

    cout<<an;
}