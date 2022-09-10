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
const int MOD = 1e9+7;
int two[30];
long long dp[31][30][2],C[32][32];
void init(){
    C[0][0]=1;
    REPP(i,1,32){
        C[i][0]=1;
        REPP(j,1,i+1)C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
    }
}
void add(long long& x,long long v){
    x=(x+v)%MOD;
}
int main(){
    init();
    DRI(K);
    REP(i,30)two[i]=(K>>i)&1;
    dp[30][0][0]=1;
    for(int i=30;i>0;i--){
        for(int j=0;j<=30-i;j++){
            if(two[i-1]){        
                add(dp[i-1][j+1][1],dp[i][j][1]);
                add(dp[i-1][j+1][0],dp[i][j][0]);

                REP(k,j+1){
                    if(k&1)add(dp[i-1][j][0],dp[i][j][0]*C[j][k]);
                    else add(dp[i-1][j][1],dp[i][j][0]*C[j][k]);

                    add(dp[i-1][j][1],dp[i][j][1]*C[j][k]);
                }
            }
            else{        
                add(dp[i-1][j+1][1],dp[i][j][1]);
                REP(k,j+1){
                    if(!(k&1))add(dp[i-1][j][0],dp[i][j][0]*C[j][k]);

                    add(dp[i-1][j][1],dp[i][j][1]*C[j][k]);
                }
            }
        }
    }
    long long an=0;
    for(int i=0;i<30;i++){
        add(an,dp[0][i][0]);
        add(an,dp[0][i][1]);
    }
    cout<<an<<endl;
    return 0;
}