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
pair<int,int>p[111];
int dp[111][4];
int get(int x,int y){
    if(x==0)return 0;
    if(dp[x][y]!=-1)return dp[x][y];
    int d[222]={};
    if(y==0){
        int i;
        for(i=1;i<=x;i++)d[get(i-1,1)^get(x-i,1)]=1;
    }
    else if(y==1){
        int i;
        for(i=1;i<=x;i++){
            d[get(i-1,2)^get(x-i,1)]=1;
            if(i>1)d[get(i-1,3)^get(x-i,1)]=1;
        }
    }
    else if(y==2){
        int i;
        for(i=1;i<=x;i++){
            d[get(i-1,2)^get(x-i,2)]=1;
            if(i>1&&i<x)d[get(i-1,3)^get(x-i,3)]=1;
        }
    }
    else if(y==3){
        int i;
        for(i=1;i<=x;i++){
            if(i<x)d[get(i-1,2)^get(x-i,3)]=1;
        }
    }
    int k=0;
    while(d[k])k++;
    return dp[x][y]=k;
}
int main(){
    MS1(dp);
    DRII(r,n);
    REP(i,n){
        DRII(x,y);
        p[i]=MP(x,y);
    }
    int res=0;
    sort(p,p+n);
    if(n==0)res=get(r,0);
    else{
        if(p[0].F!=1)res^=get(p[0].F-1,1);
        REPP(i,1,n){
            if(p[i].F!=p[i-1].F+1){
                if(p[i].S!=p[i-1].S)res^=get(p[i].F-p[i-1].F-1,3);
                else res^=get(p[i].F-p[i-1].F-1,2);
            }
        }
        if(p[n-1].F!=r)res^=get(r-p[n-1].F,1);
    }
    if(res)puts("WIN");
    else puts("LOSE");
    return 0;
}