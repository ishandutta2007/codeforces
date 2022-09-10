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
const int SIZE = 2001;
int dp[SIZE][SIZE];
int main(){
    DRII(n,K);
    REPP(i,1,n+1)dp[1][i]=1;
    REPP(i,1,K){
        for(int j=1;j<=n;j++)
            for(int k=j;k<=n;k+=j){
                dp[i+1][k]+=dp[i][j];
                if(dp[i+1][k]>=MOD)dp[i+1][k]-=MOD;
            }
    }
    int sum=0;
    REPP(i,1,n+1){
        sum+=dp[K][i];
        if(sum>=MOD)sum-=MOD;
    }
    cout<<sum<<endl;
    return 0;
}