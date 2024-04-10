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
const double EPS=1e-9;
int main(){
    DRI(n);
    int plan=0,up=0;
    long long sum=0,base=0;
    REP(i,n*2){
        double r;
        scanf("%lf",&r);
        long long x=(int)(r*1000+EPS);
        sum+=x;
        if(x%1000==0)plan++;
        else up++;
        base+=x/1000*1000;
    }
    long long mi=1e16;
    for(int i=0;i<=plan&&i<=n;i++){
        if(n-i<=up){
            mi=min(mi,abs(base+(n-i)*1000-sum));
        }
    }
    printf("%I64d.%03I64d\n",mi/1000,mi%1000);
    return 0;
}