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
#define SIZE 333
int a[SIZE],used[SIZE];
vector<pair<int,int> >e;
int main(){
    DRIII(n,m,k);
    if(m==n*(n-1)/2||k==n)puts("-1");
    else{
        REP(i,k){
            RI(a[i]);
            used[a[i]]=1;
        }
        int sp1=0,sp2=0,sp3=0;
        REPP(i,1,n+1){
            if(used[i]==0){
                sp3=i;
                break;
            }
        }
        sp1=a[0];
        sp2=a[1];
        int d[SIZE];
        REPP(i,1,n+1)d[i]=i;
        if(sp1!=n-2)swap(d[n-2],d[sp1]);
        if(sp2==d[sp1])swap(d[sp1],d[n]);
        else swap(d[sp2],d[n]);
        if(sp3==d[sp1])swap(d[sp1],d[n-1]);
        else if(sp3==d[sp2])swap(d[sp2],d[n-1]);
        else swap(d[sp3],d[n-1]);
        REPP(i,1,n){
            REPP(j,1,n){
                if(j+i>n)break;
                if(used[d[j]]&&j+i==n&&j!=n-1)continue;
                if(j==n-2&&j+i==n)continue;
                e.PB(MP(d[j],d[j+i]));
            }
        }
        if(SZ(e)<m)puts("-1");
        else{
            REP(i,m)printf("%d %d\n",e[i].F,e[i].S);
        }
    }
    return 0;
}