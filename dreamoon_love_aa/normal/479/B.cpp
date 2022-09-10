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

template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
int a[SIZE];
int main(){
    DRII(n,k);
    REP(i,n)RI(a[i]);
    VPII an;
    REP(i,k){
        PII mi=MP(1000000,0),ma=MP(0,0);
        REP(j,n){
            mii(mi,MP(a[j],j));
            maa(ma,MP(a[j],j));
        }
        if(mi.F==ma.F)break;
        a[mi.S]++;
        a[ma.S]--;
        an.PB(MP(ma.S,mi.S));
    }
    int x=0,y=100000;
    REP(i,n){
        x=max(x,a[i]);
        y=min(y,a[i]);
    }
    printf("%d %d\n",x-y,SZ(an));
    REP(i,SZ(an))printf("%d %d\n",an[i].F+1,an[i].S+1);
    return 0;
}