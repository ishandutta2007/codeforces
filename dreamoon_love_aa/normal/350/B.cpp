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
#define SIZE 100010
int ty[SIZE],ma[SIZE],used[SIZE],tt;
vector<int>e[SIZE];
int go(int x){
    if(used[x]==tt)return ma[x]=0;
    used[x]=tt;
    if(ma[x]!=-1)return ma[x];
    if(ty[x]==1){
        return ma[x]=1;
    }
    if(SZ(e[x])>1||SZ(e[x])==0)return ma[x]=0;
    int tmp=go(e[x][0]);
    if(!tmp)return ma[x]=0;
    return ma[x]=tmp+1;
}
int main(){
    DRI(n);
    REPP(i,1,n+1)RI(ty[i]);
    REPP(i,1,n+1){
        DRI(x);
        if(x&&SZ(e[x])<2)e[x].PB(i);
    }
    MS1(ma);
    int id=-1,res=-1;
    REPP(i,1,n+1){
        if(ma[i]==-1){
            tt++;
            ma[i]=go(i);
        }
        if(ma[i]>res){
            res=ma[i];
            id=i;
        }
    }
    printf("%d\n",res);
    while(ty[id]!=1){
        printf("%d ",id);
        id=e[id][0];
    }
    printf("%d\n",id);
    return 0;
}