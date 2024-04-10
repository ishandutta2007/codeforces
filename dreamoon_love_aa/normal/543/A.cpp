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
const int SIZE = 1e6+10;
// template end here
int a[SIZE];
int dp[501][501];
int main(){
    DRII(n,m);
    DRII(b,mod);
    REPP(i,1,n+1)RI(a[i]);
    dp[0][0]=1%mod;
    REPP(i,1,n+1){
        for(int j=1;j<=m;j++)
            for(int k=0;k<=b;k++){
                if(k>=a[i]){
                    dp[j][k]+=dp[j-1][k-a[i]];
                    if(dp[j][k]>=mod)dp[j][k]-=mod;
                }
            }
    }
    int an=0;
    REP(i,b+1){
        an+=dp[m][i];
        if(an>=mod)an-=mod;
    }
    printf("%d\n",an);
    return 0;
}