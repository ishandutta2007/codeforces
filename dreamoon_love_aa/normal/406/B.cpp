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
const int SIZE = 1e6+5;
int d[SIZE],an[SIZE],ann;
int main(){
    DRI(n);
    REP(i,n){
        DRI(x);
        d[x]=1;
    }
    int cnt=0;
    REPP(i,1,500001){
        if(d[i]&&d[1000000+1-i])cnt++;
        else if(d[i]){
            an[ann++]=1000000+1-i;
        }
        else if(d[1000000+1-i]){
            an[ann++]=i;
        }
    }
    REPP(i,1,500001){
        if(!d[i]&&!d[1000000+1-i]&&cnt){
            cnt--;
            an[ann++]=i;
            an[ann++]=1000000+1-i;
        }
    }
    printf("%d\n",ann);
    REP(i,ann){
        if(i)putchar(' ');
        printf("%d",an[i]);
    }
    return 0;
}