#include<bits/stdc++.h>
using namespace std;
const int N=2e6+50;
int n,m,q[N],l,r,f[N],g[N],num[N*2];char c[N];bool vis[N];
void f1(int id,int &x,int &y){x=id/m;y=id%m;}
int f2(int x,int y){return x*m+y;}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%s",c+i*m);
    l=r=1;q[1]=0;f[0]=1;
    while(l<=r){
        int xx=q[l++],x,y;
        f1(xx,x,y);f[xx]=1;
        if(x+1<n&&!vis[f2(x+1,y)]&&c[f2(x+1,y)]=='.')q[++r]=f2(x+1,y),vis[f2(x+1,y)]=1;
        if(y+1<m&&!vis[f2(x,y+1)]&&c[f2(x,y+1)]=='.')q[++r]=f2(x,y+1),vis[f2(x,y+1)]=1;
    }
    if(!f[n*m-1])puts("0"),exit(0);
    l=r=1;q[1]=n*m-1;g[n*m-1]=1;
    memset(vis,0,sizeof(vis));
    while(l<=r){
        int xx=q[l++],x,y;
        f1(xx,x,y);g[xx]=1;
        if(x-1>=0&&!vis[f2(x-1,y)]&&c[f2(x-1,y)]=='.')q[++r]=f2(x-1,y),vis[f2(x-1,y)]=1;
        if(y-1>=0&&!vis[f2(x,y-1)]&&c[f2(x,y-1)]=='.')q[++r]=f2(x,y-1),vis[f2(x,y-1)]=1;
    }
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(f[f2(i,j)]&&g[f2(i,j)])num[i+j]++;
    for(int i=1;i<n+m-2;i++)if(num[i]==1)puts("1"),exit(0);
    puts("2");
    return 0;
}