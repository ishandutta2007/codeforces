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
const int MOD = 2e9+7;
const int SIZE = 1e6+10;
// template end here
int A[SIZE];
int dp[5001][5001];
int main(){
    DRII(n,k);
    REP(i,n){
        RI(A[i+1]);
    }
    sort(A+1,A+n+1);
    int l1=n/k;
    int l2=n/k+1;
    int n2=n-l1*k;
    int n1=k-n2;
    REP(i,n1+1)REP(j,n2+1){
        if(i+j==0)continue;
        dp[i][j]=MOD;
        if(i){
            int lt=(i-1)*l1+j*l2;
            dp[i][j]=min(dp[i][j],dp[i-1][j]+A[lt+l1]-A[lt+1]);
        }
        if(j){
            int lt=i*l1+(j-1)*l2;
            dp[i][j]=min(dp[i][j],dp[i][j-1]+A[lt+l2]-A[lt+1]);
        }
    }
    printf("%d\n",dp[n1][n2]);
    return 0;
}