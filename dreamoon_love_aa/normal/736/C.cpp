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
const int SIZE = 1e3+10;
void ADD(LL& x,LL v){x=(x+v)%MOD;}
LL dp[SIZE][50];
VI e[SIZE];
int K;
const int MM=25;
void f(int x,int lt){
    LL all=1;
    dp[x][MM]=1;
    bool child=0;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(y==lt)continue;
        child=1;
        f(y,x);
        LL now=0;
        REP(j,50)ADD(now,dp[y][j]);
        all=now*all%MOD;
        LL tmp2[50]={};
        REPP(j,1,25)REPP(k,1,25){
            if(!dp[y][j+MM]||!dp[x][k+MM])continue;
            ADD(tmp2[min(j,k)+MM],dp[y][j+MM]*dp[x][k+MM]);
        }
        REPP(j,1,25)REPP(k,0,25){
            if(!dp[y][j+MM]||!dp[x][-k+MM])continue;
            if(j+k<=K)ADD(tmp2[j+MM],dp[y][j+MM]*dp[x][-k+MM]);
            else ADD(tmp2[-k+MM],dp[y][j+MM]*dp[x][-k+MM]);
        }
        REPP(j,0,25)REPP(k,1,25){
            if(!dp[y][-j+MM]||!dp[x][k+MM])continue;
            if(j+k<=K)ADD(tmp2[k+MM],dp[y][-j+MM]*dp[x][k+MM]);
            else ADD(tmp2[-j+MM],dp[y][-j+MM]*dp[x][k+MM]);
        }
        REPP(j,0,25)REPP(k,0,25){
            if(!dp[y][-j+MM]||!dp[x][-k+MM])continue;
            ADD(tmp2[-max(j,k)+MM],dp[y][-j+MM]*dp[x][-k+MM]);
        }
        memcpy(dp[x],tmp2,sizeof(tmp2));
    }
    for(int j=K;j>0;j--)dp[x][-j+MM]=dp[x][-j+1+MM];
    dp[x][MM]=dp[x][K+MM];
    for(int j=K;j>1;j--)dp[x][j+MM]=dp[x][j-1+MM];
    dp[x][1+MM]=all;
}
int main(){
    DRI(n);
    RI(K);
    if(!K)return 0*puts("1");
    REPP(i,1,n){
        DRII(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    f(1,1);
    LL an=0;
    REPP(i,25,50)ADD(an,dp[1][i]);
    cout<<an<<endl;
    return 0;
}