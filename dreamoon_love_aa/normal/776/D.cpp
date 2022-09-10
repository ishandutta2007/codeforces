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
int r[SIZE],flag[SIZE];
VI e[SIZE];
VPII ee[SIZE];
bool f(int x){
    REP(i,SZ(ee[x])){
        int y=ee[x][i].F;
        if(flag[y]==-1){
            flag[y]=flag[x]^r[ee[x][i].S];
            if(!f(y))return 0;
        }
        else if((flag[x]^r[ee[x][i].S])!=flag[y])return 0;
    }
    return 1;
}
int main(){
    MS1(flag);
    DRII(n,m);
    REP(i,n){
        RI(r[i]);
        r[i]^=1;
    }
    REP(i,m){
        DRI(k);
        REP(j,k){
            DRI(x);
            e[x-1].PB(i);
            x--;
        }
    }
    REP(i,n)REP(j,2)ee[e[i][j]].PB(MP(e[i][1^j],i));
    REP(i,m){
        if(flag[i]!=-1)continue;
        flag[i]=0;
        if(!f(i))return 0*puts("NO");
    }
    return 0*puts("YES");
}