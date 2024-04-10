#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
vector <int> sv[sz];
int su[sz];
bool us[sz];
void dfs(int v)
{
    us[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(us[ne]==0) dfs(ne);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, q, an=0;
    cin>>n>>m>>q;
    vector <int> sp[m];
    for(int a=0; a<q; a++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x--, y--;
        sp[y].push_back(x);
        su[x]++;
    }
    if(q==0)
    {
        sp[0].push_back(0);
        su[0]++;
        an++;
    }
    for(int a=0; a<m; a++)
    {
        if(sp[a].size()==0) an++;
        for(int b=0; b+1<sp[a].size(); b++)
        {
            int u=sp[a][b], v=sp[a][b+1];
            sv[u].push_back(v);
            sv[v].push_back(u);
        }
    }
    int cq=0;
    for(int a=0; a<n; a++)
    {
        if(su[a]==0) an++;
        else if(us[a]==0)
        {
            dfs(a), cq++;
        }
    }
    an+=cq-1;
    cout<<an;
}