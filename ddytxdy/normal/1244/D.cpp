#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+50;
int n,w[3][N],ver[N*2],nxt[N*2],head[N],tot,d[N],r,g[N][3][3],xx,yy,a[N];bool vis[N];
LL f[N][3][3],anss;
void cmin(LL &x,LL y){y<x?x=y:0;}
void add(int x,int y){ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;d[y]++;}
void dfs(int x,int ff){
    int y=0;LL dat;
    for(int i=head[x];i;i=nxt[i])if(ver[i]!=ff)dfs(y=ver[i],x);
    for(int j=0;j<3;j++)
        for(int k=0;k<3;k++)
            if(j!=k&&(dat=f[y][j][k]+w[3-j-k][x])<f[x][k][3-j-k])
                g[x][k][3-j-k]=j,f[x][k][3-j-k]=dat;
}
void dfs(int x,int ff,int c1,int c2){
    a[x]=c2+1;
    for(int i=head[x];i;i=nxt[i])if(ver[i]!=ff)dfs(ver[i],x,g[x][c1][c2],c1);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<3;i++)for(int j=1;j<=n;j++)scanf("%d",&w[i][j]);
    for(int i=1,x,y;i<n;i++){
        scanf("%d%d",&x,&y);
        add(x,y);add(y,x);
    }
    for(int i=1;i<=n;i++)
        if(d[i]>2)puts("-1"),exit(0);
        else if(d[i]==1)r=i;
    memset(f,0x3f,sizeof(f));memset(f[0],0,sizeof(f[0]));
    dfs(r,0);anss=1e18;
    for(int i=0;i<3;i++)for(int j=0;j<3;j++)if(i!=j&&f[r][i][j]<anss)anss=f[r][i][j],xx=i,yy=j;
    dfs(r,0,xx,yy);cout<<anss<<endl;
    for(int i=1;i<=n;i++)printf("%d ",a[i]);
    return 0;
}