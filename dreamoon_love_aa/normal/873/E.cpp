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
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
PII v[SIZE];
#define FUNC max
const int RMQ_SIZE=2e5+5;
int RMQ_TO[RMQ_SIZE];
struct RMQ{
    PII d[18][RMQ_SIZE];
    void build(int n,PII _a[]){
        REPP(i,2,RMQ_SIZE){
            RMQ_TO[i]=RMQ_TO[i>>1]+1;
        }
        REP(i,n)d[0][i]=_a[i];
        REPP(i,1,18){
            int w=(1<<i)-1;
            int half_w=1<<(i-1);
            for(int j=0;j+w<=n;j++){
                d[i][j]=FUNC(d[i-1][j],d[i-1][j+half_w]);
            }
        }
    }
    PII qq(int L,int R){
        int w=R-L+1;
        int lv=RMQ_TO[w];
        return FUNC(d[lv][L],d[lv][R-(1<<lv)+1]);
    }
}rmq;
int an[SIZE];
int main(){
    DRI(n);
    VPII pp;
    REP(i,n){
        DRI(x);
        pp.PB(MP(x,i));
    }
    sort(ALL(pp),greater<PII>());
    pp.PB(MP(0,-1));
    REP(i,n)v[i]=MP(pp[i].F-pp[i+1].F,i);
    rmq.build(n,v);
    int r1=-1,r2=-1,r3=-1;
    int id1,id2,id3;
    for(int i=1;i<n;i++){
        if(v[i-1].F<r1)continue;
        for(int j=1;i+j<=n;j++){
            if(i*2<j||j*2<i)continue;
            if(MP(v[i-1].F,v[i+j-1].F)<MP(r1,r2))continue;
            int k_mi=(max(i,j)+1)/2;
            int k_ma=min(n-i-j,min(i,j)*2);
            if(k_mi>k_ma)continue;
            PII ret=rmq.qq(i+j+k_mi-1,i+j+k_ma-1);
            if(MP(v[i-1].F,MP(v[i+j-1].F,ret.F))>=MP(r1,MP(r2,r3))){
                r1=v[i-1].F;
                r2=v[i+j-1].F;
                r3=ret.F;
                id1=i;
                id2=i+j;
                id3=ret.S+1;
            }
        }
    }
    REP(i,n){
        if(i<id1)an[pp[i].S]=1;
        else if(i<id2)an[pp[i].S]=2;
        else if(i<id3)an[pp[i].S]=3;
        else an[pp[i].S]=-1;
    }
    REP(i,n)printf("%d%c",an[i]," \n"[i==n-1]);
    return 0;
}