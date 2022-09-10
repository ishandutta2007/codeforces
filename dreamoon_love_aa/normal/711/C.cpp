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
const LL INF = 1e18+7;
const int SIZE = 110;
PLL dp[SIZE][SIZE][2];
LL dp0[SIZE][SIZE][SIZE];
int p[SIZE][SIZE],c[SIZE];
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
int main(){
    DRIII(n,m,K);
    REP(i,n)RI(c[i+1]);
    REP(i,n)REP(j,m)RI(p[i+1][j+1]);
    REP(i,SIZE)REP(j,SIZE)dp[i][j][0]=dp[i][j][1]=MP(INF,0);
    REP(i,SIZE)REP(j,SIZE)REP(k,SIZE)dp0[i][j][k]=INF;
    dp0[0][0][0]=0;
    dp[0][0][0]=MP(0,0);
    REPP(i,1,n+1){
        REPP(j,1,m+1){
            if(c[i]==j||c[i]==0){
                REP(k,K+1){
                    mii(dp0[i][j][k],dp0[i-1][j][k]+(!c[i]?p[i][j]:0));
                    if(k){
                        REP(r,2){
                            if(dp[i-1][k-1][r].S!=j){
                                mii(dp0[i][j][k],dp[i-1][k-1][r].F+(!c[i]?p[i][j]:0));
                            }
                        }
                    }
                    if(dp0[i][j][k]<dp[i][k][0].F){
                        dp[i][k][1]=dp[i][k][0];
                        dp[i][k][0]=MP(dp0[i][j][k],j);
                    }
                    else if(dp0[i][j][k]<dp[i][k][1].F){
                        dp[i][k][1]=MP(dp0[i][j][k],j);
                    }
                }
            }
        }
    }
    if(dp[n][K][0].F<INF)cout<<dp[n][K][0].F<<endl;
    else puts("-1");
    return 0;
}