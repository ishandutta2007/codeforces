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
int dp[1001][1001][11][2];
char s[1111],t[1111];
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
int main(){
    DRIII(n,m,K);
    RS(s+1);
    RS(t+1);
    REP(i,1001)REP(r,1001)REP(j,K+1)dp[r][i][j][1]=-MOD;
    REPP(i,1,n+1)
        REPP(j,1,m+1){
            REP(k,K+1){
                maa(dp[i][j][k][0],dp[i][j-1][k][0]);
                maa(dp[i][j][k][0],dp[i][j-1][k][1]);
                maa(dp[i][j][k][0],dp[i-1][j][k][0]);
                maa(dp[i][j][k][0],dp[i-1][j][k][1]);
                maa(dp[i][j][k][0],dp[i-1][j-1][k][0]);
                maa(dp[i][j][k][0],dp[i-1][j-1][k][1]);
                if(s[i]==t[j]){
                    maa(dp[i][j][k][1],dp[i-1][j-1][k][1]+1);
                    if(k)
                        maa(dp[i][j][k][1],dp[i-1][j-1][k-1][0]+1);
                }
                else{
                    dp[i][j][k][1]=-MOD;
                }
            }
        }
    int an=0;
    REP(i,K+1)REP(j,2)maa(an,dp[n][m][i][j]);
    cout<<an;
    return 0;
}