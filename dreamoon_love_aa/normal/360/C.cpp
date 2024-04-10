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
#define SIZE 2222
const int MOD = (int)1e9 + 7;
char s[SIZE];
int dp[SIZE][SIZE],ha[SIZE],ha2[SIZE][SIZE];
int main(){
    DRII(N,K);
    RS(s);
    dp[N][0]=1;
    for(int i=N-1;i>=0;i--){
        int id=s[i]-'a';
        for(int j=K-(N-i);j>=0;j--){
            dp[i][j+(N-i)]+=(long long)dp[i+1][j]*(25-id)%MOD;
            if(dp[i][j+(N-i)]>=MOD)dp[i][j+(N-i)]-=MOD;
            ha2[i][j+(N-i)]+=(long long)dp[i+1][j]*(25-id)%MOD;
            if(ha2[i][j+(N-i)]>=MOD)ha2[i][j+(N-i)]-=MOD;
        }
        for(int j=K;j>=0;j--){
            dp[i][j]+=(long long)dp[i+1][j]*id%MOD;
            if(dp[i][j]>=MOD)dp[i][j]-=MOD;
            dp[i][j]+=ha[j];
            if(dp[i][j]>=MOD)dp[i][j]-=MOD;
        }
        for(int j=K;j>=0;j--){
            ha[j]+=(long long)dp[i+1][j]*id%MOD;
            if(ha[j]>=MOD)ha[j]-=MOD;
        }
        for(int j=1;i+j<N;j++){
            for(int k=K-(N-i-j)*j;k>=0;k--){
                dp[i][k+(N-i-j)*j]+=ha2[i+j][k];
                if(dp[i][k+(N-i-j)*j]>=MOD)dp[i][k+(N-i-j)*j]-=MOD;
            }
        }
        dp[i][0]++;
    }
    printf("%d\n",dp[0][K]);
    return 0;
}