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
const int SIZE = 1000010;
int d[SIZE],match[SIZE],an[SIZE];
void ins(int x){
    while(x<SIZE){
        d[x]++;
        x+=x&-x;
    }
}
int query(int x){
    int res=0;
    while(x){
        res+=d[x];
        x-=x&-x;
    }
    return res;
}
char s[SIZE];
vector<pair<int,int> >qq[SIZE];
int stack[SIZE],sn;
int main(){
    MS1(match);
    RS(s+1);
    int n=LEN(s+1);
    DRI(Q);
    REP(i,Q){
        DRII(x,y);
        qq[x].PB(MP(y,i));
    }
    for(int i=1;i<=n;i++){
        if(s[i]=='(')stack[sn++]=i;
        else{
            if(sn){
                match[stack[--sn]]=i;
            }
        }
    }
    for(int i=n;i>=1;i--){
        if(s[i]=='('&&match[i]!=-1){
            ins(match[i]);
        }
        REP(j,SZ(qq[i]))an[qq[i][j].S]=query(qq[i][j].F);
    }
    REP(i,Q)printf("%d\n",an[i]*2);
    return 0;
}