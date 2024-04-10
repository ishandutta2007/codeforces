#include <bits/stdc++.h>
using namespace std;
const int sz=3e5+10;
vector <int> sv[sz];
int si[sz], tin[sz], tout[sz], pre[sz], timer=0;
void dfs(int v, int pr)
{
    tin[v]=timer, timer++;
    si[v]=1, pre[v]=pr;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            dfs(ne, v);
            si[v]+=si[ne];
        }
    }
    tout[v]=timer, timer++;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, x, y;
    cin>>n>>x>>y;
    x--, y--;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0, -1);
    long long an=1ll*n*(n-1);
    if(tin[x]<tin[y]) swap(x, y);
    if(tout[x]<tout[y])
    {
        int v=x;
        while(pre[v]!=y) v=pre[v];
        //cout<<si[v];
        an-=1ll*si[x]*(n-si[v]);
    }
    else an-=1ll*si[x]*si[y];
    cout<<an;
}