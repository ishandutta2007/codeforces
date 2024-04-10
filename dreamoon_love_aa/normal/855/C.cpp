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
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e5+10;
LL dp[SIZE][11][3];
int n,m,K,X;
VI e[SIZE];
void ADD(LL& x,LL v){
    x=(x+v)%MOD;
}
void dfs(int x,int lt){
    LL tmp[2][11][3]={};
    REP(j,3)tmp[0][0][j]=1;
    int now=0,nxt=1;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(y==lt)continue;
        dfs(y,x);
        MS0(tmp[nxt]);
        for(int j=X;j>=0;j--){
            for(int k=X-j;k>=0;k--){
                ADD(tmp[nxt][j+k][0],tmp[now][j][0]*dp[y][k][0]);
                ADD(tmp[nxt][j+k][0],tmp[now][j][0]*dp[y][k][1]);
                ADD(tmp[nxt][j+k][0],tmp[now][j][0]*dp[y][k][2]);

                ADD(tmp[nxt][j+k][1],tmp[now][j][1]*dp[y][k][0]);

                ADD(tmp[nxt][j+k][2],tmp[now][j][2]*dp[y][k][0]);
                ADD(tmp[nxt][j+k][2],tmp[now][j][2]*dp[y][k][2]);
            }
        }
        swap(now,nxt);
    }
    REP(i,X+1){
        ADD(dp[x][i][0],tmp[now][i][0]*(K-1));
        ADD(dp[x][i][2],tmp[now][i][2]*(m-K));
    }
    REP(i,X)ADD(dp[x][i+1][1],tmp[now][i][1]);
}
int main(){
    RII(n,m);
    REPP(i,1,n){
        DRII(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    RII(K,X);
    dfs(1,1);
    LL an=0;
    REP(i,X+1)REP(j,3)ADD(an,dp[1][i][j]);
    //REPP(i,1,n+1)REP(j,X+1)REP(k,3)printf("dp[%d][%d][%d]=%I64d\n",i,j,k,dp[i][j][k]);
    printf("%I64d\n",an);
    return 0;
}