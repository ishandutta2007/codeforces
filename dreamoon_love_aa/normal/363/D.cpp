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
int b[SIZE],p[SIZE];
int main(){
    DRIII(n,m,a);
    REP(i,n)RI(b[i]);
    REP(i,m)RI(p[i]);
    sort(b,b+n);
    sort(p,p+m);
    int ll=0,rr=min(n,m);
    while(ll<rr){
        int mm=(ll+rr+1)>>1;
        long long need=0;
        REP(i,mm){
            need+=p[i]-min(b[n-mm+i],p[i]);
        }
        if(need<=a)ll=mm;
        else rr=mm-1;
    }
    long long sum=0;
    REP(i,ll){
        sum+=p[i];
    }
    cout<<ll<<" "<<max(sum-a,0ll)<<endl;
    return 0;
}