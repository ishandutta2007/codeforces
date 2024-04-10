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
#define SIZE 1000010
const int MAX = (int)1e9;
int x[SIZE],d[SIZE],ma[SIZE],an[SIZE],a;
void fresh_ma(int &x,int v){
    if(x<v)x=v;
}
void fresh_mi(int &x,int v){
    if(x>v)x=v;
}
void insert(int x,int v){
    if(!x)return;
    while(x<SIZE){
        fresh_mi(d[x],v);
        x+=x&-x;
    }
}
int qq(int x){
    int res=MAX;
    while(x){
        fresh_mi(res,d[x]);
        x-=x&-x;
    }
    return res;
}
int main(){
    DRI(n);
    REP(i,n)RI(x[i]);
    DRII(a,b);
    sort(x,x+n);
    n=unique(x,x+n)-x;
    REP(i,n){
        int k=b/x[i]*x[i];
        if(k<b)k+=x[i];
        while(k<=a){
            fresh_ma(ma[k-b],x[i]);
            k+=x[i];
        }
    }
    REP(i,SIZE)d[i]=MAX;
    insert(a-b,an[a-b]=0);
    for(int i=a-1;i>=b;i--){
        if(ma[i-b]==0)an[i-b]=an[i+1-b]+1;
        else{
            an[i-b]=qq(min(i+ma[i-b]-1-b,SIZE-1))+1;
        }
        insert(i-b,an[i-b]);
    }
    printf("%d\n",an[0]);
    return 0;
}