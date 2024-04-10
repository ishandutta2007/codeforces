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
int dx[4]={1,1,-1,-1};
int dy[4]={1,-1,1,-1};
int ma[10][4],id[10][4],r[10][10];
const int INF = (int)1e9;
int main(){
    DRII(n,m);
    DRII(k,s);
    REP(i,k)REP(j,4)ma[i][j]=-INF;
    REP(i,n)REP(j,m){
        DRI(x);
        x--;
        REP(k,4){
            int v=i*dx[k]+j*dy[k];
            if(v>ma[x][k]){
                ma[x][k]=v;id[x][k]=i*m+j;
            }
        }
    }
    REP(i,k)REP(j,k){
        REP(i2,4)REP(j2,4){
            r[i][j]=max(r[i][j],abs(id[i][i2]/m-id[j][j2]/m)+abs(id[i][i2]%m-id[j][j2]%m));
        }
    }
    int an=0;
    int last=-1;
    REP(i,s){
        DRI(x);
        x--;
        if(last!=-1){
            an=max(an,r[last][x]);
        }
        last=x;
    }
    printf("%d\n",an);
    return 0;
}