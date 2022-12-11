#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=310,Q=2e6+50;
int n,m,q,c[N][N],mx,f[N*N],id[N][N],cnt,ans[Q];bool fl[N*N];
int dx[4]={-1,0,0,1},dy[4]={0,1,-1,0};
struct node{int x,y,id;};
vector<node>a[Q],b[Q];
bool can(int x,int y){return x>=1&&x<=n&&y>=1&&y<=m&&fl[id[x][y]];}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
bool merge(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return 0;
    f[x]=y;return 1;
}
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)id[i][j]=++cnt;
    for(int i=1,x,y,z;i<=q;i++){
        scanf("%d%d%d",&x,&y,&z);mx=max(mx,z);
        if(c[x][y]==z)continue;
        a[z].pb((node){x,y,i});
        b[c[x][y]].pb((node){x,y,i});
        c[x][y]=z;
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)b[c[i][j]].pb((node){i,j,q+1});
    for(int i=1;i<=mx;i++){
        for(int j=1;j<=cnt;j++)f[j]=j,fl[j]=0;
        for(int j=0;j<a[i].size();j++){
            int x=a[i][j].x,y=a[i][j].y,Id=id[x][y];fl[Id]=1;
            for(int k=0;k<4;k++){
                int xx=x+dx[k],yy=y+dy[k];
                if(can(xx,yy)&&merge(Id,id[xx][yy]))ans[a[i][j].id]--;
            }
        }
    }
    for(int i=0;i<=mx;i++){
        for(int j=1;j<=cnt;j++)f[j]=j,fl[j]=0;
        reverse(b[i].begin(),b[i].end());
        for(int j=0;j<b[i].size();j++){
            int x=b[i][j].x,y=b[i][j].y,Id=id[x][y];fl[Id]=1;
            for(int k=0;k<4;k++){
                int xx=x+dx[k],yy=y+dy[k];
                if(can(xx,yy)&&merge(Id,id[xx][yy]))ans[b[i][j].id]++;
            }
        }
    }
    ans[0]=1;
    for(int i=1;i<=q;i++)ans[i]+=ans[i-1];
    for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
    return 0;
}