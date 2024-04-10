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
const int SIZE = 1e5+5;
int a[SIZE],dp[2][SIZE];
int main(){
    DRI(N);
    REPP(i,1,N+1)RI(a[i]);
    dp[0][1]=1;
    REPP(i,2,N+1){
        if(a[i]>a[i-1])dp[0][i]=dp[0][i-1]+1;
        else dp[0][i]=1;
    }
    dp[1][N]=1;
    for(int i=N-1;i>0;i--){
        if(a[i]<a[i+1])dp[1][i]=dp[1][i+1]+1;
        else dp[1][i]=1;
    }
    if(N==1){
        puts("1");
    }
    else{
        int an=max(dp[1][2]+1,dp[0][N-1]+1);
        REPP(i,2,N){
            if(a[i+1]-1>a[i-1])an=max(an,dp[0][i-1]+dp[1][i+1]+1);
            an=max(an,dp[0][i-1]+1);
            an=max(an,dp[1][i+1]+1);
        }
        printf("%d\n",an);
    }
    return 0;
}