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
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
double dp[201][30][30];
int a[33];
int main(){
    DRII(n,K);
    REP(i,n)RI(a[i]);
    REP(i,n)REPP(j,i+1,n){
        if(a[i]<a[j])dp[0][i][j]=1;
        else dp[0][j][i]=1;
    }
    int qq=n*(n+1)/2;
    REP(i,K){
        REP(j,n)REP(k,n){
            if(j==k)continue;
            REP(j2,n)REPP(k2,j2,n){
                int jj=j,kk=k;
                if(j2<=jj&&k2>=jj)jj=k2-(jj-j2);
                if(j2<=kk&&k2>=kk)kk=k2-(kk-j2);
                dp[i+1][jj][kk]+=dp[i][j][k]/qq;
            }
        }
    }
    double an=0;
    REP(i,n)REPP(j,i+1,n)an+=dp[K][j][i];
    printf("%.12f\n",an);
    return 0;
}