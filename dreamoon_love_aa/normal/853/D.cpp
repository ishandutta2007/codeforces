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
const int SIZE = 251;
int dp[2][SIZE];
int mii(int& x,int v){
    if(x==-1||x>v)x=v;
}
int main(){
    DRI(n);
    int now=0,nxt=1;
    MS1(dp);
    dp[0][0]=0;
    REP(i,n){
        DRI(x);x/=100;
        MS1(dp[nxt]);
        REP(j,SIZE){
            if(dp[now][j]==-1)continue;
            if(j+x/10<SIZE)mii(dp[nxt][j+x/10],dp[now][j]+x);
            mii(dp[nxt][max(j-x,0)],dp[now][j]+max(0,x-j));
        }
        swap(now,nxt);
    }
    int an=-1;
    REP(i,SIZE){
        if(dp[now][i]!=-1)mii(an,dp[now][i]);
    }
    return 0*printf("%d\n",an*100);
}