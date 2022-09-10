#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
#define SIZE 1024
using namespace std;
int n,m,an,used[SIZE][SIZE],cnt,yes[SIZE*SIZE],de[SIZE*SIZE];
char s[SIZE][SIZE];
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,1,-1};
vector<pair<int,int> >bfs,edge;
bool Out(int x,int y){
    return x<=0||y<=0||x>n||y>m;
}
void join(int x,int y){
    while(x!=yes[x])x=yes[x];
    while(y!=yes[y])y=yes[y];
    if(x==y)return;
    if(de[x]<de[y]){
        yes[x]=y;
    }
    else if(de[x]>de[y]){
        yes[y]=x;
    }
    else{
        yes[x]=y;
        de[y]++;
    }
}
void Go(int x,int y){
    cnt++;
    int now=cnt;
    cnt++;
    int i,j,k;
    bfs.clear();
    bfs.pb(make_pair(x,y));
    edge.clear();
    used[x][y]=now;
    for(i=0;i<bfs.size();i++){
        for(k=0;k<8;k++){
            int nnx=bfs[i].first+dx[k];
            int nny=bfs[i].second+dy[k];
            if(Out(nnx,nny)||used[nnx][nny]==cnt)continue;
            if(s[nnx][nny]=='1'){
                used[nnx][nny]=cnt;
                edge.pb(make_pair(nnx,nny));
            }
        }
        for(j=0;j<8;j++){
            int nx=bfs[i].first+dx[j];
            int ny=bfs[i].second+dy[j];
            if(Out(nx,ny)||used[nx][ny]==now||s[nx][ny]=='1')continue;
            used[nx][ny]=now;
            bfs.pb(make_pair(nx,ny));
        }
    }
    for(i=0;i<bfs.size();i++){
        for(j=0;j<8;j++){
            int nx=bfs[i].first+dx[j];
            int ny=bfs[i].second+dy[j];
            if(s[nx][ny]=='0'&&used[nx][ny]!=now)return;
        }
    }
    for(i=0;i<edge.size();i++){
        yes[(edge[i].first<<10)+edge[i].second]=(edge[i].first<<10)+edge[i].second;
        de[(edge[i].first<<10)+edge[i].second]=0;
    }
    for(i=0;i<edge.size();i++){
        int haha=0;
        int rr=(edge[i].first<<10)+edge[i].second;
        for(j=0;j<4;j++){
            int nx=edge[i].first+dx[j];
            int ny=edge[i].second+dy[j];
            if(s[nx][ny]=='1'&&used[nx][ny]==cnt){
                int ll=(nx<<10)+ny;
                join(ll,rr);
                haha++;
            }
        }
        if(haha!=2)return;
    }
    int final;
    int tt=(edge[0].first<<10)+edge[0].second;
    while(tt!=yes[tt])tt=yes[tt];
    for(i=1;i<edge.size();i++){
        int rr=(edge[i].first<<10)+edge[i].second;
        while(rr!=yes[rr])rr=yes[rr];
        if(rr!=tt)return;
    }
    an=max(an,(int)edge.size());
}
int main(){
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%s",s[i]+1);
    for(i=0;i<=n+1;i++)s[i][0]=s[i][m+1]='0';
    for(i=0;i<=m+1;i++)s[0][i]=s[n+1][i]='0';
    for(i=1;i<n&&an<4;i++)
        for(j=1;j<m&&an<4;j++){
            if(s[i][j]=='1'&&s[i+1][j+1]=='1'&&s[i][j+1]=='1'&&s[i+1][j]=='1')an=4;
        }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            if(s[i][j]=='0'&&!used[i][j]){
                Go(i,j);
            }
        }
    cout<<an<<endl;
    return 0;
}