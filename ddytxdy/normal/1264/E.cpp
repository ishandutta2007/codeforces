#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int N=110,M=N*N*10,inf=0x3f3f3f3f;
int n,m,a[N][N],ver[M],nxt[M],edge[M],val[M],head[M],tot=1,S,T,cnt,id[N][N],d[M],f[M],ans,mx[M],w[N][N];bool vis[M];
queue<int>q;
void add(int x,int y,int f,int v){
    ver[++tot]=y;edge[tot]=f;val[tot]=v;nxt[tot]=head[x];head[x]=tot;
    ver[++tot]=x;edge[tot]=0;val[tot]=-v;nxt[tot]=head[y];head[y]=tot;
}
bool bfs(){
    memset(d,0x3f,sizeof(d));
    q.push(S);vis[S]=1;d[S]=0;
    while(q.size()){
        int x=q.front();q.pop();vis[x]=0;
        for(int i=head[x],y;i;i=nxt[i]){
            if(edge[i]&&d[y=ver[i]]>d[x]+val[i]){
                d[y]=d[x]+val[i];f[y]=i;
                if(!vis[y])q.push(y),vis[y]=1;
            }
        }
    }
    return d[T]!=inf;
}
void dfs(){
    ans+=d[T];int y=ver[f[T]^1];
    if(val[f[T]]==mx[y])add(y,T,1,++mx[y]);
    for(int x=T;x!=S;x=ver[f[x]^1])
        edge[f[x]]--,edge[f[x]^1]++;
}
int main(){
    scanf("%d%d",&n,&m);cnt=n;
    for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)id[i][j]=id[j][i]=++cnt;
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)a[i][j]=a[j][i]=2;
    for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),a[x][y]=1,a[y][x]=0;
    S=++cnt;T=++cnt;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        if(a[i][j]==1)add(S,j,1,0);
        else if(a[i][j]==2)add(id[i][j],j,1,0),w[i][j]=tot;
    }
    for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)if(a[i][j]==2)add(S,id[i][j],1,0);
    for(int i=1;i<=n;i++)add(i,T,1,0);
    while(bfs())dfs();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            if(a[i][j]!=2)printf("%d",a[i][j]);
            else printf("%d",edge[w[i][j]]);
        puts("");
    }
    return 0;
}