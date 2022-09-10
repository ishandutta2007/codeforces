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
int a[3][SIZE];
int dp[SIZE][2];
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
    REP(i,3)REP(j,n)RI(a[i][j]);
    if(n==1)printf("%d\n",a[0][0]);
    else if(n==2){
        printf("%d\n",max(a[0][0]+a[1][1],a[1][0]+a[0][1]));
    }
    else{
        dp[1][0]=a[1][0];
        dp[1][1]=a[0][0];
        REPP(i,2,n){
            maa(dp[i][0],dp[i-1][0]+a[1][i-1]);
            maa(dp[i][0],dp[i-1][1]+a[2][i-1]);
            maa(dp[i][1],dp[i-1][0]+a[0][i-1]);
            maa(dp[i][1],dp[i-1][1]+a[1][i-1]);
        }
        int an=max(dp[n-1][0]+a[0][n-1],dp[n-1][1]+a[1][n-1]);
        printf("%d\n",an);
    }
    return 0;
}