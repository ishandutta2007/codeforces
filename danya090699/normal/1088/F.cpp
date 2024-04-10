#include <bits/stdc++.h>
using namespace std;
const int sz=5e5+10;
int va[sz], up[sz][20];
vector <int> sv[sz];
int dfs(int v)
{
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=up[v][0])
        {
            up[ne][0]=v, dfs(ne);
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, rt=0;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        scanf("%d", &va[a]);
        if(va[a]<va[rt]) rt=a;
    }
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    up[rt][0]=rt, dfs(rt);
    for(int i=1; i<20; i++)
    {
        for(int a=0; a<n; a++) up[a][i]=up[up[a][i-1]][i-1];
    }
    long long an=0;
    for(int a=0; a<n; a++)
    {
        if(a!=rt)
        {
            long long be=1e18;
            for(int i=0; i<20; i++) be=min(be, 1ll*i*va[up[a][i]]+va[a]+va[up[a][i]]);
            an+=be;
        }
    }
    cout<<an;
}