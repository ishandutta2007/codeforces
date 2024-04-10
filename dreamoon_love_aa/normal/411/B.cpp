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
int x[111][111],locked[111],an[111];
int main(){
    DRIII(n,m,k);
    REP(i,n)REP(j,m)RI(x[i][j]);
    REP(i,m){
        vector<int>d[111];
        REP(j,n){
            if(x[j][i]&&!an[j])
                d[x[j][i]].PB(j);
        }
        REPP(i2,1,k+1){
            if(SZ(d[i2])>1)locked[i2]=1;
            if(locked[i2]){
                REP(j,SZ(d[i2]))
                    if(!an[d[i2][j]])an[d[i2][j]]=i+1;
            }
        }
    }
    REP(i,n)printf("%d\n",an[i]);
    return 0;
}