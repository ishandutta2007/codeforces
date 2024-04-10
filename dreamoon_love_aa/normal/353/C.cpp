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
#define SIZE 100010
int a[SIZE],dp[SIZE][2];
char s[SIZE];
int main(){
    DRI(n);
    REP(i,n)RI(a[i]);
    RS(s);
    MS1(dp);
    dp[n][1]=0;
    for(int i=n-1;i>=0;i--){
        dp[i][1]=dp[i+1][1]+a[i]*(s[i]=='1');
        if(s[i]=='1')dp[i][0]=dp[i+1][1];
        dp[i][0]=max(dp[i][0],dp[i+1][0]);
        if(dp[i+1][0]!=-1)dp[i][0]=max(dp[i][0],dp[i+1][0]+a[i]);
    }
    printf("%d\n",max(dp[0][0],dp[0][1]));
    return 0;
}