#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%I64d", &(X))
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
const LL INF = 2e18;
const int SIZE = 1e6+10;
LL a[SIZE],b[SIZE];
VPII e[SIZE];
LL dfs(int x){
    LL me=b[x]-a[x];
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        LL ev=e[x][i].S;
        LL v=dfs(y);
        if(v>=0)me+=v;
        else{
            v=-v;
            if(v>INF/ev){
                me=-INF;
            }
            else{
                me-=v*ev;
                me=max(me,-INF);
            }
        }
    }
    return me;
}
int main(){
    DRI(n);
    REPP(i,1,n+1)RI(b[i]);
    REPP(i,1,n+1)RI(a[i]);
    REPP(i,2,n+1){
        DRII(x,v);
        e[x].PB(MP(i,v));
    }
    if(dfs(1)>=0)puts("YES");
    else puts("NO");
    return 0;
}