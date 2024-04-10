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
const int MOD = 1e9+7;
const int SIZE = 3e3+10;
VI e[SIZE];
int dis[SIZE][SIZE];
int bfs[SIZE],dd[SIZE];
int used[SIZE],tt;
PII to[SIZE][3],from[SIZE][3];
void build(int st){
    bfs[0]=st;
    tt++;
    used[st]=tt;
    int rr=1;
    dis[st][st]=0;
    REP(i,rr){
        int x=bfs[i];
        REP(j,SZ(e[x])){
            int y=e[x][j];
            if(used[y]==tt)continue;
            used[y]=tt;
            dis[st][y]=dis[st][x]+1;
            bfs[rr++]=y;
        }
    }
}
int main(){
    MS1(dis);
    DRII(n,m);
    REP(i,m){
        DRII(x,y);
        e[x].PB(y);
    }
    REPP(i,1,n+1){
        build(i);
    }
    REPP(i,1,n+1){
        REP(j,3)to[i][j]=MP(-1,-1);
        REPP(j,1,n+1){
            if(dis[i][j]==-1||i==j)continue;
            REP(k,3){
                if(dis[i][j]>to[i][k].F){
                    for(int r=2;r>k;r--)to[i][r]=to[i][r-1];
                    to[i][k]=MP(dis[i][j],j);
                    break;
                }
            }
        }
        REP(j,3)from[i][j]=MP(-1,-1);
        REPP(j,1,n+1){
            if(dis[j][i]==-1||i==j)continue;
            REP(k,3){
                if(dis[j][i]>from[i][k].F){
                    for(int r=2;r>k;r--)from[i][r]=from[i][r-1];
                    from[i][k]=MP(dis[j][i],j);
                    break;
                }
            }
        }
    }
    int ma=0;
    PII an1,an2;
    REPP(i,1,n+1)REPP(j,1,n+1){
        if(i==j)continue;
        if(dis[i][j]==-1)continue;
        REP(k1,3)REP(k2,3){
            if(from[i][k1].F==-1||to[j][k2].F==-1)continue;
            if(to[j][k2].S==from[i][k1].S
            || to[j][k2].S==i
            || from[i][k1].S==j)continue;
            if(ma<dis[i][j]+from[i][k1].F+to[j][k2].F){
                ma=dis[i][j]+from[i][k1].F+to[j][k2].F;
                an1=MP(from[i][k1].S,i);
                an2=MP(j,to[j][k2].S);
            }
        }
    }
    printf("%d %d %d %d\n",an1.F,an1.S,an2.F,an2.S);
    return 0;
}