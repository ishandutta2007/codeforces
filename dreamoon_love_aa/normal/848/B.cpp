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
int n,w,h;
vector<pair<PII,int>> d[SIZE];
PII an[SIZE];
int f(PII x){
    if(!x.F)return  h-x.S;
    return h+x.F;
}
bool cmp(pair<PII,int> x,pair<PII,int> y){
    return f(x.F)<f(y.F);
}
int main(){
    RIII(n,w,h);
    REP(i,n){
        DRIII(g,p,t);
        t=100000-t;
        if(g==1)
            d[p+t].PB(MP(MP(p,0),i));
        else
            d[p+t].PB(MP(MP(0,p),i));
    }
    REP(i,SIZE){
        if(!SZ(d[i]))continue;
        VPII pp;
        REP(j,SZ(d[i])){
            PII me=d[i][j].F;
            if(!me.F)
                pp.PB(MP(w,-me.S));
            else
                pp.PB(MP(me.F,-h));
        }
        sort(ALL(pp));
        sort(ALL(d[i]),cmp);
        REP(j,SZ(d[i])){
            an[d[i][j].S]=MP(pp[j].F,-pp[j].S);
        }
    }
    REP(i,n)printf("%d %d\n",an[i].F,an[i].S);
    return 0;
}