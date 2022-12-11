#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3030;
int n,ver[N*2],nxt[N*2],head[N],tot=1,sz[N*2],fr[N][N];LL f[N][N],ans;
void add(int x,int y){ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;}
void cmax(LL &x,LL y){y>x?x=y:0;}
void dfs(int id){
    sz[id]=1;
    for(int i=head[ver[id]];i;i=nxt[i])
        if(id^i^1)dfs(i),sz[id]+=sz[i];
    sz[id^1]=n-sz[id];
}
void dfs2(int id,int z){
    fr[ver[id]][z]=id;
    for(int i=head[ver[id]];i;i=nxt[i])
        if(i^id^1)dfs2(i,z);
}
void dfs(int x,int y){
    if(f[x][y]||x==y)return;
    int xx=ver[fr[x][y]^1],yy=ver[fr[y][x]^1];
    dfs(xx,y);dfs(x,yy);
    f[x][y]=f[y][x]=max(f[xx][y],f[x][yy])+sz[fr[x][y]]*sz[fr[y][x]];
}
int main(){
    scanf("%d",&n);ver[0]=1;
    for(int i=1,x,y;i<n;i++){
        scanf("%d%d",&x,&y);
        add(x,y);add(y,x);
    }
    dfs(0);
    for(int i=1;i<=n;i++)for(int j=head[i];j;j=nxt[j])dfs2(j,i);
    for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)dfs(i,j),ans=max(ans,f[i][j]);
    printf("%lld\n",ans);
    return 0;
}