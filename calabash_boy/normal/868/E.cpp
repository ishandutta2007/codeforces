#include<bits/stdc++.h>
using namespace std;

int n,m,cnt=0,root,ans=0x3f3f3f3f,head[60],a[60],cd[60],c[60][60],f[2][60],dp[60][60][60][60];
struct edge{
    int u,v,w,next;
}e[120];

void add(int u,int v,int w){
    e[++cnt]=(edge){u,v,w,head[u]};
    head[u]=cnt;
}

void dfs(int u,int fa){
    for(int i=head[u];i;i=e[i].next)
      if(e[i].v!=fa)
        dfs(e[i].v,u),a[u]+=a[e[i].v];
}

int solve(int u,int v,int s1,int s2){
    if(!s1&&!s2)return 0;
    if(!s1)return 0x3f3f3f3f;
    int &ret=dp[u][v][s1][s2];
    if(ret<0x3f3f3f3f)return ret;
    if(cd[v]==1){
        ret=solve(v,u,s2,0)+c[u][v];
        return ret;
    }
    for(int i=head[v];i;i=e[i].next)
      if(e[i].v!=u)
        for(int k=0;k<=s1;k++)
          solve(v,e[i].v,k,s1+s2-k);
    memset(f[1],0,sizeof(f[1]));
    f[1][0]=0x3f3f3f3f;
    bool b=0;
    for(int i=head[v];i;i=e[i].next)
      if(e[i].v!=u){
        memset(f[b],0,sizeof(f[b]));
        for(int j=0;j<=s1;j++)
          for(int k=0;k+j<=s1;k++)
            f[b][j+k]=max(f[b][j+k],min(f[b^1][j],solve(v,e[i].v,k,s1+s2-k)));
        b^=1;
      }
    ret=f[b^1][s1]+c[u][v];
    return ret;
}

int main(){
    int x,y,z;
    memset(dp,0x3f,sizeof(dp));
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);add(y,x,z);
        cd[x]++;cd[y]++;
        c[x][y]=c[y][x]=z;
    }
    scanf("%d%d",&root,&m);
    for(int i=1;i<=m;i++)scanf("%d",&x),a[x]++;
    dfs(root,0);
    for(int i=head[root];i;i=e[i].next)
      ans=min(ans,solve(root,e[i].v,a[e[i].v],m-a[e[i].v]));
    printf("%d",ans);
    return 0;
}