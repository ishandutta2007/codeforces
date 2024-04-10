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
char s[1111],s2[3][1111];
void print(int x,int y,int z){
    REP(i,x)printf("|");
    putchar('+');
    REP(i,y)printf("|");
    putchar('=');
    REP(i,z)printf("|");
    puts("");
}
int main(){
    RS(s);
    REP(i,LEN(s)){
        if(s[i]!='|')s[i]=' ';
    }
    sscanf(s,"%s%s%s",s2[0],s2[1],s2[2]);
    int d[3];
    REP(i,3){
        d[i]=LEN(s2[i]);
    }
    if(d[0]+d[1]==d[2]){
        print(d[0],d[1],d[2]);
        return 0;
    }
    else{
        if(d[2]>1){
            if(d[0]+1+d[1]==d[2]-1){
                print(d[0],d[1]+1,d[2]-1);
                return 0;
            }
        }
        if(d[1]>1){
            if(d[0]+d[1]-1==d[2]+1){
                print(d[0],d[1]-1,d[2]+1);
                return 0;
            }
        }
        if(d[0]>1){
            if(d[0]+d[1]-1==d[2]+1){
                print(d[0]-1,d[1],d[2]+1);
                return 0;
            }
        }
    }
    puts("Impossible");
    return 0;
}