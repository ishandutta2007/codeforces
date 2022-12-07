#include <bits/stdc++.h>
using namespace std;
const int sz=5e3+10;
vector <pair <int, int> > sv[sz];
int us[sz], c[sz], an=1;
void dfs(int v)
{
    us[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, i=sv[v][a].second;
        if(us[ne]==1) c[i]=2, an=2;
        else
        {
            c[i]=1;
            if(us[ne]==0) dfs(ne);
        }
    }
    us[v]=2;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    for(int a=0; a<m; a++)
    {
        int u, v;
        cin>>u>>v;
        u--, v--;
        sv[u].push_back({v, a});
    }
    for(int a=0; a<n; a++) if(us[a]==0) dfs(a);
    cout<<an<<"\n";
    for(int a=0; a<m; a++) cout<<c[a]<<" ";
}