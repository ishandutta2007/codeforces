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
const int SIZE  = 1e5+5;
const int IN = 1;
const int OUT = 0;
struct data{
    int id,x,io;
    data(int _id=0,int _x=0,int _io=0):id(_id),x(_x),io(_io){}
    bool operator<(const data& b)const{return x<b.x;}
}a[SIZE*2];
int m=0;
int to[SIZE*2],an[SIZE];
int main(){
    DRI(n);
    REP(i,n){
        DRII(l,r);
        a[m++]=data(i,l,IN);
        a[m++]=data(i,r+1,OUT);
    }
    sort(a,a+m);
    for(int i=0;i<m;i++)
        to[a[i].id*2+a[i].io]=a[i^1].id*2+a[i^1].io;
    for(int i=0;i<n;i++){
        if(!an[i]){
            int now=i;
            int me=IN;
            an[i]=1;
            while(1){
                int tmp=to[now*2+me];
                if(tmp/2==i)break;
                if((tmp&1)==me){
                    an[tmp>>1]=-an[now];
                }
                else{
                    an[tmp>>1]=an[now];
                }
                now=tmp>>1;
                me=tmp&1;
                me^=1;
            }
        }
    }
    REP(i,n){
        if(i)putchar(' ');
        if(an[i]==1)printf("1");
        else printf("0");
    }
    puts("");
    return 0;
}