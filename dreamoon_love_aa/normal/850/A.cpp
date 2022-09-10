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
int p[SIZE][5];
int main(){
    DRI(n);
    REPP(i,1,n+1){
        REP(j,5)RI(p[i][j]);
    }
    VI an;
    REPP(i,1,n+1){
        bool fail=0;
        REPP(j,1,n+1){
            if(j==i)continue;
            int d1[5];
            REP(r,5)d1[r]=p[j][r]-p[i][r];
            REPP(k,1,j){
                int d2[5]={};
                int v=0;
                REP(r,5)v+=(p[k][r]-p[i][r])*d1[r];
                if(v>0){
                    fail=1;
                    break;
                }
            }
            if(fail)break;
        }
        if(!fail)an.PB(i);
    }
    printf("%d\n",SZ(an));
    REP(i,SZ(an))printf("%d%c",an[i]," \n"[i==SZ(an)-1]);
    return 0;
}