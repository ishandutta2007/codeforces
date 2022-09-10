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
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
int d[3][SIZE];
LL dp[3][SIZE];
int main(){
    DRI(n);
    REP(i,3)REPP(j,1,n+1)RI(d[i][j]);
    REP(i,3)REP(j,n+1)dp[i][j]=-1e18;
    dp[0][0]=0;
    REP(i,n){
        maa(dp[0][i+1],dp[0][i]+d[0][i+1]);
        maa(dp[1][i+1],dp[0][i]+d[0][i+1]+d[1][i+1]);
        maa(dp[2][i+1],dp[0][i]+d[0][i+1]+d[1][i+1]+d[2][i+1]);

        maa(dp[0][i+1],dp[1][i]+d[0][i+1]+d[1][i+1]);
        maa(dp[1][i+1],dp[1][i]+d[1][i+1]);
        maa(dp[2][i+1],dp[1][i]+d[1][i+1]+d[2][i+1]);

        maa(dp[0][i+1],dp[2][i]+d[0][i+1]+d[1][i+1]+d[2][i+1]);
        maa(dp[1][i+1],dp[2][i]+d[1][i+1]+d[2][i+1]);
        maa(dp[2][i+1],dp[2][i]+d[2][i+1]);

        maa(dp[0][i+2],dp[2][i]+d[0][i+1]+d[1][i+1]+d[2][i+1]+d[0][i+2]+d[1][i+2]+d[2][i+2]);
        maa(dp[2][i+2],dp[0][i]+d[0][i+1]+d[1][i+1]+d[2][i+1]+d[0][i+2]+d[1][i+2]+d[2][i+2]);
    }
    cout<<dp[2][n];
    return 0;
}