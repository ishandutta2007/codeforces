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
const int SIZE = 1<<20;
int a[SIZE],b[SIZE];
long long v[20][2];
void dfs(int L,int R,int lv){
    if(L==R)return;
    int mm=(L+R)>>1;
    dfs(L,mm,lv-1);
    dfs(mm+1,R,lv-1);
    int l1=L,l2=mm+1,it=L;
    long long small=0;
    while(l1<=mm&&l2<=R){
        if(a[l1]<a[l2]){
            b[it++]=a[l1++];
        }
        else{
            b[it++]=a[l2++];
            small+=l1-L;
        }
    }
    while(l1<=mm){
        b[it++]=a[l1++];
    }
    while(l2<=R){
        b[it++]=a[l2++];
        small+=l1-L;
    }
    v[lv][1]+=small;
    long long big=0;
    l1=L,l2=mm+1,it=L;
    while(l1<=mm&&l2<=R){
        if(a[l1]<=a[l2]){
            b[it++]=a[l1++];
            big+=l2-mm-1;
        }
        else{
            b[it++]=a[l2++];
            small+=l1-L;
        }
    }
    while(l1<=mm){
        b[it++]=a[l1++];
        big+=l2-mm-1;
    }
    while(l2<=R){
        b[it++]=a[l2++];
    }
    v[lv][0]+=big;
    for(int i=L;i<=R;i++)a[i]=b[i];
}
long long f(int x,int n){
    long long res=0;
    int ha=0;
    for(int i=n-1;i>=0;i--){
        ha^=(x>>i)&1;
        res+=v[i][ha];
    }
    return res;
}
int main(){
    DRI(n);
    REP(i,(1<<n)){
        RI(a[i]);
    }
    dfs(0,(1<<n)-1,n-1);
    DRI(m);
    int now=0;
    while(m--){
        DRI(x);
        if(x)now^=(1<<(x-1));
        if(n)printf("%I64d\n",f(now,n));
        else puts("0");
    }
    return 0;
}