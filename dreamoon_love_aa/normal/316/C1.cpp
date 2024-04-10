#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define pb push_back
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int r[88][88],o[88][88],n,m;
bool Out(int x,int y){return x<0||y<0||x>=n||y>=m;}
struct EDGE{
    int x,y,v,c,id;
    EDGE(int _x=0,int _y=0,int _v=0,int _c=0,int _id=0){x=_x;y=_y;v=_v;c=_c;id=_id;}
}ee[1000000];
int en,used[2000],tt,last[2000],mi[2000];
int record[2000];
vector<EDGE*>e[2000];
void add(int x,int y,int v){
    ee[en]=EDGE(x,y,v,1,en);
    e[x].pb(&ee[en]);
    e[y].pb(&ee[en]);
    en++;
}
int mp(int x,int y){return x*m+y+1;}
int flow(){
    int i,j,k;
    queue<int>qq;
    qq.push(0);
    for(i=1;i<=n*m+1;i++)mi[i]=-1000000,used[i]=0;
    mi[0]=0;
    while(qq.size()){
        int now=qq.front();
        used[now]=0;
        qq.pop();
        for(i=0;i<e[now].size();i++){
            if(now==e[now][i]->x){
                if(e[now][i]->c==1&&mi[now]+e[now][i]->v>mi[e[now][i]->y]){
                    mi[e[now][i]->y]=mi[now]+e[now][i]->v;
                    last[e[now][i]->y]=now;
                    record[e[now][i]->y]=e[now][i]->id;
                    if(!used[e[now][i]->y]){
                        used[e[now][i]->y]=1;
                        qq.push(e[now][i]->y);
                    }
                }
            }
            else{
                if(e[now][i]->c==0&&mi[now]-e[now][i]->v>mi[e[now][i]->x]){
                    mi[e[now][i]->x]=mi[now]-e[now][i]->v;
                    last[e[now][i]->x]=now;
                    record[e[now][i]->x]=e[now][i]->id;
                    if(!used[e[now][i]->x]){
                        used[e[now][i]->x]=1;
                        qq.push(e[now][i]->x);
                    }
                }
            }
        }
    }
    k=n*m+1;
    while(k){
        if(ee[record[k]].y==k)ee[record[k]].c=0;
        else ee[record[k]].c=1;
        k=last[k];
    }
    return mi[n*m+1];
}
int main(){
    int i,j,k,ha=0,res=0;
    cin>>n>>m;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)cin>>r[i][j];
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            if((i+j)&1){
                add(0,mp(i,j),0);
                for(k=0;k<4;k++){
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(Out(nx,ny))continue;
                    if(r[nx][ny]==r[i][j]){
                        add(mp(i,j),mp(nx,ny),1);
                    }
                    else{
                        add(mp(i,j),mp(nx,ny),0);
                    }
                }
            }
            else{
                add(mp(i,j),n*m+1,0);
            }
        }
    int an=0;
    for(i=0;i<n*m/2;i++)
        an+=flow();
    printf("%d\n",(n*m-an*2)/2);
    return 0;
}