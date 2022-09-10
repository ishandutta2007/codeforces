#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define REPC(I, C) for (int I = 0; !(C); ++I)
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
using namespace std;
int t[3][3];
long long dp[42][3][3];
int main(){
    REP(i,3)REP(j,3){
        RI(t[i][j]);
        dp[1][i][j]=t[i][j];
    }
    REP(i,3)REP(j,3){
        if(i==j)continue;
        int ot=3-i-j;
        dp[1][i][j]=min(dp[1][i][j],(long long)t[i][ot]+t[ot][j]);
    }
    DRI(n);
    REPP(i,2,n+1){
        REP(i2,3)
            REP(j2,3){
                if(i2==j2)continue;
                int ot=3-i2-j2;
                dp[i][i2][j2]=dp[i-1][i2][ot]+t[i2][j2]+dp[i-1][ot][j2];
                dp[i][i2][j2]=min(dp[i][i2][j2],dp[i-1][i2][j2]*2+t[i2][ot]+dp[i-1][j2][i2]+t[ot][j2]);
            }
    }
    cout<<dp[n][0][2]<<endl;
    return 0;
}