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
const int MOD = 1e9+7;
const int SIZE = 4010;
// template end here
LL dp[SIZE][2];
LL C[SIZE][SIZE];
void ADD(LL &x,LL v){
    x=(x+v)%MOD;
}
int main(){
    REP(i,SIZE){
        C[i][0]=1;
        REPP(j,1,i+1){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
            if(C[i][j]>=MOD)C[i][j]-=MOD;
        }
    }
    DRI(n);
    dp[0][1]=0;
    dp[0][0]=1;
    REPP(i,1,n+1){
        dp[i][0]=dp[i-1][0]*2;
        REPP(j,2,i+1){
            ADD(dp[i][0],C[i-1][j-1]*dp[i-j][0]);
        }
        dp[i][1]=(dp[i-1][0]+dp[i-1][1])%MOD;
        REPP(j,2,i+1){
            ADD(dp[i][1],C[i-1][j-1]*dp[i-j][1]);
        }
    }
    cout<<dp[n][1]<<endl;
    return 0;
}