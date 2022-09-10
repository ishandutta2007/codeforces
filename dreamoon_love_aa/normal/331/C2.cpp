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
int need[1000000][10],next[1000000][10];
int main(){
    long long res=0,n;
    cin>>n;
    if(n==1000000000000ll){
        res++;
        n--;
    }
    REP(i,10)
        REP(j,10)next[i][j]=i;
    REPP(i,10,1000000){
        int tmp=i,ma=0;
        while(tmp){
            ma=max(ma,tmp%10);
            tmp/=10;
        }
        REP(j,10){
            need[i][j]=need[i-max(ma,j)][j]+1;
            next[i][j]=next[i-max(ma,j)][j];
        }
    }
    int xx=n/1000000,yy=n%1000000;
    while(xx||yy){
        int tmp=xx,ma=0;
        while(tmp){
            ma=max(ma,tmp%10);
            tmp/=10;
        }
        res+=need[yy][ma];
        yy=next[yy][ma];
        while(yy>0||xx>0&&!yy){
            yy-=max(ma,yy);
            res++;
        }
        if(yy<0){
            xx--;
            yy+=1000000;
        }

    }
    cout<<res<<endl;
    return 0;
}