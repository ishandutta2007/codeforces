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
struct EDGE{
    int x,y,l,h;
    EDGE(int _x=0,int _y=0,int _l=0,int _h=0):x(_x),y(_y),l(_l),h(_h){}
    bool operator<(const EDGE& b)const{return h>b.h;}
}e[3030];
int lv[3030],d[3030];
int find(int x){
    return x!=d[x]?d[x]=find(d[x]):x;
}
void uu(int x,int y){
    x=find(x);
    y=find(y);
    d[x]=y;
}
int go(int low,int n,int m){
    REPP(i,1,n+1)d[i]=i;
    REP(i,m){
        if(e[i].l<=low)uu(e[i].x,e[i].y);
        if(find(1)==find(n))return e[i].h-low+1;
    }
    return 0;
}
int main(){
    DRII(n,m);
    REP(i,m){
        DRII(x,y);
        DRII(low,high);
        e[i]=EDGE(x,y,low,high);
        lv[i]=low;
        d[i+1]=i+1;
    }
    sort(e,e+m);
    int ma=0;
    REP(i,m){
        ma=max(ma,go(lv[i],n,m));
    }
    if(ma==0)puts("Nice work, Dima!");
    else printf("%d\n",ma);
    return 0;
}