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
const int SIZE = 1e5+10;
int deg[SIZE],x[SIZE],y[SIZE],u[SIZE],tt;
VI c[SIZE],e[SIZE];
void go(int v){
    u[v]=tt;
    REP(i,SZ(e[v])){
        int v2=e[v][i];
        if(u[v2]==tt)continue;
        if(x[v2]==x[v]||y[v2]==y[v])swap(x[v2],y[v2]);
        go(v2);
    }
}
int main(){
    CASET{
        tt++;
        DRII(n,m);
        REPP(i,1,n+1)c[i].clear();
        REP(i,m){
            e[i].clear();
            RII(x[i],y[i]);
            c[x[i]].PB(i);
            c[y[i]].PB(i);
        }
        int an=0;
        REPP(i,1,n+1){
            if(SZ(c[i])%2==0)an++;
            for(int j=0;j+1<SZ(c[i]);j+=2){
                e[c[i][j]].PB(c[i][j+1]);
                e[c[i][j+1]].PB(c[i][j]);
            }
        }
        REP(i,m){
            if(u[i]!=tt){
                go(i);
            }
        }
        printf("%d\n",an);
        REP(i,m)printf("%d %d\n",x[i],y[i]);
    }
    return 0;
}