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
const int SIZE = 1e6+5;
int x[SIZE],y[SIZE],BIT[SIZE],last[SIZE],an[SIZE];
void ins(int x,int v){
    x=SIZE-x;
    while(x<SIZE){
        BIT[x]+=v;
        x+=x&-x;
    }
}
int qq(int x){
    x=SIZE-x;
    int res=0;
    while(x){
        res+=BIT[x];
        x-=x&-x;
    }
    return res;
}
int BIT2[SIZE];
void ins2(int x,int v){
    while(x<SIZE){
        BIT2[x]+=v;
        x+=x&-x;
    }
}
int qq2(int x){
    int res=0;
    while(x){
        res+=BIT2[x];
        x-=x&-x;
    }
    return res;
}
int main(){
    DRII(n,m);
    bool err=false;
    REPP(i,1,m+1){
        RII(x[i],y[i]);
        if(!last[x[i]]){
            int tmp=qq(1);
            if(tmp>=y[i])err=true;
            else{
                int ll=1;
                int rr=n;
                while(ll<rr){
                    int mm=(ll+rr)>>1;
                    if(mm+tmp-qq2(mm)>=y[i])rr=mm;
                    else ll=mm+1;
                }
                an[ll]=x[i];
                ins2(ll,1);
            }
            ins(i,1);
        }
        else{
            int tmp=qq(last[x[i]]+1);
            if(tmp+1!=y[i])err=true;
            ins(i,1);
            ins(last[x[i]],-1);
        }
        last[x[i]]=i;
    }
    if(err){
        puts("-1");
        return 0;
    }
    int now=1;
    for(int i=1;i<=n;i++){
        if(!an[i]){
            while(last[now])now++;
            an[i]=now++;
        }
    }
    REPP(i,1,n+1){
        if(i!=1)putchar(' ');
        printf("%d",an[i]);
    }
    puts("");
    return 0;
}