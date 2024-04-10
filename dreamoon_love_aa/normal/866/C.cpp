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
const int SIZE = 55;
int F[SIZE],S[SIZE],P[SIZE];
long double p[SIZE];
long double dp[SIZE][5001];
int sum[SIZE];
int main(){
    DRII(N,R);
    long double ll=0,rr=1e9;
    REP(i,N){
        RIII(F[i],S[i],P[i]);
        ll+=F[i];
        p[i]=(long double)P[i]*0.01;
    }
    REP(k,150){
        long double v=(ll+rr)*0.5;
        for(int i=N-1;i>=0;i--){
            REP(j,R+1){
                dp[i][j]=0;
                if(j+F[i]>R)dp[i][j]+=(F[i]+v)*p[i];
                else dp[i][j]+=(min(v,dp[i+1][j+F[i]])+F[i])*p[i];
                if(j+S[i]>R)dp[i][j]+=(S[i]+v)*(1-p[i]);
                else dp[i][j]+=(min(v,dp[i+1][j+S[i]])+S[i])*(1-p[i]);
            }
        }
        if(dp[0][0]<v)rr=v;
        else ll=v;
    }
    printf("%.15f\n",(double)((ll+rr)*0.5));
    return 0;
}