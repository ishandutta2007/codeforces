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
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define F first
#define S second
typedef long long LL;
using namespace std;
const int SIZE = 2e3+10;
char s[SIZE][SIZE];
int deg[SIZE][SIZE];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
char fl[2][8]={"^<v>","v>^<"};
pair<int,int>bfs[SIZE*SIZE];
int main(){
    int ll=0,rr=0;
    DRII(n,m);
    REP(i,n)RS(s[i+1]+1);
    int sp=0;
    REPP(i,1,n+1)REPP(j,1,m+1){
        REP(k,4){
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(s[nx][ny]=='.')deg[i][j]++;
        }
        if(s[i][j]=='.'){
            sp++;
            if(deg[i][j]==1)bfs[rr++]=MP(i,j);
        }
    }
    while(ll<rr){
        int x=bfs[ll].F;
        int y=bfs[ll].S;
        if(s[x][y]=='.'){
            int nx,ny;
            int id=-1;
            bool suc=0;
            REP(k,4){
                nx=x+dx[k];
                ny=y+dy[k];
                id=k;
                if(s[nx][ny]=='.'){
                    suc=1;
                    break;
                }
            }
            if(!suc){
                puts("Not unique");
                return 0;
            }
            s[x][y]=fl[0][id];
            s[nx][ny]=fl[1][id];
            deg[x][y]=0;
            deg[nx][ny]=0;
            REP(k,4){
                int nnx=nx+dx[k];
                int nny=ny+dy[k];
                deg[nnx][nny]--;
                if(deg[nnx][nny]==1)bfs[rr++]=MP(nnx,nny);
            }
        }
        ll++;
    }
    REP(i,n)REP(j,m)if(s[i+1][j+1]=='.'){
        puts("Not unique");
        return 0;
    }
    REP(i,n)puts(s[i+1]+1);
    return 0;
}