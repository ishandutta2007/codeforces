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
int x[1111];
int main(){
    DRI(n);
    REP(i,n)RI(x[i]);
    bool err=false;
    REPP(i,1,n)REPP(j,i+1,n){
        int mi1=min(x[i],x[i-1]);
        int mi2=min(x[j],x[j-1]);
        int ma1=max(x[i],x[i-1]);
        int ma2=max(x[j],x[j-1]);
        if(mi1>=mi2&&ma1<=ma2)continue;
        if(mi2>=mi1&&ma2<=ma1)continue;
        if(ma1<=mi2)continue;
        if(ma2<=mi1)continue;
        err=true;
    }
    if(err)puts("yes");
    else puts("no");
    return 0;
}