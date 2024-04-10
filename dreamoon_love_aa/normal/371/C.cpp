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
const int SIZE = 111;
char s[SIZE];
int a[3],p[3],me[3];
int main(){
    RS(s);
    for(int i=0;s[i];i++){
        if(s[i]=='B')a[0]++;
        else if(s[i]=='S')a[1]++;
        else a[2]++;
    }
    REP(i,3)RI(me[i]);
    REP(i,3)RI(p[i]);
    long long V;
    scanf("%I64d",&V);
    long long ll=0,rr=1e15;
    while(ll<rr){
        long long mm=(ll+rr+1)>>1;
        long long need=0;
        REP(i,3)need+=max(0ll,(a[i]*mm-me[i])*p[i]);
        if(need<=V)ll=mm;
        else rr=mm-1;
    }
    cout<<ll<<endl;
    return 0;
}