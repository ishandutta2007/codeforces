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
const int SIZE = 5e5+10;
const int CUT_OFF = 40;
double dp[SIZE][CUT_OFF],two[SIZE],tmp[CUT_OFF],tmp2[CUT_OFF];
int father[SIZE];
int id=2;
VI e[SIZE];
void update(int x,int from,int r){
    if(x==from){
        REP(i,CUT_OFF)dp[x][i]=1;
        REP(i,CUT_OFF)tmp[i]=dp[x][i];
    }
    else{
        REP(i,CUT_OFF)tmp2[i]=dp[x][i];
        dp[x][0]=two[SZ(e[x])];
        REPP(i,1,CUT_OFF){
            dp[x][i]=dp[x][i]*((1+dp[from][i-1])/(1+tmp[i-1]));
        }
        REP(i,CUT_OFF)tmp[i]=tmp2[i];
    }
    if(r&&x!=1)update(father[x],x,r-1);
}
int main(){
    two[0]=1;
    REPP(i,1,SIZE)two[i]=two[i-1]*0.5;
    REP(i,CUT_OFF)dp[1][i]=1;
    DRI(Q);
    while(Q--){
        DRII(ty,x);
        if(ty==1){
            int me=id++;
            father[me]=x;
            e[x].PB(me);
            update(me,me,CUT_OFF);
        }
        else{
            double an=0;
            REPP(i,1,CUT_OFF){
                an+=(dp[x][i]-dp[x][i-1])*i;
            }
            printf("%.12f\n",an);
        }
        //    REP(i,CUT_OFF)printf("%d:%f\n",i,dp[1][i]);
    }
    return 0;
}