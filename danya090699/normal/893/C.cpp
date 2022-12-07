#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, inf=2e9;
vector <int> sv[sz];
int pr[sz], mi;
bool us[sz];
void dfs(int v)
{
    us[v]=1, mi=min(mi, pr[v]);
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(us[ne]==0) dfs(ne);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    long long an=0;
    for(int a=0; a<n; a++) cin>>pr[a];
    for(int a=0; a<m; a++)
    {
        int u, v;
        cin>>u>>v;
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    for(int a=0; a<n; a++)
    {
        if(us[a]==0)
        {
            mi=inf, dfs(a), an+=mi;
        }
    }
    cout<<an;
}