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
int d[3];
char an[1000][1000][3];
int main(){
    DRII(n,m);
    REP(i,n)REP(j,m)an[i][j][0]=an[i][j][1]='0';
    REP(i,n*m){
        char s[4];
        RS(s);
        int r=s[0]+s[1]-'0'-'0';
        d[r]++;
    }
    int x=0,y=0;
    while(d[2]>0){
        an[x][y][0]=an[x][y][1]='1';
        d[2]--;
        y++;
        if(y==m)x++,y=0;
    }
    int ed=y;
    y=m-1;
    int flag=0;
    while(d[1]>0){
        if(flag)an[x][y][1]='1';
        else an[x][y][0]='1';
        d[1]--;
        y--;
        if(y<ed){
            ed=0;
            y=m-1;
            x++;
            flag^=1;
        }
    }
    REP(i,n){
        REP(j,m){
            if(j)putchar(' ');
            printf("%s",an[i][j]);
        }
        puts("");
    }
    return 0;
}