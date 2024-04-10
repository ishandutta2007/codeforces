#include<bits/stdc++.h>
using namespace std;
const int N=60,inf=0x3f3f3f3f,M=2*N*N,K=N*N*N;
int n,m,k,c,d,cnt,id[N*2][N],S,T,ver[K],nxt[K],f[K],v[K],head[M],tot=1,dis[M],q[K],l,r,fr[M],ans;bool vis[M];
void add(int x,int y,int ff,int vv){
    ver[++tot]=y;f[tot]=ff;v[tot]=vv;nxt[tot]=head[x];head[x]=tot;
    ver[++tot]=x;f[tot]=0;v[tot]=-vv;nxt[tot]=head[y];head[y]=tot;
}
bool bfs(){
    memset(dis,0x3f,sizeof(dis));
    dis[S]=0;q[1]=S;l=r=1;vis[S]=1;
    while(l<=r){
        int x=q[l++];vis[x]=0;
        for(int i=head[x],y;i;i=nxt[i]){
            y=ver[i];
            if(f[i]&&dis[y]>dis[x]+v[i]){
                dis[y]=dis[x]+v[i];fr[y]=i;
                if(!vis[y])q[++r]=y;
            }
        }
    }
    return dis[T]!=inf;
}
void dfs(){
    ans+=dis[T];
    for(int i=fr[T];i;i=fr[ver[i^1]]){
        f[i]--;f[i^1]++;
        if(v[i]<=c)continue;
        int x=ver[i^1],y=ver[i];
        add(x,y,1,v[i]+2*d);
    }
}
int main(){
    scanf("%d%d%d%d%d",&n,&m,&k,&c,&d);
    for(int i=0;i<=k+n;i++)for(int j=1;j<=n;j++)id[i][j]=++cnt;
    S=++cnt;T=++cnt;
    for(int i=0;i<=k+n;i++)add(id[i][1],T,1e9,0);
    for(int i=0;i<k+n;i++)for(int j=1;j<=n;j++)add(id[i][j],id[i+1][j],1e9,c);
    for(int i=1,x;i<=k;i++){
        scanf("%d",&x);
        add(S,id[0][x],1,0);
    }
    for(int i=1,x,y;i<=m;i++){
        scanf("%d%d",&x,&y);
        for(int j=0;j<k+n;j++){
            add(id[j][x],id[j+1][y],1,c+d);
            add(id[j][y],id[j+1][x],1,c+d);
        }
    }
    while(bfs())dfs();
    printf("%d\n",ans);
    return 0;
}