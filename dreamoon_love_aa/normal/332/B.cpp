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
#define SIZE 1000000
long long dp[SIZE];
int main(){
    int ll,rr;
    DRII(n,k);
    REPP(i,1,n+1){cin>>dp[i];dp[i]+=dp[i-1];}
    long long ma=0,No,an=0;
    REPP(i,k*2,n+1){
        if(dp[i-k]-dp[i-2*k]>ma){
            ma=dp[i-k]-dp[i-2*k];
            No=i-2*k+1;
        }
        if(dp[i]-dp[i-k]+ma>an){
            an=dp[i]-dp[i-k]+ma;
            ll=No;rr=i-k+1;
        }
    }
    printf("%d %d\n",ll,rr);
    return 0;
}