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
const LL INF = 1e12;
const int SIZE = 1e6+10;
LL BIT[2][SIZE];
void ins(LL bit[],int x,LL v){
    for(;x;x-=x&-x)bit[x]+=v;
}
LL qq(LL bit[],int x){
    LL res=0;
    for(;x<SIZE;x+=x&-x)res+=bit[x];
    return res;
}
VPII data[2][SIZE];
int main(){
    DRIII(N,M,K);
    REP(i,M){
        DRII(d,f);DRII(t,c);
        if(!f){
            data[1][t].PB(MP(d,c));
        }
        else{
            data[0][f].PB(MP(d,c));
        }
    }
    REPP(i,1,N+1){
        if(!SZ(data[0][i])||!SZ(data[1][i]))return 0*puts("-1");
        REP(j,2)sort(ALL(data[j][i]));
        int lt=1;
        LL mi=INF;
        REP(j,SZ(data[0][i])){
            ins(BIT[0],lt-1,-mi);
            ins(BIT[0],data[0][i][j].F-1,mi);
            mi=min(mi,(LL)data[0][i][j].S);
            lt=data[0][i][j].F;
        }
        ins(BIT[0],lt-1,-mi);
        ins(BIT[0],SIZE-1,mi);
        lt=SIZE-1;
        mi=INF;
        for(int j=SZ(data[1][i])-1;j>=0;j--){
            while(j&&data[1][i][j].F==data[1][i][j-1].F)j--;
            ins(BIT[1],(SIZE-lt)-1,-mi);
            ins(BIT[1],(SIZE-data[1][i][j].F)-1,mi);
            mi=min(mi,(LL)data[1][i][j].S);
            lt=data[1][i][j].F;
        }
        ins(BIT[1],(SIZE-lt)-1,-mi);
        ins(BIT[1],SIZE-1,mi);
    }
    LL ans=INF;
    for(int i=2;i+K<SIZE;i++){
        LL v=qq(BIT[0],i-1)+qq(BIT[1],(SIZE-(i+K)));
        if(v<ans){
            ans=v;
        }
    }
    if(ans>=INF)puts("-1");
    else printf("%I64d\n",ans);
    return 0;
}