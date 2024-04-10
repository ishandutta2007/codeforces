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
    int an=1;
    DRII(r,h);
    for(int i=1;;i++){
        if(i*r-0.5*r<h+EPS)an=max(an,i*2);
        else break;
        if(i*r+sqrt(3)*0.5*r<h+r)an=max(an,i*2+1);
        /*
        double tmp=(h-(i*r-0.5*r)+EPS)/((sqrt(3)-1)*r);
        int more=(int)(floor(tmp)+EPS);
        an=max(an,i+min(more,i-1));
        if(r+sqrt(3)*r*(2*i-1)*0.5<h+r+EPS)an=max(an,i*3);*/
    }
    printf("%d\n",an);
    return 0;
}