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
vector<int>lv[SIZE];
void err(){puts("-1");exit(0);}
int d[SIZE],deg[SIZE];
int main(){
    DRII(n,k);
    REP(i,n)RI(d[i+1]);
    int ma=0;
    REPP(i,1,n+1){
        ma=max(ma,d[i]);
        lv[d[i]].PB(i);
    }
    if(SZ(lv[0])!=1)err();
    VPII e;
    REPP(i,1,ma+1){
        if(!SZ(lv[i]))err();
        REP(j,SZ(lv[i])){
            int x=lv[i-1][j%SZ(lv[i-1])];
            int y=lv[i][j];
            e.PB(MP(x,y));
            deg[x]++;
            deg[y]++;
            if(deg[x]>k||deg[y]>k)err();
        }
    }
    printf("%d\n",SZ(e));
    REP(i,SZ(e))printf("%d %d\n",e[i].F,e[i].S);
    return 0;
}