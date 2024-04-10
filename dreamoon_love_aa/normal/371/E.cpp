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
const int SIZE = 300010;
pair<long long,int>st[SIZE];
long long dp[SIZE];
int main(){
    DRI(n);
    REP(i,n){
        DRI(x);
        st[i]=MP(x,i+1);
    }
    DRI(K);
    sort(st,st+n);
    dp[0]=st[0].F;
    REPP(i,1,n)dp[i]=dp[i-1]+st[i].F;
    long double now=0,ma=(long long)1e30;
    int id;
    REP(i,K){
        now+=(K-1-i)*(-st[i].F)+i*st[i].F;
    }
    if(now<ma){
        ma=now;
        id=0;
    }
    REPP(i,K,n){
        now+=st[i].F*(K-1)+st[i-K].F*(K-1);
        now-=(dp[i-1]-dp[i-K])*2;
        if(now<ma){
            ma=now;
            id=i-K+1;
        }
    }
    REP(i,K){
        if(i)printf(" ");
        printf("%d",st[i+id].S);
    }
    puts("");
    return 0;
}