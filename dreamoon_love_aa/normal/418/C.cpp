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
int dp[101][10001],a[101],b[101];
void go(int d[],int n){
    int last;
    REPP(i,1,101){
        if(dp[n][i*i]){
            last=i*i;
            break;
        }
    }
    int it=0;
    while(n){
        d[it++]=dp[n][last];
        last-=d[it-1]*d[it-1];
        n--;
    }
}
int main(){
    dp[0][0]=-1;
    REPP(i,1,101){
        REP(j,100){
            for(int k=i*i;k<=10000;k++){
                if(dp[j][k-i*i]){
                    dp[j+1][k]=i;
                }
            }
        }
    }
    REPP(i,1,101){
        bool ff=false;
        REP(j,101){
            if(dp[i][j*j])ff=true;
        }
        if(!ff)printf("WA %d\n",i);
    }
    DRII(n,m);
    go(a,n);
    go(b,m);
    REP(i,n){
        REP(j,m){
            if(j)putchar(' ');
            printf("%d",a[i]*b[j]);
        }
        puts("");
    }
    return 0;
}