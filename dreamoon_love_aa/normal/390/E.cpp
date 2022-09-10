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
const int SIZE = 4e6+10;
long long col[SIZE<<2],row[SIZE<<2],row_push[SIZE<<2],col_push[SIZE<<2];
void ins(long long d[],long long push[],int L,int R,int id,int l,int r,long long v){
    if(R<l||L>r)return;
    if(L>=l&&R<=r){
        d[id]+=(R-L+1)*v;
        push[id]+=v;
        return;
    }
    int mm=(L+R)>>1;
    if(push[id]){
        push[id*2]+=push[id];
        push[id*2+1]+=push[id];
        d[id*2]+=(mm-L+1)*push[id];
        d[id*2+1]+=(R-mm)*push[id];
        push[id]=0;
    }
    ins(d,push,L,mm,id*2,l,r,v);
    ins(d,push,mm+1,R,id*2+1,l,r,v);
    d[id]=d[id*2]+d[id*2+1];
}
long long qq(long long d[],long long push[],int L,int R,int id,int l,int r){
    if(R<l||L>r)return 0;
    if(L>=l&&R<=r){
        return d[id];
    }
    int mm=(L+R)>>1;
    if(push[id]){
        push[id*2]+=push[id];
        push[id*2+1]+=push[id];
        d[id*2]+=(mm-L+1)*push[id];
        d[id*2+1]+=(R-mm)*push[id];
        push[id]=0;
    }
    long long an=
    qq(d,push,L,mm,id*2,l,r)+
    qq(d,push,mm+1,R,id*2+1,l,r);
    d[id]=d[id*2]+d[id*2+1];
    return an;
}
int main(){
    DRIII(n,m,w);
    while(w--){
        DRI(ty);
        if(ty==0){
            DRII(x1,y1);
            DRII(x2,y2);
            DRI(v);
            ins(row,row_push,1,n,1,x1,x2,(long long)v*(y2-y1+1));
            ins(col,col_push,1,m,1,y1,y2,(long long)v*(x2-x1+1));
        }
        else{
            DRII(x1,y1);
            DRII(x2,y2);
            long long an=0;
            an+=qq(row,row_push,1,n,1,x1,x2);
            if(y1>1)an-=qq(col,col_push,1,m,1,1,y1-1);
            if(y2<m)an-=qq(col,col_push,1,m,1,y2+1,m);
            cout<<an<<endl;
        }
    }
    return 0;
}