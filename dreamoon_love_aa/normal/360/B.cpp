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
const int SIZE = 2222;
int a[SIZE],dp[SIZE];
int f(int x,int y,int n){
    if(x>y)swap(x,y);
    return (y-x+n-1)/n;
}
bool valid(int v,int N,int K){
    dp[1]=0;
    for(int i=2;i<=N;i++){
        dp[i]=i-1;
        for(int j=1;j<i;j++){
            if(f(a[j],a[i],i-j)<=v)dp[i]=min(dp[i],dp[j]+i-j-1);
        }
        if(dp[i]+N-i<=K)return true;
    }
    return false;
}
int main(){
    DRII(N,K);
    REPP(i,1,N+1)RI(a[i]);
    if(K+1>=N){
        puts("0");
        return 0;
    }
    int ll=0,rr=2000000000;
    while(ll<rr){
        int mm=ll+(rr-ll)/2;
        if(valid(mm,N,K))rr=mm;
        else ll=mm+1;
    }
    printf("%d\n",ll);
    return 0;
}