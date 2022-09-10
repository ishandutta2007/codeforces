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
#define F first
#define S second
typedef long long LL;
using namespace std;
const int SIZE = 1e5+5;
vector<int>e[SIZE];
int col[SIZE];
int dp[SIZE][2];
const int MOD = 1e9+7;
void dfs(int x){
    LL tmp[2];
    dp[x][col[x]]=1;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        dfs(y);
        MS0(tmp);
        tmp[1]=(LL)dp[x][1]*(dp[y][0]+dp[y][1])%MOD;
        tmp[1]+=(LL)dp[x][0]*dp[y][1]%MOD;
        tmp[1]%=MOD;
        tmp[0]=(LL)dp[x][0]*(dp[y][0]+dp[y][1])%MOD;
        REP(j,2)dp[x][j]=tmp[j];
    }
}
int main(){
    DRI(n);
    REPP(i,1,n){
        DRI(x);
        e[x].PB(i);
    }
    REP(i,n)RI(col[i]);
    dfs(0);
    cout<<dp[0][1]<<endl;
    return 0;
}