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
#define SIZE 510
#define DOWN 0
#define RIGHT 1
#define UP 2
#define LEFT 3
char an[3000010];
bool gett[SIZE][SIZE];
int an_cnt;
int a[SIZE][SIZE],n;
int row[SIZE][2],col[SIZE][2];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
char dir[6]="DRUL";
bool Out(int x,int y){return x<=0||y<=0||x>n||y>n;}
void dfs(int x,int y){
    row[x][0]=min(row[x][0],y);
    row[x][1]=max(row[x][1],y);
    col[y][0]=min(col[y][0],x);
    col[y][1]=max(col[y][1],x);
    gett[x][y]=true;
    if(!a[x][y]){
        an[an_cnt++]='1';
        a[x][y]=1;
    }
    REP(i,4){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(Out(nx,ny)||gett[nx][ny])continue;
        bool fail=false;
        switch(i){
            case LEFT:
                if(row[nx][0]>ny)fail=true;
                break;
            case DOWN:
                if(col[ny][1]<nx)fail=true;
                break;
            case RIGHT:
                if(row[nx][1]<ny)fail=true;
                break;
            case UP:
                if(col[ny][0]>nx)fail=true;
                break;
        }
        if(fail)continue;
        an[an_cnt++]=dir[i];
        dfs(nx,ny);
        an[an_cnt++]=dir[i^2];
    }
}
void move(int &now_x,int &now_y,int tx,int ty){
    while(now_x!=tx||now_y!=ty){
        if(now_x<tx){
            if(a[now_x+1][now_y]){
                an[an_cnt++]=dir[DOWN];
                now_x++;
            }
        }
        if(now_x>tx){
            if(a[now_x-1][now_y]){
                an[an_cnt++]=dir[UP];
                now_x--;
            }
        }
        if(now_y<ty){
            if(a[now_x][now_y+1]){
                an[an_cnt++]=dir[RIGHT];
                now_y++;
            }
        }
        if(now_y>ty){
            if(a[now_x][now_y-1]){
                an[an_cnt++]=dir[LEFT];
                now_y--;
            }
        }
    }
}
void clear_row(int &now_x,int &now_y){
    int rr=now_x;
    for(int i=now_y;i>row[rr][0];i--)an[an_cnt++]=dir[LEFT];
    for(int i=row[rr][0];i<now_y;i++){
        a[rr][i]=0;
        an[an_cnt++]='2';
        an[an_cnt++]=dir[RIGHT];
    }
    for(int i=now_y;i<row[rr][1];i++)an[an_cnt++]=dir[RIGHT];
    for(int i=row[rr][1];i>now_y;i--){
        a[rr][i]=0;
        an[an_cnt++]='2';
        an[an_cnt++]=dir[LEFT];
    }
    an[an_cnt++]='2';
    a[now_x][now_y]=0;
}
int main(){
    RI(n);
    REPP(i,1,n+1){
        col[i][0]=row[i][0]=n+1;
        col[i][1]=row[i][1]=0;
    }
    DRII(x0,y0);
    REPP(i,1,n+1)REPP(j,1,n+1){
        RI(a[i][j]);
        if(a[i][j]){
            row[i][0]=min(row[i][0],j);
            row[i][1]=max(row[i][1],j);
            col[j][0]=min(col[j][0],i);
            col[j][1]=max(col[j][1],i);
        }
    }
    dfs(x0,y0);
    REPP(i,1,n+1)REPP(j,1,n+1){
        if(a[i][j]&&!gett[i][j]){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    int uu=n+1,dd=0;
    REPP(i,1,n+1){
        if(row[i][0]<=n){
            uu=min(uu,i);
            dd=max(dd,i);
        }
    }
    int now_x=x0,now_y=y0;
    for(int i=uu;i<x0;i++){
        int yy=max(row[i][0],row[i+1][0]);
        move(now_x,now_y,i,yy);
        clear_row(now_x,now_y);
        move(now_x,now_y,now_x+1,now_y);
    }
    for(int i=dd;i>x0;i--){
        int yy=max(row[i][0],row[i-1][0]);
        move(now_x,now_y,i,yy);
        clear_row(now_x,now_y);
        move(now_x,now_y,now_x-1,now_y);
    }
    move(now_x,now_y,x0,y0);
    clear_row(now_x,now_y);
    an[an_cnt]=0;
    puts(an);
    return 0;
}