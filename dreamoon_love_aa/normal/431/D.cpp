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
long long dp[62][64][2];
long long cal(long long x,int k){
    MS0(dp);
    dp[61][0][1]=1;
    for(int i=60;i>=0;i--){
        for(int j=0;j<=62;j++){
            dp[i][j][0]+=dp[i+1][j][0];
            dp[i][j+1][0]+=dp[i+1][j][0];
            if((x>>i)&1){
                dp[i][j][0]+=dp[i+1][j][1];
                dp[i][j+1][1]+=dp[i+1][j][1];
            }
            else{
                dp[i][j][1]+=dp[i+1][j][1];
            }
        }
    }
    return dp[0][k][0]+dp[0][k][1];
}
int main(){
    long long m;
    int k;
    cin>>m>>k;
    if(m==0){
        puts("1");
        return 0;
    }
    long long ll=1,rr=1000000000000000000LL;
    while(ll<rr){
        long long mm=(ll+rr)>>1;
        long long v=cal(2*mm,k)-cal(mm,k);
        if(v>=m)rr=mm;
        else ll=mm+1;
    }
    cout<<ll<<endl;
    return 0;
}