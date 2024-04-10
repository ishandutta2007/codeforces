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
struct EDGE{
    int x,y,v;
    EDGE(int _x=0,int _y=0,int _v=0):x(_x),y(_y),v(_v){}
}e[SIZE];
int ll[SIZE],rr[SIZE],d[SIZE],ty[SIZE];
int find(int x){
    if(x!=d[x])return d[x]=find(d[x]);
    return x;
}
void uu(int x,int y){
    x=find(x);
    y=find(y);
    d[x]=y;
}
int ee[511][511];
int main(){
    DRIII(n,m,K);
    int now=1;
    REP(i,K){
        DRI(cc);
        ll[i]=now;
        rr[i]=now+cc-1;
        now+=cc;
    }
    REPP(i,1,n+1)d[i]=i;
    REP(i,m){
        RIII(e[i].x,e[i].y,e[i].v);
        if(!e[i].v)uu(e[i].x,e[i].y);
    }
    bool err=false;
    REP(i,K){
        REPP(j,ll[i],rr[i]){
            if(find(j)!=find(j+1))err=true;
        }
        REPP(j,ll[i],rr[i]+1)ty[j]=i;
    }
    if(err)puts("No");
    else{
        REP(i,K){
            REP(j,K)ee[i][j]=1e9;
            ee[i][i]=0;
        }
        REP(i,m){
            if(ty[e[i].x]!=ty[e[i].y]){
                ee[ty[e[i].x]][ty[e[i].y]]=min(e[i].v,ee[ty[e[i].x]][ty[e[i].y]]);
                ee[ty[e[i].y]][ty[e[i].x]]=min(e[i].v,ee[ty[e[i].y]][ty[e[i].x]]);
            }
        }
        REP(k,K){
            REP(i,K)
                REP(j,K)ee[i][j]=min(ee[i][k]+ee[k][j],ee[i][j]);
        }
        puts("Yes");
        REP(i,K){
            REP(j,K){
                if(j)putchar(' ');
                if(ee[i][j]==(int)1e9)printf("-1");
                else printf("%d",ee[i][j]);
            }
            puts("");
        }
    }
    return 0;
}