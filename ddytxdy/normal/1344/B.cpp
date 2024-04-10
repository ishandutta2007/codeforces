#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m,dx[4]={-1,0,0,1},dy[4]={0,1,-1,0},ans;char c[N][N];bool fl[N],fr[N],f1,f2;bool vis[N][N];
void fail(){puts("-1"),exit(0);}
void dfs(int x,int y){
    vis[x][y]=1;
    for(int k=0;k<4;k++){
        int xx=x+dx[k],yy=y+dy[k];
        if(xx>0&&xx<=n&&yy>0&&yy<=m&&c[xx][yy]=='#'&&!vis[xx][yy])dfs(xx,yy);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%s",c[i]+1);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(c[i][j]=='#')fl[i]=fr[j]=1;
    for(int i=1;i<=n;i++)f1|=!fl[i];f2=1;
    for(int i=1;i<=m;i++)f2&=fr[i];
    if(f1&&f2)fail();
    f1=0;f2=1;
    for(int i=1;i<=m;i++)f1|=!fr[i];
    for(int i=1;i<=n;i++)f2&=fl[i];
    if(f1&&f2)fail();
    for(int i=1;i<=n;i++){
        int num=0;
        for(int j=1;j<=m;j++)if(c[i][j]=='#'&&c[i][j-1]!='#')num++;
        if(num>1)fail();
    }
    for(int i=1;i<=m;i++){
        int num=0;
        for(int j=1;j<=n;j++)if(c[j][i]=='#'&&c[j-1][i]!='#')num++;
        if(num>1)fail();
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
        if(c[i][j]=='#'&&!vis[i][j])dfs(i,j),ans++;
    cout<<ans;
    return 0;
}