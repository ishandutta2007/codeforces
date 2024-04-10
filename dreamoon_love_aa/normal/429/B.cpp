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
const int SIZE =1010;
int dp[4][SIZE][SIZE],a[SIZE][SIZE];
int main(){
    DRII(n,m);
    REPP(i,1,n+1)REPP(j,1,m+1)RI(a[i][j]);
    REPP(i,1,n+1)REPP(j,1,m+1){
        dp[0][i][j]=max(dp[0][i-1][j],dp[0][i][j-1])+a[i][j];
    }
    for(int i=n;i>=1;i--)REPP(j,1,m+1){
        dp[1][i][j]=max(dp[1][i+1][j],dp[1][i][j-1])+a[i][j];
    }
    REPP(i,1,n+1)for(int j=m;j>=1;j--){
        dp[2][i][j]=max(dp[2][i-1][j],dp[2][i][j+1])+a[i][j];
    }
    for(int i=n;i>=1;i--)for(int j=m;j>=1;j--){
        dp[3][i][j]=max(dp[3][i+1][j],dp[3][i][j+1])+a[i][j];
    }
    int an=0;
    REPP(i,2,n)REPP(j,2,m){
        an=max(an,dp[0][i-1][j]+dp[3][i+1][j]+dp[1][i][j-1]+dp[2][i][j+1]);
        an=max(an,dp[0][i][j-1]+dp[3][i][j+1]+dp[1][i+1][j]+dp[2][i-1][j]);
    }
    printf("%d\n",an);
    return 0;
}