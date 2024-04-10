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
#define F first
#define S second
typedef long long LL;
using namespace std;
const LL INF = 1e18;
LL dp[5001][5001];
int p[5001];
int main(){
    DRIII(n,m,k);
    REP(i,n){
        RI(p[i+1]);
    }
    int r=n-m*k;
    LL sum=0;
    REPP(i,1,r+1)dp[0][i]=INF;
    REPP(i,1,n+1){
        sum+=p[i];
        REP(j,r+1){
            dp[i][j]=INF;
            if(i>=m)dp[i][j]=min(dp[i][j],dp[i-m][j]);
            if(j)dp[i][j]=min(dp[i][j],dp[i-1][j-1]+p[i]);
        }
    }
    cout<<sum-dp[n][r]<<endl;
    return 0;
}