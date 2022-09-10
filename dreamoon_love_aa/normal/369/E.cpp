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
const int SIZE = 3*1e5+5;
struct data{
    int L,R,id;
    data(int _L=0,int _R=0,int _id=0):L(_L),R(_R),id(_id){}
    bool operator<(const data& b)const{
        return R<b.R||(R==b.R&&id<b.id);
    }
}e[SIZE<<2];
const int B_SIZE = 1000001;
int en,an[SIZE],BIT[1000002];
void insert(int x){
    x=B_SIZE-x;
    while(x<B_SIZE){
        BIT[x]++;
        x+=x&-x;
    }
}
int qq(int x){
    x=B_SIZE-x;
    int res=0;
    while(x){
        res+=BIT[x];
        x-=x&-x;
    }
    return res;
}
int main(){
    DRII(n,m);
    REP(i,n){
        DRII(x,y);
        e[en++]=data(x,y,-1);
    }
    REP(i,m){
        DRI(num);
        int last=1;
        while(num--){
            DRI(x);
            if(x-1>=last){
                e[en++]=data(last,x-1,i);
            }
            last=x+1;
        }
        if(last<=(int)1e6){
            e[en++]=data(last,(int)1e6,i);
        }
    }
    sort(e,e+en);
    REP(i,en){
        if(e[i].id==-1){
            insert(e[i].L);
        }
        else{
            an[e[i].id]+=qq(e[i].L);
        }
    }
    REP(i,m){
        printf("%d\n",n-an[i]);
    }
    return 0;
}