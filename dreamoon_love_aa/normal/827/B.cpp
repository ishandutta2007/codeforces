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
    DRII(n,k);
    VPII d;
    REPP(i,1,k+1){
        d.PB(MP(i,0));
    }
    VPII e;
    int it=0;
    REPP(i,k+1,n){
        e.PB(MP(d[it].F,i));
        d[it++]=MP(i,d[it].S+1);
        if(it==SZ(d))it=0;
    }
    VI v;
    REP(i,SZ(d)){
        v.PB(d[i].S);
        e.PB(MP(n,d[i].F));
    }
    sort(ALL(v));
    printf("%d\n",v.back()+v[SZ(v)-2]+2);
    REP(i,SZ(e))printf("%d %d\n",e[i].F,e[i].S);
    return 0;
}