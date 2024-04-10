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
const int SIZE = 210000;
const int MM = 105000;
const int INF = (int)1e9;
int dp[SIZE],a[SIZE],b[SIZE];
int main(){
    DRII(n,k);
    REP(i,SIZE)dp[i]=-INF;
    dp[MM]=0;
    REP(i,n)RI(a[i]);
    REP(i,n)RI(b[i]);
    REP(i,n){
        int c=a[i]-b[i]*k;
        if(c>=0){
            for(int j=SIZE-1-c;j>=0;j--){
                dp[j+c]=max(dp[j+c],dp[j]+b[i]);
            }
        }
        else{
            for(int j=-c;j<SIZE;j++){
                dp[j+c]=max(dp[j+c],dp[j]+b[i]);
            }
        }
    }
    if(dp[MM]==0)puts("-1");
    else printf("%d\n",dp[MM]*k);
    return 0;
}