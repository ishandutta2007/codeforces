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
int a[18][1<<17],n;
void init(int lv){
    if(lv==n)return;
    REP(i,1<<(n-lv-1)){
        if(lv&1)a[lv+1][i]=a[lv][i*2]^a[lv][i*2+1];
        else a[lv+1][i]=a[lv][i*2]|a[lv][i*2+1];
    }
    init(lv+1);
}
void edit(int lv,int id){
    if(lv==n)return;
    if(lv&1)a[lv+1][id>>1]=a[lv][id]^a[lv][id^1];
    else a[lv+1][id>>1]=a[lv][id]|a[lv][id^1];
    edit(lv+1,id>>1);
}
int main(){
    int q;
    scanf("%d%d",&n,&q);
    REP(i,1<<n)scanf("%d",&a[0][i]);
    init(0);
    while(q--){
        DRII(x,y);
        a[0][x-1]=y;
        edit(0,x-1);
        printf("%d\n",a[n][0]);
    }
    return 0;
}