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
int a[2002],res[222];
vector<int>pos[200];
int main(){
    DRI(n);
    REP(i,2*n){
        RI(a[i]);
        pos[a[i]].PB(i);
    }
    vector<int>an[2],d,one;
    int cnt[2]={};
    REPP(i,10,100){
        if(SZ(pos[i])<2){
            REP(j,SZ(pos[i]))one.PB(pos[i][j]);
            continue;
        }
        REP(j,2){
            cnt[j]++;
            an[j].PB(pos[i][j]);
        }
        REPP(j,2,SZ(pos[i]))d.PB(pos[i][j]);
    }
    REP(i,SZ(one)){
        cnt[i&1]++;
        an[i&1].PB(one[i]);
    }
    REP(i,SZ(d)){
        if(SZ(an[0])<SZ(an[1]))an[0].PB(d[i]);
        else if(SZ(an[0])>SZ(an[1]))an[1].PB(d[i]);
        else an[0].PB(d[i]);
    }
    REP(i,2)REP(j,SZ(an[i])){
        res[an[i][j]]=i+1;
    }
    printf("%d\n",cnt[0]*cnt[1]);
    REP(i,2*n){
        if(i)printf(" ");
        printf("%d",res[i]);
    }
    puts("");
    return 0;
}