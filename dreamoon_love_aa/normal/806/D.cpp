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
const int SIZE = 2017;
LL INF = 1e14;
LL a[SIZE][SIZE];
LL an[SIZE];
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
int main(){
    DRI(n);
    REP(i,n)an[i]=a[i][i]=INF;
    LL mi=INF;
    REP(i,n)REPP(j,i+1,n){
        RI(a[i][j]);
        mi=min(mi,(LL)a[i][j]);
        a[j][i]=a[i][j];
    }
    REP(i,n)REP(j,n)a[i][j]-=mi;
    vector<pair<int,PII> >e;
    REP(i,n)REPP(j,i+1,n)e.PB(MP(a[i][j],MP(i,j)));
    sort(ALL(e));
    REP(i,SZ(e)){
        LL v=e[i].F;
        int x=e[i].S.F;
        int y=e[i].S.S;
        mii(an[x],v*2);
        mii(an[y],v*2);
        mii(an[x],an[y]+v);
        mii(an[y],an[x]+v);
    }
    REP(i,n)printf("%I64d\n",an[i]+mi*(n-1));
    return 0;
}