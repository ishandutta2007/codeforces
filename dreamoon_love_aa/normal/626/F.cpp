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
int a[222];
int dp[201][102][1002];
void ADD(int &x,LL v){
    x=(x+v)%MOD;
}
int main(){
    DRII(N,K);
    int mm=N/2;
    REP(i,N)RI(a[i]);
    sort(a,a+N);
    dp[0][1][0]=dp[0][0][0]=1;
    REPP(i,1,N){
        REP(j,mm+1){
            REP(k,K+1){
                if(!dp[i-1][j][k])continue;
                if(k+j*(a[i]-a[i-1])<=K)ADD(dp[i][j][k+j*(a[i]-a[i-1])],dp[i-1][j][k]*(j+1LL));                 //single or med
                if(k+j*(a[i]-a[i-1])<=K)ADD(dp[i][j+1][k+j*(a[i]-a[i-1])],dp[i-1][j][k]);               //start
                if(k+j*(a[i]-a[i-1])<=K&&j)ADD(dp[i][j-1][k+j*(a[i]-a[i-1])],dp[i-1][j][k]*(LL)j);               //end

            }
        }
    }
    int an=0;
    REP(j,K+1)ADD(an,dp[N-1][0][j]);
    cout<<an<<endl;
    return 0;
}