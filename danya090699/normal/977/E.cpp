#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
vector <int> sv[sz], sp;
bool us[sz];
void dfs(int v)
{
    us[v]=1;
    sp.push_back(v);
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(us[ne]==0) dfs(ne);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, an=0;
    cin>>n>>m;
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    for(int a=0; a<n; a++)
    {
        if(us[a]==0)
        {
            dfs(a);
            int ok=1;
            for(int b=0; b<sp.size(); b++) if(sv[sp[b]].size()!=2) ok=0;
            an+=ok, sp.clear();
        }
    }
    cout<<an;
}