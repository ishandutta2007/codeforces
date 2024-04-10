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
const int SIZE = 1e5+5;
vector<int>e[SIZE];
int used[SIZE],an,a[SIZE];
vector<int>res;
void dfs(int x,int lv,int d[]){
    used[x]=1;
    a[x]^=d[lv&1];
    int d2[2]={d[0],d[1]};
    if(a[x]){
        d2[lv&1]^=1;
        res.PB(x);
    }
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(used[y])continue;
        dfs(y,lv+1,d2);
    }
}
int main(){
    DRI(n);
    REPP(i,1,n){
        DRII(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    REPP(i,1,n+1)RI(a[i]);
    REPP(i,1,n+1){
        DRI(x);
        a[i]^=x;
    }
    int d[2]={};
    dfs(1,0,d);
    sort(ALL(res));
    printf("%d\n",SZ(res));
    REP(i,SZ(res))printf("%d\n",res[i]);
    return 0;
}