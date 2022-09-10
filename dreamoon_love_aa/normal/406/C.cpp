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
vector<pair<int,int> >e[100010];
int an[100000][3],ann,e_used[100010],used[100010];
void err(){puts("No solution");}
int dfs(int x){
    used[x]=1;
    vector<int>son;
    REP(i,SZ(e[x])){
        if(e_used[e[x][i].S])continue;
        e_used[e[x][i].S]=1;
        if(!used[e[x][i].F]){
            int tmp=dfs(e[x][i].F);
            if(tmp){
                an[ann][0]=x;
                an[ann][1]=e[x][i].F;
                an[ann++][2]=tmp;
            }
            else son.PB(e[x][i].F);
        }
        else{
            son.PB(e[x][i].F);
        }
    }
    for(int i=0;i+2<=SZ(son);i+=2){
        an[ann][0]=son[i];
        an[ann][1]=x;
        an[ann++][2]=son[i+1];
    }
    if(SZ(son)%2==0)return 0;
    return son.back();
}
int main(){
    DRII(n,m);
    REP(i,m){
        DRII(x,y);
        e[x].PB(MP(y,i));
        e[y].PB(MP(x,i));
    }
    if(m%2){
        err();
        return 0;
    }
    REPP(i,1,n+1){
        if(!used[i]){
            if(dfs(i)){
                err();
                return 0;
            }
        }
    }
    REP(i,ann){
        REP(j,3){
            if(j)putchar(' ');
            printf("%d",an[i][j]);
        }
        puts("");
    }
    return 0;
}