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
#define SIZE 100010
int flag;
struct data{
    int a,b,No,No2;
    bool operator<(const data& B)const{
        if(!flag)
            return b<B.b||(b==B.b&&a>B.a);
        else if(flag==1)
            return a>B.a||(a==B.a&&No2>B.No2);
        else if(flag==2)
            return No2<B.No2;
        else 
            return b>B.b;
    }
}d[SIZE];
int main(){
    DRIII(n,p,k);
    REP(i,n){
        RII(d[i].a,d[i].b);
        d[i].No=i+1;
    }
    sort(d,d+n);
    REP(i,n)d[i].No2=i;
    flag=1;
    sort(d+p-k,d+n);
    int mi=100000000;
    REPP(i,p-k,p){
        mi=min(mi,d[i].No2);
        if(i!=p-k)printf(" ");
        printf("%d",d[i].No);
    }
    flag=2;
    sort(d,d+n);
    flag=3;
    sort(d,d+mi);
    REP(i,p-k){
        printf(" %d",d[i].No);
    }
    puts("");
    return 0;
}