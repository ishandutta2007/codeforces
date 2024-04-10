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
int used[100000],tt,N,now;
int res[10000000],rn;
void go(int r,int d[]){
    if(r==1){
        int v=N+d[0];
        if(v<10000&&v>=0&&used[v]!=tt){
            used[v]=tt;
            if(rn<999999){
                res[rn++]=v*10000+now;
            //res[rn++]=now*10000+v;
            }
        }
        v=N-d[0];
        if(v<10000&&v>=0&&used[v]!=tt){
            used[v]=tt;
            if(rn<999999){
                res[rn++]=v*10000+now;
            //res[rn++]=now*10000+v;
            }
        }
        return;
    }
    int d2[4];
    REPP(i,0,r-1){
        for(int j=0;j<i;j++)d2[j]=d[j];
        for(int j=i+1;j<r-1;j++)d2[j]=d[j+1];
        d2[i]=d[i]-d[i+1];
        go(r-1,d2);
        d2[i]=d[i]+d[i+1];
        go(r-1,d2);
        d2[i]=d[i]*d[i+1];
        go(r-1,d2);
    }
}
int main(){
    DRII(n,m);
    N=n;
    REP(i,10000){
        tt++;
        now=i;
        int d[4]={i/1000,i/100%10,i/10%10,i%10};
        go(4,d);
    }
    sort(res,res+rn);
    rn=unique(res,res+rn)-res;
    REP(i,m){
        printf("%08d\n",res[i]);
    }
    return 0;
}