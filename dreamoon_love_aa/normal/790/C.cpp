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
const int INF = 1e9;
const int SIZE = 80;
char s[SIZE];
VI d[3];
int dp[SIZE][SIZE][SIZE][2];
template <class T>
void mii(T& x,T y){
    if(x==-1||x>y)x=y;
}
int get(int x,int y,int z,int id){
    int st[3]={x,y,z};
    if(st[id]>=SZ(d[id]))return INF;
    int ret=0;
    REP(i,3){
        if(id==i)continue;
        REPP(j,st[i],SZ(d[i])){
            if(d[i][j]<d[id][st[id]])ret++;
            else break;
        }
    }
    return ret;
}
int main(){
    DRI(n);
    RS(s+1);
    REPP(i,1,n+1){
        if(s[i]=='V')d[0].PB(i);
        else if(s[i]=='K')d[1].PB(i);
        else d[2].PB(i);
    }
    REP(i,SIZE)REP(j,SIZE)REP(k,SIZE)REP(r,2)dp[i][j][k][r]=INF;
    dp[0][0][0][0]=0;
    REPP(i,1,n+1){
        REP(j,i)REP(k,i){
            if(dp[i-1][j][k][0]<INF){
                mii(dp[i][j+1][k][1],dp[i-1][j][k][0]+get(j,k,i-1-j-k,0));
                mii(dp[i][j][k+1][0],dp[i-1][j][k][0]+get(j,k,i-1-j-k,1));
                mii(dp[i][j][k][0],dp[i-1][j][k][0]+get(j,k,i-1-j-k,2));
            }
            if(dp[i-1][j][k][1]<INF){
                mii(dp[i][j+1][k][1],dp[i-1][j][k][1]+get(j,k,i-1-j-k,0));
                mii(dp[i][j][k][0],dp[i-1][j][k][1]+get(j,k,i-1-j-k,2));
            }
        }
        /*REP(j,i+1)REP(k,i+1){
            if(dp[i][j][k][0]<INF)printf("dp[%d][%d][%d][%d]=%d\n",i,j,k,0,dp[i][j][k][0]);
            if(dp[i][j][k][1]<INF)printf("dp[%d][%d][%d][%d]=%d\n",i,j,k,1,dp[i][j][k][1]);
        }*/
    }
    int an=dp[n][SZ(d[0])][SZ(d[1])][0];
    mii(an,dp[n][SZ(d[0])][SZ(d[1])][1]);
    printf("%d\n",an);
    return 0;
}