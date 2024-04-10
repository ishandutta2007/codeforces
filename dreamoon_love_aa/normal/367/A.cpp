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
const int SIZE =100010;
const int INF = 100010000;
char s[SIZE];
int d[SIZE][3];
int main(){
    RS(s+1);
    for(int i=1;s[i];i++){
        REP(j,4)d[i][j]=d[i-1][j];
        d[i][s[i]-'x']++;
    }
    DRI(n);
    REP(i,n){
        DRII(x,y);
        if(y-x<=1)puts("YES");
        else{
            int ma=-INF,mi=INF;
            REP(i,3){
                ma=max(ma,d[y][i]-d[x-1][i]);
                mi=min(mi,d[y][i]-d[x-1][i]);
            }
            if(ma<=mi+1)puts("YES");
            else puts("NO");
        }
    }
    return 0;
}