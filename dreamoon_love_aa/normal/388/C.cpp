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
const int SIZE = 111;
vector<int>cards[SIZE],sp;
int main(){
    int an1=0,an2=0;
    DRI(n);
    REP(i,n){
        DRI(m);
        REP(j,m){
            DRI(x);
            cards[i].PB(x);
        }
        if(m%2==0){
            REP(j,m/2){
                an1+=cards[i][j];
                an2+=cards[i][j+m/2];
            }
        }
        else{
            REP(j,m/2){
                an1+=cards[i][j];
                an2+=cards[i][j+m/2+1];
            }
            sp.PB(cards[i][m/2]);
        }
    }
    sort(ALL(sp));
    reverse(ALL(sp));
    REP(i,SZ(sp)){
        if(i%2==0)an1+=sp[i];
        else an2+=sp[i];
    }
    printf("%d %d\n",an1,an2);
    return 0;
}