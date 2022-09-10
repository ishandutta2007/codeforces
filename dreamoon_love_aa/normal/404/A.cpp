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
const int SIZE = 1024;
char s[SIZE][SIZE];
int d[2][128],id[2];
int main(){
    DRI(n);
    REP(i,n)RS(s[i]);
    REP(i,n)REP(j,n){
        if(i==j||i+j==n-1){
            d[0][s[i][j]]=1;
        }
        else{
            d[1][s[i][j]]=1;
        }
    }
    REP(i,2){
        int ha=0;
        REP(j,128){
            ha+=d[i][j];
            if(d[i][j])id[i]=j;
        }
        if(ha!=1){
            puts("NO");
            return 0;
        }
    }
    if(id[0]!=id[1])puts("YES");
    else puts("NO");
    return 0;
}