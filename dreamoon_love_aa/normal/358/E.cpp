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
#define SIZE 2003
int n,m,a[SIZE][SIZE],pn,lux,luy,d[SIZE][SIZE];
struct Point{
    int x,y;
    Point(int _x=0,int _y=0):x(_x),y(_y){}
}p[SIZE*SIZE];
int cs,used[SIZE*SIZE];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
vector<int>e[SIZE];
int get(int x1,int y1,int x2,int y2){
    if(x1<=0||y1<=0||x2>n||y2>m)return -1;
    return d[x2][y2]+d[x1-1][y1-1]-d[x1-1][y2]-d[x2][y1-1];
}
int tran(int x,int y){return x*(m+1)+y;}
int bfs[SIZE*SIZE];
bool Out(int x,int y){return x<=0||y<=0||x>n||y>m;}
bool check(int k){
    int one=0;
    for(int i=0;i<(n+1)*(m+1);i++)e[i].clear();
    cs++;
    for(int i=0;i<pn;i++){
        if((p[i].x-lux)%k&&(p[i].y-luy)%k){
            return false;
        }
        else if((p[i].x-lux)%k==0&&(p[i].y-luy)%k==0){
            used[tran(p[i].x,p[i].y)]=cs;
            int r,cnt=0;
            for(r=0;r<4;r++){
                if(!Out(p[i].x+dx[r]*k,p[i].y+dy[r]*k)&&a[p[i].x+dx[r]][p[i].y+dy[r]]){
                    cnt++;
                    if(get(min(p[i].x,p[i].x+dx[r]*k),min(p[i].y,p[i].y+dy[r]*k),max(p[i].x,p[i].x+dx[r]*k),max(p[i].y,p[i].y+dy[r]*k))!=k+1)return false;
                    else e[tran(p[i].x,p[i].y)].PB(tran(p[i].x+dx[r]*k,p[i].y+dy[r]*k));
                }
            }
            if(cnt==0){
                return false;
            }
            if(cnt%2==1)one++;
        }
        else if((p[i].x-lux)%k==0){
            if(Out(p[i].x,luy+(p[i].y-luy)/k*k)||!a[p[i].x][luy+(p[i].y-luy)/k*k]
             ||Out(p[i].x,luy+((p[i].y-luy)/k+1)*k)||!a[p[i].x][luy+((p[i].y-luy)/k+1)*k]){
                return false;
            }
        }
        else{
            if(Out(lux+(p[i].x-lux)/k*k,p[i].y)||!a[lux+(p[i].x-lux)/k*k][p[i].y]
             ||Out(lux+((p[i].x-lux)/k+1)*k,p[i].y)||!a[lux+((p[i].x-lux)/k+1)*k][p[i].y]){
                return false;
            }
        }
    }
    if(one&&one!=2)return false;
    int st;
    for(st=0;used[st]!=cs;st++);
    bfs[0]=st;
    used[st]=0;
    for(int i=0,j=1;i<j;i++){
        for(k=0;k<SZ(e[bfs[i]]);k++){
            int y=e[bfs[i]][k];
            if(used[y]==cs){
                bfs[j++]=y;
                used[y]=0;
            }
        }
    }
    for(st=0;st<(n+1)*(m+1)&&used[st]!=cs;st++);
    if(st<(n+1)*(m+1))return false;
    return true;
}
int main(){
    scanf("%d%d",&n,&m);
    lux=-1,luy=-1;
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]){
                p[pn++]=Point(i,j);
                cnt++;
                if(lux==-1){
                    lux=i;
                    luy=j;
                }
            }
        }
    }
    if(cnt==1)puts("-1");
    else{
        int xx=lux,yy=luy;
        int len=0;
        if(a[lux][luy+1]==1){
            for(len=1;a[lux][luy+len]==1;len++);
        }
        else{
            for(len=1;a[lux+len][luy]==1;len++);
        }
        len--;
        if(len<=1){
            puts("-1");
        }
        else{
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)d[i][j]=a[i][j]+d[i][j-1];
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)d[i][j]+=d[i-1][j];
            for(int k=len;k>1;k--){
                lux=xx%k,luy=yy%k;
                if(len%k==0&&check(k)){
                    bool first=true;
                    for(int i=2;i<=k;i++){
                        if(k%i==0){
                            if(!first)printf(" ");
                            else first=false;
                            printf("%d",i);
                        }
                    }
                    puts("");
                    return 0;
                }
            }
            puts("-1");
        }
    }
    return 0;
}