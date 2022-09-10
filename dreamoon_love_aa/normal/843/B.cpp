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
int main(){
    srand(time(NULL));
    DRIII(n,start,x);
    VI d;
    REPP(i,1,n+1)d.PB(i);
    REPP(j,1,n){
        int id=rand()%(j+1);
        if(id!=j)swap(d[j],d[id]);
    }
    int qq=min(n,1000);
    VPII gg;
    REP(i,qq){
        printf("? %d\n",d[i]);
        fflush(stdout);
        DRII(v,nxt);
        gg.PB(MP(v,nxt));
    }
    sort(ALL(gg));
    int it=-1;
    REP(i,SZ(gg)){
        if(gg[i].F<=x){
            if(it==-1||gg[i].F>gg[it].F)it=i;
        }
    }
    if(it!=-1&&gg[it].F==x){
        printf("! %d\n",x);
        return 0;
    }
    if(it!=-1)start=gg[it].S;
    while(1){
        if(start==-1){
            return 0*puts("! -1");
        }
        printf("? %d\n",start);
        fflush(stdout);
        DRII(v,nxt);
        if(v==-1)return 0*puts("! -1");
        if(v>=x){
            printf("! %d\n",v);
            return 0;
        }
        if(nxt==-1){
            puts("! -1");
            return 0;
        }
        start=nxt;
    }
    return 0;
}