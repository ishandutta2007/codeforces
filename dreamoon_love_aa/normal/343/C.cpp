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
long long h[SIZE],p[SIZE];
const long long INF=(long long)3e10;
bool valid(int n,int m,long long v){
    int id=0;
    REP(i,n){
        if(p[id]<h[i]){
            if(p[id]+v<h[i])return false;
            long long nt=max(p[id]+v-(h[i]-p[id]),h[i]);
            nt=max(nt,h[i]+(v-(h[i]-p[id]))/2);
            while(id<m&&p[id]<=nt)id++;
        }
        else{
            long long nt=h[i]+v;
            while(id<m&&p[id]<=nt)id++;
        }
        if(id>=m)return true;
    }
    return false;
}
int main(){
    DRII(n,m);
    REP(i,n)scanf("%I64d",&h[i]);
    REP(i,m)scanf("%I64d",&p[i]);
    long long ll=0,rr=INF;
    while(ll<rr){
        long long mm=(ll+rr)>>1;
        if(valid(n,m,mm))rr=mm;
        else ll=mm+1;
    }
    printf("%I64d\n",ll);
    return 0;
}