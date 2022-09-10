#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
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
#define PII pair<int,int>
#define VI vector<int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int SIZE = 1e3+10;
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
char s[1111][1111];
int sX,sY,eX,eY;
PII bfs[SIZE*SIZE*4];
int dir[SIZE*SIZE*4],v[SIZE*SIZE*4];
bool used[SIZE][SIZE][4];
int n,m;
bool Out(int x,int y){return x<0||y<0||x>=n||y>=m;}
bool cc(int x,int v){return (x>>v)&1;}
int main(){
    RII(n,m);
    REP(i,n)RS(s[i]);
    RII(sX,sY);
    RII(eX,eY);
    sX--;sY--;eX--;eY--;
    REP(i,n)REP(j,m){
        if(s[i][j]=='+')s[i][j]=15;
        if(s[i][j]=='-')s[i][j]=10;
        if(s[i][j]=='|')s[i][j]=5;
        if(s[i][j]=='^')s[i][j]=4;
        if(s[i][j]=='>')s[i][j]=8;
        if(s[i][j]=='<')s[i][j]=2;
        if(s[i][j]=='v')s[i][j]=1;
        if(s[i][j]=='L')s[i][j]=13;
        if(s[i][j]=='R')s[i][j]=7;
        if(s[i][j]=='U')s[i][j]=11;
        if(s[i][j]=='D')s[i][j]=14;
        if(s[i][j]=='*')s[i][j]=0;
    }
    used[sX][sY][0]=1;
    bfs[0]=MP(sX,sY);
    dir[0]=0;
    int rr=1;
    REP(i,rr){
        if(bfs[i]==MP(eX,eY))return 0*printf("%d\n",v[i]);
        int x=bfs[i].F;
        int y=bfs[i].S;
        int dd=dir[i];
        if(!used[x][y][(dd+1)&3]){
            used[x][y][(dd+1)&3]=1;
            bfs[rr]=MP(x,y);
            v[rr]=v[i]+1;
            dir[rr++]=(dd+1)&3;
        }
        REP(j,4){
            int nx=x+dx[j];
            int ny=y+dy[j];
            if(Out(nx,ny))continue;
            if(used[nx][ny][dd])continue;
            int me=(s[x][y]<<dd)|(s[x][y]>>(4-dd));
            int you=(s[nx][ny]<<dd)|(s[nx][ny]>>(4-dd));
            if(!j){
                if(!cc(me,0)||!cc(you,2))continue;
            }
            else if(j==1){
                if(!cc(me,1)||!cc(you,3))continue;
            }
            else if(j==2){
                if(!cc(me,2)||!cc(you,0))continue;
            }
            else if(j==3){
                if(!cc(me,3)||!cc(you,1))continue;
            }
            used[nx][ny][dd]=1;
            bfs[rr]=MP(nx,ny);
            v[rr]=v[i]+1;
            dir[rr++]=dd;
        }
    }
    puts("-1");
    return 0;
}