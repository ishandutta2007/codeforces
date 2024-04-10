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
int a[501][501];
int main(){
    DRII(n,m);
    REP(i,n)REP(j,m)RI(a[i][j]);
    int mi=555;
    REP(i,m){
        mi=min(mi,a[0][i]);
    }
    VPII res;
    REP(i,m){
        int r=a[0][i]-mi;
        REP(j,r)res.PB(MP(1,i+1));
        REP(j,n)a[j][i]-=r;
    }
    mi=555;
    REP(i,n)mi=min(mi,a[i][0]);
    REP(i,n){
        int r=a[i][0]-mi;
        REP(j,r)res.PB(MP(0,i+1));
        REP(j,m)a[i][j]-=r;
    }
    if(n<=m){
        REP(i,n){
            if(a[i][0]<0){
                return 0*puts("-1");
            }
            REP(j,a[i][0])res.PB(MP(0,i+1));
            int r=a[i][0];
            REP(j,m)a[i][j]-=r;
        }
    }
    else{
        REP(i,m){
            if(a[0][i]<0){
                return 0*puts("-1");
            }
            REP(j,a[0][i])res.PB(MP(1,i+1));
            int r=a[0][i];
            REP(j,n)a[j][i]-=r;
        }
    }
    REP(i,n)REP(j,m){
        if(a[i][j]){
            return 0*puts("-1");
        }
    }
    printf("%d\n",SZ(res));
    REP(i,SZ(res))printf("%s %d\n",res[i].F?"col":"row",res[i].S);
    return 0;
}