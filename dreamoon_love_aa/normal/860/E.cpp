#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
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
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6;
// 1-based
vector<int>e[SIZE];
VI gg[SIZE];
int jump[20][SIZE],lv[SIZE];
void __init(int x,int lt){
    gg[lv[x]].PB(x);
    jump[0][x]=lt;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(y!=lt){
            lv[y]=lv[x]+1;
            __init(y,x);
        }
    }
}
int adv(int x,int v){
    for(int i=0;(1<<i)<=v;i++){
        if((v>>i)&1)x=jump[i][x];
    }
    return x;
}
int lca(int x,int y){
    if(lv[x]>lv[y])x=adv(x,lv[x]-lv[y]);
    else y=adv(y,lv[y]-lv[x]);
    if(x==y)return x;
    for(int i=19;i>=0;i--)
        if(jump[i][x]!=jump[i][y]){x=jump[i][x];y=jump[i][y];}
    return jump[0][x];
}
void build(int root,int N){
    __init(root,root);
    REPP(i,1,20){
        REPP(x,1,N+1)
            jump[i][x]=jump[i-1][jump[i-1][x]];
    }
}
LL an[SIZE];
int h[SIZE];
PII stk[SIZE];
void handle(int now_lv){
    int m=SZ(gg[now_lv]);
    REP(i,m){
        int x=gg[now_lv][i];
        an[x]=an[jump[0][x]]+lv[x];
    }
    REPP(i,1,m){
        h[i]=lv[lca(gg[now_lv][i-1],gg[now_lv][i])]+1;
    }
    LL now=0;
    int sn=0;
    REPP(i,1,m){
        int num=1;
        while(sn&&h[i]<=stk[sn-1].F){
            now-=(LL)stk[sn-1].F*stk[sn-1].S;
            num+=stk[--sn].S;
        }
        now+=(LL)h[i]*num;
        stk[sn++]=MP(h[i],num);
        an[gg[now_lv][i]]+=now;
    }
    sn=0;
    now=0;
    for(int i=m-1;i>0;i--){
        int num=1;
        while(sn&&h[i]<=stk[sn-1].F){
            now-=(LL)stk[sn-1].F*stk[sn-1].S;
            num+=stk[--sn].S;
        }
        now+=(LL)h[i]*num;
        stk[sn++]=MP(h[i],num);
        an[gg[now_lv][i-1]]+=now;
    }
}
int main(){
    int root=0;
    DRI(N);
    REPP(i,1,N+1){
        DRI(x);
        if(!x)root=i;
        else e[x].PB(i);
    }
    build(root,N);
    REPP(i,1,SIZE){
        if(!SZ(gg[i]))break;
        handle(i);
    }
    REPP(i,1,N+1)printf("%I64d ",an[i]);
    return 0;
}