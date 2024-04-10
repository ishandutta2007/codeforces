#include<bits/stdc++.h>
using namespace std;
vector<int>G[500009];
vector<int>Query[500009];
int dep[500009];
char str[500009];
int ans[500009];
int height[500009];
void dfs(int u,int d)
{
    for(int v:Query[u]) ans[v]^=dep[height[v]];
    for(int v:G[u]) dfs(v,d+1);

    dep[d]^=(1<<(int)(str[u]-'a'));

    for(int v:Query[u]) ans[v]^=dep[height[v]];
}
int main()
{
    int n,m,x,y;
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&x);
        G[x].push_back(i);
    }
    scanf("%s",(str+1));
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        Query[x].push_back(i);
        height[i]=y;
    }
    dfs(1,1);
    for(int i=1;i<=m;i++)
    {
        if(ans[i]&(ans[i]-1)) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}