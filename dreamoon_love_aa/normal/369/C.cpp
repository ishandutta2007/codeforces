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
const int SIZE = 100100;
vector<pair<int,int> >e[SIZE];
int bfs[SIZE],last[SIZE],re[SIZE],need[SIZE],used[SIZE];
int main(){
    DRI(n);
    REPP(i,1,n){
        DRIII(x,y,v);
        e[x].PB(MP(y,v));
        e[y].PB(MP(x,v));
    }
    bfs[0]=1;
    last[0]=0;
    for(int i=0,j=1;i<j;i++){
        int x=bfs[i];
        REP(k,SZ(e[x])){
            int y=e[x][k].F;
            if(y==last[x])continue;
            last[y]=x;
            bfs[j++]=y;
            need[y]=e[x][k].S;
        }
    }
    vector<int>res;
    for(int i=n-1;i>=0;i--){
        int x=bfs[i];
        if(need[x]==2&&!used[x]){
            res.PB(x);
            used[last[x]]=true;
        }
        if(used[x])used[last[x]]=true;
    }
    sort(ALL(res));
    printf("%d\n",SZ(res));
    REP(i,SZ(res)){
        if(i)putchar(' ');
        printf("%d",res[i]);
    }
    return 0;
}