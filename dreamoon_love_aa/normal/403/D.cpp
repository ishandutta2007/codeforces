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
const int SIZE = 1001;
const int MOD = 1e9+7;
int C[SIZE][SIZE],dp[45][SIZE],fac[SIZE],an[45][SIZE];
void add(int &x,int v){
    x+=v;
    if(x>=MOD)x-=MOD;
}
void init(){
    fac[0]=1;
    REPP(i,1,SIZE){
        fac[i]=(long long)fac[i-1]*i%MOD;
    }
    REP(i,SIZE){
        C[i][0]=1;
        REPP(j,1,i+1){
            C[i][j]=C[i-1][j]+C[i-1][j-1];
            if(C[i][j]>=MOD)C[i][j]-=MOD;
        }
    }
    dp[0][0]=1;
    REPP(i,1,SIZE){
        for(int k=43;k>=0;k--){
            for(int j=SIZE-1-i;j>=0;j--){
                if(dp[k][j]){
                    add(dp[k+1][j+i],dp[k][j]);
                }
            }
        }
    }
    REPP(i,1,45){
        int base=(i*(i+1))>>1;
        REPP(j,base,SIZE){
            REPP(k,base,j+1){
                add(an[i][j],(long long)dp[i][k]*fac[i]%MOD*C[j-k+i][i]%MOD);
            }
        }
    }
}
int main(){
    init();
    CASET{
        DRII(n,k);
        if(k>44)puts("0");
        else{
            printf("%d\n",an[k][n]);
        }
    }
    return 0;
}