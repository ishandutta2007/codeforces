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
double p[20][20];
double dp[1<<18][18];
vector<pair<double,int> >pp;
double an;
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
    REP(i,n)REP(j,n){
        scanf("%lf",&p[i][j]);
    }
    int st=0;
    REPP(i,1,1<<n){
        if(!(i&(i-1))){
            dp[i][st++]=(i==1);
        }
        REP(j,n){
            if(!((i>>j)&1))continue;
            REP(k,n){
                if(!((i>>k)&1))continue;
                maa(dp[i][j],dp[i^(1<<j)][k]*p[k][j]+
                             dp[i^(1<<k)][j]*p[j][k]);
            }
        }
    }
    double an=0;
    REP(i,n)an=max(an,dp[(1<<n)-1][i]);
    printf("%.12f\n",an);
    return 0;
}