#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
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
typedef long long LL;
using namespace std;
const int SIZE = 4e5+1;
int a[SIZE],n,m;
LL sum[SIZE];
int ma[SIZE];
void add_number(int L,int R,int id,int x,int v){
    if(L==R){
        ma[id]=sum[id]=a[x]=v;
        return;
    }
    int mm=(L+R)>>1;
    if(x<=mm)add_number(L,mm,id<<1,x,v);
    else add_number(mm+1,R,(id<<1)|1,x,v);
    sum[id]=sum[id*2]+sum[id*2+1];
    ma[id]=max(ma[id*2],ma[id*2+1]);
}
int MOD;
void mymod(int L,int R,int id,int lll,int rr){
    if(R<lll||L>rr)return;
    if(ma[id]<MOD)return;
    if(L==R){
        ma[id]=sum[id]=a[L]=a[L]%MOD;
        return;
    }
    int mm=(L+R)>>1;
    mymod(L,mm,id<<1,lll,rr);
    mymod(mm+1,R,(id<<1)|1,lll,rr);
    sum[id]=sum[id*2]+sum[id*2+1];
    ma[id]=max(ma[id*2],ma[id*2+1]);
}

LL qq(int L,int R,int id,int lll,int rr){
    if(R<lll||L>rr)return 0;
    if(L>=lll&&R<=rr){
        return sum[id];
    }
    int mm=(L+R)>>1;
    return qq(L,mm,id<<1,lll,rr)+qq(mm+1,R,(id<<1)|1,lll,rr);
}
int main(){
    RII(n,m);
    REPP(i,1,n+1){
        DRI(x);
        add_number(1,n,1,i,x);
    }
    while(m--){
        DRI(ty);
        if(ty==1){
            DRII(L,R);
            printf("%I64d\n",qq(1,n,1,L,R));
        }
        else if(ty==2){
            DRIII(L,R,x);
            MOD=x;
            mymod(1,n,1,L,R);
        }
        else{
            DRII(k,x);
            add_number(1,n,1,k,x);
        }
    }
    return 0;
}