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
int n,m,K,an;
const int SIZE = 111;
int a[SIZE][SIZE];
int res[SIZE],low_bit[4096];
void dfs(int x,int v){
    if(v>=an)return;
    if(x==n){
        an=v;
        return;
    }
    //same
    int dif[12]={},dif_n=0,add=0;
    REP(i,m){
        if(res[i]!=-1){
            if(a[x][i]!=res[i])add++;
        }
        else if(a[0][i]!=a[x][i]){
            dif[dif_n++]=i;
            if(dif_n+v+add>=an)break;
        }
    }
    if(dif_n+v+add<an){
        int nxt_v=dif_n+add+v;
        REP(j,dif_n)res[dif[j]]=a[0][dif[j]];
        dfs(x+1,nxt_v);
        REPP(j,1,(1<<dif_n)){
            int id=dif[low_bit[j]];
            if(res[id]==a[0][id])nxt_v+=x-1;
            else nxt_v-=x-1;
            res[id]^=1;
            dfs(x+1,nxt_v);
        }
    }
    REP(i,dif_n)res[dif[i]]=-1;
    //dif
    MS0(dif);
    dif_n=0,add=0;
    REP(i,m){
        if(res[i]!=-1){
            if(a[x][i]==res[i])add++;
        }
        else if(a[0][i]==a[x][i]){
            dif[dif_n++]=i;
            if(dif_n+v+add>=an)break;
        }
    }
    if(dif_n+v+add<an){
        int nxt_v=dif_n+add+v;
        REP(j,dif_n)res[dif[j]]=a[0][dif[j]];
        dfs(x+1,nxt_v);
        REPP(j,1,(1<<dif_n)){
            int id=dif[low_bit[j]];
            if(res[id]==a[0][id])nxt_v+=x-1;
            else nxt_v-=x-1;
            res[id]^=1;
            dfs(x+1,nxt_v);
        }
    }
    REP(i,dif_n)res[dif[i]]=-1;
}
int main(){
    REPP(i,1,4096){
        if(i&1)low_bit[i]=0;
        else low_bit[i]=low_bit[i>>1]+1;
    }
    RII(n,m);
    RI(K);
    MS1(res);
    REP(i,n)REP(j,m)RI(a[i][j]);
    if(n==1||m==1){
        puts("0");
        return 0;
    }
    an=K+1;
    dfs(1,0);
    if(an>K)puts("-1");
    else printf("%d\n",an);
    return 0;
}