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
#define SIZE 1000005
int lst[SIZE];
int main(){
    DRII(n,k);
    int mi=SIZE;
    REP(i,n){
        DRI(x);
        lst[x]=x;
        mi=min(mi,x);
    }
    REPP(i,1,SIZE){
        if(lst[i]==0)lst[i]=lst[i-1];
    }
    for(;mi>1;mi--){
        bool err=false;
        int i;
        for(i=mi+mi;i<SIZE;i+=mi){
            int tmp=lst[i-1];
            if(tmp<=i-mi)continue;
            if(tmp-(i-mi)>k){
                err=true;
                break;
            }
        }
        if(!err){
            int tmp=lst[SIZE-1];
            if(tmp>i-mi&&tmp-(i-mi)>k)err=true;
            if(!err)break;
        }
    }
    printf("%d\n",mi);
    return 0;
}