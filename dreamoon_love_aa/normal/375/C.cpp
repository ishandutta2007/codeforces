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
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define REPC(I, C) for (int I = 0; !(C); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
int v[20][20][1<<8],cost[10],n,m;
bool used[20][20][1<<8];
char s[20][24];
bool Out(int x,int y){
    return x<0||y<0||x>=n||y>=m||s[x][y]!='.';
}
struct Point{
    int x,y,id;
    Point(int _x=0,int _y=0,int _id=0):x(_x),y(_y),id(_id){}
};
vector<Point>obj;
struct data{
    int x,y,z;
    data(int _x=0,int _y=0,int _z=0):x(_x),y(_y),z(_z){}
}bfs[1000000];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main(){
    RII(n,m);
    REP(i,n)RS(s[i]);
    int ma_id=0,sx,sy;
    REP(i,n)REP(j,m){
        if(s[i][j]>='0'&&s[i][j]<='8'){
            obj.PB(Point(i,j,s[i][j]-'0'));
            ma_id=max(ma_id,s[i][j]-'0');
        }
        else if(s[i][j]=='B')obj.PB(Point(i,j,-1));
        else if(s[i][j]=='S'){sx=i;sy=j;s[i][j]='.';}
    }
    REPP(i,1,ma_id+1)RI(cost[i]);
    bfs[0]=data(sx,sy,0);
    used[sx][sy][0]=true;
    for(int i=0,j=1;i<j;i++){
        for(int k=0;k<4;k++){
            int nx=bfs[i].x+dx[k];
            int ny=bfs[i].y+dy[k];
            int nz=bfs[i].z;
            if(Out(nx,ny))continue;
            if(k==0){
                for(int r=0;r<SZ(obj);r++){
                    if(obj[r].x==nx&&obj[r].y<ny)nz^=1<<r;
                }
            }
            else if(k==2){
                for(int r=0;r<SZ(obj);r++){
                    if(obj[r].x==bfs[i].x&&obj[r].y<ny)nz^=1<<r;
                }
            }
            if(used[nx][ny][nz])continue;
            used[nx][ny][nz]=true;
            v[nx][ny][nz]=v[bfs[i].x][bfs[i].y][bfs[i].z]+1;
            bfs[j++]=data(nx,ny,nz);
        }
    }
    int an=0;
    REP(i,(1<<SZ(obj))){
        if(!used[sx][sy][i])continue;
        bool err=false;
        int tmp=0;
        for(int j=0;j<SZ(obj);j++){
            if((i>>j)&1){
                if(obj[j].id==-1){
                    err=true;
                    break;
                }
                else tmp+=cost[obj[j].id];
            }
        }
        if(!err)an=max(an,tmp-v[sx][sy][i]);
    }
    printf("%d\n",an);
    return 0;
}