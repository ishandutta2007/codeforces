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
#define MAX 10000000
#define SIZE 100010
bool fail[SIZE],p[SIZE];
int D,used[SIZE],tt,dp[SIZE][2];
vector<int>e[SIZE];
void fresh(int dd[],int v){
    if(v>dd[0]){
        dd[1]=dd[0];
        dd[0]=v;
    }
    else if(v>dd[1])dd[1]=v;
}
int dfs1(int x){
    used[x]=tt;
    if(p[x])fresh(dp[x],0);
    REP(i,SZ(e[x])){
        if(used[e[x][i]]==tt)continue;
        fresh(dp[x],dfs1(e[x][i]));
    }
    if(dp[x][0]>D)fail[x]=1;
    return dp[x][0]+1;
}
void dfs2(int x,int v){
    used[x]=tt;
    if(v>D)fail[x]=1;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(used[y]==tt)continue;
        if(dp[y][0]+1==dp[x][0])dfs2(y,max(v,dp[x][1])+1);
        else dfs2(y,max(v,dp[x][0])+1);
    }
}
int main(){
    DRIII(n,m,d);
    D=d;
    REP(i,m){
        DRI(x);
        p[x]=1;
    }
    REP(i,n-1){
        DRII(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    tt++;
    REPP(i,1,n+1)dp[i][0]=dp[i][1]=-MAX;
    dfs1(1);
    tt++;
    dfs2(1,-MAX);
    int an=0;
    REPP(i,1,n+1)
        if(!fail[i])an++;
    printf("%d\n",an);
    return 0;
}