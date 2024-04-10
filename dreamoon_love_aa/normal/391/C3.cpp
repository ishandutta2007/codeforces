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
struct data{
    int p,e;
    bool operator<(const data& b)const{
        return e<b.e||(e==b.e&&p>b.p);
    }
}a[200010];
int yo[200010],yon;
void fresh(long long& x,long long v){
    if(x==-1||x>v)x=v;
}
int err[2][200010];
int main(){
    DRII(n,k);
    int win=n+1-k;
    REP(i,n){
        scanf("%d%d",&a[i].p,&a[i].e);
        yo[yon++]=a[i].p;
    }
    if(win==0){
        puts("0");
        return 0;
    }
    sort(yo,yo+yon);
    sort(a,a+n);
    long long an=-1;
    int low=0,st=200004;
    REPP(i,1,200001){
        while(low<n&&yo[low]<=i)low++;
        if(low>=win){
            st=i;
            break;
        }
    }
    for(int i=0;i<20;i++,st++){
        if(st<1)continue;
        if(st>n)break;
        long long v=0;
        int ha=0;
        int en1=0,en2=0;
        REP(j,st){
            v+=a[j].e;
            if(a[j].p<=st)ha++;
            if(a[j].p<=st-2||a[j].p>st)err[0][en1++]=a[j].e;
        }
        REPP(j,st,n){
            if(a[j].p<=st-2)ha++;
            else if(a[j].p<=st){
                err[1][en2++]=a[j].e;
            }
        }
        if(ha+min(en1,en2)<win)continue;
        REP(j,win-ha)v+=err[1][j]-err[0][en1-1-j];
        fresh(an,v);
    }
    cout<<an<<endl;
    return 0;
}