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
const int SIZE = 400000;
int d[SIZE],dn,P;
int s[SIZE],p[SIZE],N,M,cnt[SIZE],r[SIZE],rn;
void build(){
    dn=0;
    REP(i,N)d[dn++]=s[i];
    REP(i,M)d[dn++]=p[i];
    sort(d,d+dn);
    dn=unique(d,d+dn)-d;
}
int get(int x){return lower_bound(d,d+dn,x)-d;}
int nonzero;
void change(int x,int v){
    if(!cnt[x])nonzero++;
    cnt[x]+=v;
    if(!cnt[x])nonzero--;
}
int main(){
    RIII(N,M,P);
    REP(i,N)RI(s[i]);
    REP(i,M)RI(p[i]);
    build();
    REP(i,N)s[i]=get(s[i]);
    REP(i,M)p[i]=get(p[i]);
    vector<int>an;
    nonzero=0;
    REP(i,M){
        change(p[i],-1);
    }
    REP(k,P){
        rn=0;
        for(int i=k;i<N;i+=P)r[rn++]=s[i];
        if(rn<M)continue;
        REP(i,M)change(r[i],1);
        if(!nonzero)an.PB(k+1);
        REPP(i,M,rn){
            change(r[i],1);
            change(r[i-M],-1);
            if(!nonzero){
                an.PB(k+(i-M+1)*P+1);
            }
        }
        REP(i,M)change(r[rn-1-i],-1);
    }
    printf("%d\n",SZ(an));
    sort(ALL(an));
    REP(i,SZ(an)){
        if(i)printf(" ");
        printf("%d",an[i]);
    }
    puts("");
    return 0;
}