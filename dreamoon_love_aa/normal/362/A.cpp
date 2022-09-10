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
char s[9][9];
void move1(int &x,int &y){
    while(x>=4){
        x-=4;
    }
    while(y>=4)y-=4;
}
void move2(int &x,int &y){
    while(x>=4){
        x-=4;
    }
    while(y>=4)y-=4;
    while(x>=2){
        x-=2;
        y+=2;
    }
    while(y>=4)y-=4;
}
int main(){
    CASET{
        vector<pair<int,int> >K;
        REP(i,8)RS(s[i]);
        REP(i,8){
            REP(j,8){
                if(s[i][j]=='K')K.PB(MP(i,j));
            }
        }
        move1(K[0].F,K[0].S);
        move1(K[1].F,K[1].S);
        if(K[0].F!=K[1].F||K[0].S!=K[1].S)puts("NO");
        else{
            bool suc=false;
            move2(K[0].F,K[0].S);
            REP(i,8)REP(j,8){
                int x=i,y=j;
                if(s[i][j]=='#')continue;
                move2(x,y);
                if(x==K[0].F&&y==K[0].S&&!suc){
                    puts("YES");
                    suc=true;
                }
            }
            if(!suc)puts("NO");
        }
    }
    return 0;
}