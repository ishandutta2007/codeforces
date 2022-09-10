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
const int SIZE = 1e6+20;
int last[SIZE][20],ma,lv[SIZE];
int dis(int x,int y){
    int res=0;
    if(lv[x]>lv[y])swap(x,y);
    res=lv[y]-lv[x];
    for(int i=0;(1<<i)<=res;i++){
        if((res>>i)&1)y=last[y][i];
    }
    if(x==y)return res;
    for(int i=19;i>=0;i--){
        if(last[x][i]!=last[y][i]){
            res+=(1<<i)<<1;
            x=last[x][i];
            y=last[y][i];
        }
    }
    return res+2;
}
void add(int x,int lt,int p[]){
    lv[x]=lv[lt]+1;
    last[x][0]=lt;
    REPP(i,1,20)last[x][i]=last[last[x][i-1]][i-1];
    int tmp=dis(x,p[0]);
    if(tmp>ma){
        p[1]=x;
        ma=tmp;
    }
    else{
        tmp=dis(x,p[1]);
        if(tmp>ma){
            p[0]=x;
            ma=tmp;
        }
    }
}
int main(){
    DRI(Q);
    REPP(i,2,5){
        last[i][0]=1;
        lv[i]=1;
    }
    ma=2;
    int now=5,p[2]={2,3};
    while(Q--){
        DRI(x);
        add(now,x,p);
        add(now+1,x,p);
        now+=2;
        printf("%d\n",ma);
    }
    return 0;
}