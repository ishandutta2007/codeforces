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
#define SIZE 1000
int a[SIZE][SIZE],d[SIZE*SIZE],dn,used[SIZE][SIZE],tt,N,M;
int tmp[SIZE],tn;
bool check(int v){
    REP(i,N){
        tn=0;
        REP(j,M){
            if(a[i][j]>=v){
                REP(k,tn){
                    if(used[tmp[k]][j]==tt)return 1;
                    used[tmp[k]][j]=tt;
                }
                tmp[tn++]=j;
            }
        }
    }
    return 0;
}
int main(){
    DRII(n,m);
    N=n;M=m;
    REP(i,n)
        REP(j,m){
            RI(a[i][j]);
            d[dn++]=a[i][j];
        }
    sort(d,d+dn);
    dn=unique(d,d+dn)-d;
    int ll=0,rr=dn-1;
    while(ll<rr){
        int mm=(ll+rr+1)>>1;
        tt++;
        if(check(d[mm]))ll=mm;
        else rr=mm-1;
    }
    printf("%d\n",d[ll]);
    return 0;
}