#include<cstdio>
const int INF=1e9;
int n,c[200001],used[200001],used1[200001],g[200001],ans;
int dfs(int u){
    int t;
    used1[u]=1;
    if(used[g[u]]){used1[u]=0;used[u]=1;return 0;}
    if(used1[g[u]]){used1[u]=0;used[u]=1;return g[u];}
    t=dfs(g[u]);
    used1[u]=0;used[u]=1;return t;
}
int dfs1(int u){
    int t=INF;
    used1[u]=1;
    if(!used1[g[u]])t=dfs1(g[u]);
    used1[u]=0;
    return c[u]<t?c[u]:t;
}
int main()
{
    int t;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",c+i);
    for(int i=1;i<=n;i++)scanf("%d",g+i);
    for(int i=1;i<=n;i++)
      if(!used[i]&&(t=dfs(i)))ans+=dfs1(t);
    printf("%d",ans);
    return 0;
}