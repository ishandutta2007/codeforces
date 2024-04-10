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
const int SIZE = 25;
int e[SIZE][SIZE],n,p;
void find(){
    REPP(i,1,n+1)
        REPP(j,i+1,n+1){
            if(e[i][j]==0){
                e[i][j]=e[j][i]=1;
                return;
            }
        }
}
int main(){
    CASET{
        MS0(e);
        RII(n,p);
        REPP(i,1,n+1){
            e[i][i%n+1]=1;
            e[i][(i+1)%n+1]=1;
            e[i][(i+n-2)%n+1]=1;
            e[i][(i+n-3)%n+1]=1;
        }
        while(p>0){
            find();
            p--;
        }
        REPP(i,1,n+1)REPP(j,i+1,n+1){
            if(e[i][j])printf("%d %d\n",i,j);
        }
    }
    return 0;
}