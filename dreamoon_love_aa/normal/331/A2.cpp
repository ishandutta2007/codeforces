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
#define SIZE 300010
struct data{
    int v,pos;
    data(int _v=0,int _pos=0){v=_v;pos=_pos;}
    bool operator<(const data& b)const{return v<b.v||(v==b.v&&pos<b.pos);}
}d[SIZE];
int a[SIZE],dn;
long long dp[SIZE];
long long get(int ll,int rr){
    if(ll>rr)return 0;
    return dp[rr]-dp[ll-1];
}
int main(){
    DRI(n);
    REPP(i,1,n+1){
        RI(a[i]);
        d[dn++]=data(a[i],i);
    }
    REPP(i,1,n+1){
        if(a[i]>0)dp[i]=a[i]+dp[i-1];
        else dp[i]=dp[i-1];
    }
    sort(d,d+dn);
    int k,ll,rr;
    long long ma=-2000001000;
    for(int i=0;i<dn;i=k){
        for(k=i+1;k<dn&&d[k].v==d[i].v;k++);
        if(i+1!=k){
            if(d[i].v*2+get(d[i].pos+1,d[k-1].pos-1)>ma){
                ma=d[i].v*2+get(d[i].pos+1,d[k-1].pos-1);
                ll=d[i].pos;rr=d[k-1].pos;
            }
        }
    }
    vector<int>res;
    REPP(i,1,ll)res.PB(i);
    REPP(i,ll+1,rr)if(a[i]<0)res.PB(i);
    REPP(i,rr+1,n+1)res.PB(i);
    printf("%lld %d\n",ma,SZ(res));
    REP(i,SZ(res)){
        if(i)printf(" ");
        printf("%d",res[i]);
    }
    puts("");
    return 0;
}