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
#define MOD 1000000009
long long mypow(long long x,long long y){
    long long res=1;
    while(y){
        if(y&1){
            res*=x;
            res%=MOD;
        }
        x*=x;
        x%=MOD;
        y>>=1;
    }
    return res;
}
int main(){
    DRIII(n,m,k);
    int lb=n-n/k;
    if(m<=lb)printf("%d\n",m);
    else{
        long long over=m-lb;
        long long an=k*(mypow(2,over)-1)%MOD*2%MOD;
        an+=m-over*k;
        an%=MOD;
        if(an<0)an+=MOD;
        printf("%lld\n",an);
    }
    return 0;
}