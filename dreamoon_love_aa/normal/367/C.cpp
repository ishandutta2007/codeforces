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
vector<int>cc;
long long res;
void odd(int n,int m){
    int ll=1,rr=5000;
    while(ll<rr){
        int mm=(ll+rr+1)>>1;
        int real=mm*2-1;
        if(real*(real-1)/2+1<=n)ll=mm;
        else rr=mm-1;
    }
    int real=ll*2-1;
    real=min(real,m);
    if(real%2==0)real--;
    long long tmp=0;
    for(int i=0;i<real;i++)tmp+=cc[i];
    res=max(res,tmp);
}
void even(int n,int m){
    int ll=0,rr=5000;
    while(ll<rr){
        int mm=(ll+rr+1)>>1;
        int real=mm*2;
        if(real*(real-1)/2+(real/2-1)+1<=n)ll=mm;
        else rr=mm-1;
    }
    int real=ll*2;
    real=min(real,m);
    if(real%2==1)real--;
    long long tmp=0;
    for(int i=0;i<real;i++)tmp+=cc[i];
    res=max(res,tmp);
}
int main(){
    DRII(n,m);
    REP(i,m){
        DRII(q,w);
        cc.PB(w);
    }
    sort(ALL(cc));
    reverse(ALL(cc));
    odd(n,m);
    even(n,m);
    cout<<res<<endl;
    return 0;
}