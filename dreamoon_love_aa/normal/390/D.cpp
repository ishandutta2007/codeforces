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
void print(int x,int y){
    if(x==1&&y==1){
        printf("(%d,%d)",1,1);
        return;
    }
    if(x>1)print(x-1,y);
    else print(x,y-1);
    printf(" (%d,%d)",x,y);
}
int main(){
    vector<pair<int,int> >pp;
    DRIII(n,m,k);
    REPP(i,1,n+1)REPP(j,1,m+1){
        pp.PB(MP(i+j,j));
    }
    sort(ALL(pp));
    int an=0;
    for(int i=0;i<k;i++)an+=pp[i].F-1;
    printf("%d\n",an);
    for(int i=k-1;i>=0;i--){
        print(pp[i].F-pp[i].S,pp[i].S);
        puts("");
    }
    return 0;
}