#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
vector <int> sv[sz];
int va[sz], an[sz];
bool us[sz];
map <int, int> ma[sz];
void dfs(int v, int pr)
{
    us[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(us[ne]==0) dfs(ne, v);
    }
    if(pr!=-1)
    {
        if(ma[v].find(pr)!=ma[v].end())
        {
            int i=ma[v][pr];
            an[i]=-va[v];
        }
        else
        {
            int i=ma[pr][v];
            an[i]=va[v];
        }
        va[pr]+=va[v], va[v]=0;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n;
    for(int a=0; a<n; a++) scanf("%d", &va[a]);
    cin>>m;
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        ma[u][v]=a;
        sv[v].push_back(u);
        sv[u].push_back(v);
    }
    dfs(0, -1);
    if(va[0]==0)
    {
        cout<<"Possible\n";
        for(int a=0; a<m; a++) printf("%d\n", an[a]);
    }
    else cout<<"Impossible";
}