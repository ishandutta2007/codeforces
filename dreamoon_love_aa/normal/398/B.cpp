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
const int SIZE = 2010;
long double dp[SIZE][SIZE];
int used[2][SIZE],r[2];
int main(){
    DRII(n,m);
    REP(i,m){
        DRII(x,y);
        used[0][x]=1;
        used[1][y]=1;
    }
    REPP(i,1,n+1)
        if(!used[0][i])r[0]++;

    REPP(i,1,n+1)
        if(!used[1][i])r[1]++;

    REP(i,r[0]+1)
        REP(j,r[1]+1){
            if(!i&&!j)dp[i][j]=0;
            else if(!i){
                dp[i][j]=1.*n/j+dp[i][j-1];
            }
            else if(!j){
                dp[i][j]=1.*n/i+dp[i-1][j];
            }
            else{
                dp[i][j]=(n*n+i*j*dp[i-1][j-1]+(n-i)*j*dp[i][j-1]+i*(n-j)*dp[i-1][j])/(n*j+n*i-i*j);
            }
        }
    printf("%.12f\n",(double)dp[r[0]][r[1]]);
    return 0;
}