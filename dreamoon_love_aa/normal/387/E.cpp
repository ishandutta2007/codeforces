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
const int SIZE = 1000010;
int a[SIZE],stk[SIZE],sn,ll[SIZE],rr[SIZE],bit[SIZE],pos[SIZE];
bool exist[SIZE];
void ins(int x){
    while(x<SIZE){
        bit[x]++;
        x+=x&-x;
    }
}
int qq(int x){
    int res=0;
    while(x){
        res+=bit[x];
        x-=x&-x;
    }
    return res;
}
int main(){
    DRII(n,m);
    REP(i,n){
        RI(a[i]);
        pos[a[i]]=i;
    }
    REP(i,m){
        DRI(x);
        exist[x]=true;
    }

    sn=0;
    for(int i=0;i<n;i++){
        if(exist[a[i]]){
            while(sn>0&&a[i]<a[stk[sn-1]])sn--;
            stk[sn++]=i;
        }
        else{
            int L=-1,R=sn-1;
            while(L<R){
                int mm=(L+R+1)>>1;
                if(a[stk[mm]]<a[i])L=mm;
                else R=mm-1;
            }
            if(L==-1)ll[a[i]]=0;
            else ll[a[i]]=stk[L]+1;
        }
    }
    
    sn=0;
    for(int i=n-1;i>=0;i--){
        if(exist[a[i]]){
            while(sn>0&&a[i]<a[stk[sn-1]])sn--;
            stk[sn++]=i;
        }
        else{
            int L=-1,R=sn-1;
            while(L<R){
                int mm=(L+R+1)>>1;
                if(a[stk[mm]]<a[i])L=mm;
                else R=mm-1;
            }
            if(L==-1)rr[a[i]]=n-1;
            else rr[a[i]]=stk[L]-1;
        }
    }
    long long an=0;
    REPP(i,1,n+1){
        if(!exist[i]){
            an+=(rr[i]-ll[i]+1)-(qq(rr[i]+1)-qq(ll[i]));
            ins(pos[i]+1);
        }        
    }
    cout<<an<<endl;
    return 0;
}