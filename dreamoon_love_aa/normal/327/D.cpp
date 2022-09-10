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
#define MS0(X) memset((X), 0, sizeof((X))
#define MS1(X) memset((X), -1, sizeof((X))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
struct OP{
    int ty,x,y;
    OP(int _ty=0,int _x=0,int _y=0){ty=_ty;x=_x;y=_y;}
};
vector<OP>op;
#define SIZE 511
bool used[SIZE][SIZE];
char s[SIZE][SIZE];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1},n,m;
bool Out(int x,int y){return x<0||y<0||x>=n||y>=m;}
void go(int x,int y,bool first){
    used[x][y]=1;
    int i;
    op.PB(OP(0,x,y));
    for(i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(Out(nx,ny)||used[nx][ny]||s[nx][ny]=='#')continue;
        go(nx,ny,0);
    }
    if(!first){
        op.PB(OP(1,x,y));
        op.PB(OP(2,x,y));
    }
}
int main(){
    int i,j,k;
    RII(n,m);
    for(i=0;i<n;i++)scanf("%s",s[i]);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            if(used[i][j]||s[i][j]=='#')continue;
            go(i,j,1);
        }
    printf("%d\n",SZ(op));
    for(i=0;i<op.size();i++){
        if(op[i].ty==0)printf("B %d %d\n",op[i].x+1,op[i].y+1);
        else if(op[i].ty==1)printf("D %d %d\n",op[i].x+1,op[i].y+1);
        else printf("R %d %d\n",op[i].x+1,op[i].y+1);
    }
    return 0;
}