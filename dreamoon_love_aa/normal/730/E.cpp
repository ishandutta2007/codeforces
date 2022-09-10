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
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
PII a[SIZE];
int d[SIZE];
int main(){
    DRI(n);
    VPII gg[2];
    REP(i,n){
        a[i].S=-i;
        RII(a[i].F,d[i]);
        if(d[i]>0)gg[0].PB(a[i]);
        else if(d[i]<0)gg[1].PB(a[i]);
    }
    sort(ALL(gg[0]));
    sort(ALL(gg[1]));
    reverse(ALL(gg[1]));
    int an=0;
    REP(i,SZ(gg[0])){
        int id=-gg[0][i].S;
        REP(j,n){
            if(j==id)continue;
            if((a[id]<a[j])!=(MP(a[id].F+d[id],-id)<a[j]))an++;
        }
        a[id].F+=d[id];
    }
    REP(i,SZ(gg[1])){
        int id=-gg[1][i].S;
        REP(j,n){
            if(j==id)continue;
            if((a[id]<a[j])!=(MP(a[id].F+d[id],-id)<a[j]))an++;
        }
        a[id].F+=d[id];
    }
    printf("%d\n",an);

    return 0;
}