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
char s[45][45];
int dp[42][42],dp2[42][42][42][42],an[42][42][42][42];
int get(int x1,int y1,int x2,int y2){x1--;y1--;return dp[x2][y2]+dp[x1][y1]-dp[x1][y2]-dp[x2][y1];}
int main(){
    DRIII(N,M,Q);
    REP(i,N)RS(s[i+1]+1);
    REPP(i,1,N+1)
        REPP(j,1,M+1){
            dp[i][j]=dp[i][j-1]+s[i][j]-'0';
        }
    REPP(i,1,N+1)
        REPP(j,1,M+1){
            dp[i][j]+=dp[i-1][j];
        }
    REPP(h,1,N+1)
        REPP(w,1,M+1){
            REPP(k1,h,N+1){
                int i=k1-h+1,i2=k1;
                REPP(k2,w,M+1){
                    int j=k2-w+1,j2=k2;
                    an[i][j][i2][j2]=an[i][j][i2][j2-1]+an[i][j][i2-1][j2]+an[i+1][j][i2][j2]+an[i][j+1][i2][j2]
                                    -an[i+1][j][i2-1][j2]-an[i][j+1][i2][j2-1]-an[i+1][j+1][i2][j2]-an[i+1][j][i2][j2-1]-an[i][j+1][i2-1][j2]-an[i][j][i2-1][j2-1]
                                    +an[i][j+1][i2-1][j2-1]+an[i+1][j][i2-1][j2-1]+an[i+1][j+1][i2][j2-1]+an[i+1][j+1][i2-1][j2]
                                    -an[i+1][j+1][i2-1][j2-1]+(get(i,j,i2,j2)==0);
                }
            }

        }
    REP(i,Q){
        DRII(x1,y1);
        DRII(x2,y2);
        printf("%d\n",an[x1][y1][x2][y2]);
    }
    return 0;
}