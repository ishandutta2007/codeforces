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
#define SIZE 100000
int t[SIZE],l[SIZE],r[SIZE];
bool in(int ll,int rr,int x){
    return ll<=x&&x<=rr;
}
int main(){
    DRII(n,m);
    DRII(s,f);
    REP(i,m){
        RIII(t[i],l[i],r[i]);
    }
    int now_t=1,idx=0,pos=s;
    while(pos!=f){
        bool can=true;
        if(pos<f){
            if(idx<m&&now_t==t[idx]&&(in(l[idx],r[idx],pos)||in(l[idx],r[idx],pos+1)))can=false;
            if(can){putchar('R');pos++;}
            else putchar('X');
        }
        else{
            if(idx<m&&now_t==t[idx]&&(in(l[idx],r[idx],pos)||in(l[idx],r[idx],pos-1)))can=false;
            if(can){putchar('L');pos--;}
            else putchar('X');
        }
        if(idx<m&&now_t==t[idx])idx++;
        now_t++;
    }
    puts("");
    return 0;
}