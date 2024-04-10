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
#define pb push_back
using namespace std;
#define SIZE 1555
struct Point{
    int x,y;
    Point(int _x=0,int _y=0){x=_x,y=_y;}
    bool operator==(const Point& b)const{return x==b.x&&y==b.y;}
}bfs[SIZE*SIZE],p[SIZE][SIZE];
char s[SIZE][SIZE];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int used[SIZE][SIZE];
int n,m;
void fix(int &x,int nn){
    if(x<0)x+=nn;
    if(x>=nn)x-=nn;
}
bool go(int x,int y){
    bfs[0]=Point(x,y);
    used[x][y]=1;
    p[x][y]=Point(0,0);
    int i,j,k;
    for(i=0,j=1;i<j;i++){
        //printf("(%d,%d)\n",bfs[i].x,bfs[i].y);
        for(k=0;k<4;k++){
            int nx=bfs[i].x+dx[k];
            int ny=bfs[i].y+dy[k];
            fix(nx,n);
            fix(ny,m);
            if(s[nx][ny]=='#')continue;
            if(used[nx][ny]){
                if(nx==bfs[i].x+dx[k]&&ny==bfs[i].y+dy[k]){
                    Point next=p[bfs[i].x][bfs[i].y];
                    if(!(next==p[nx][ny]))return 1;
                }
                else{
                    Point next=Point(p[bfs[i].x][bfs[i].y].x+dx[k],p[bfs[i].x][bfs[i].y].y+dy[k]);
                    if(!(next==p[nx][ny]))return 1;
                }
            }
            else{
                used[nx][ny]=1;
                if(nx==bfs[i].x+dx[k]&&ny==bfs[i].y+dy[k]){
                    p[nx][ny]=p[bfs[i].x][bfs[i].y];
                }
                else{
                    p[nx][ny]=Point(p[bfs[i].x][bfs[i].y].x+dx[k],p[bfs[i].x][bfs[i].y].y+dy[k]);
                }
                bfs[j++]=Point(nx,ny);
            }
        }
    }
    return 0;
}
int main(){
    int i,j,k;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%s",s[i]);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            if(s[i][j]=='S'){
                if(go(i,j))puts("Yes");
                else puts("No");
                return 0;
            }
        }
    return 0;
}