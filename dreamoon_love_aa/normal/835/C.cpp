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
const int SIZE = 1e6+10;
int dp[11][111][111];
int get(int lv,int x1,int y1,int x2,int y2){
    x1--;y1--;
    return dp[lv][x2][y2]+dp[lv][x1][y1]-dp[lv][x1][y2]-dp[lv][x2][y1];
}
int main(){
    DRIII(n,q,c);
    c++;
    REP(i,n){
        DRIII(x,y,v);
        REP(j,c){
            dp[j][x][y]+=(v+j)%c;
        }
    }
    REP(k,c){
        REP(i,101)REP(j,101){
            if(i)dp[k][i][j]+=dp[k][i-1][j];
        }
        REP(i,101)REP(j,101){
            if(j)dp[k][i][j]+=dp[k][i][j-1];
        }
    }
    REP(cs,q){
        DRI(t);
        DRII(x1,y1);
        DRII(x2,y2);
        t%=c;
        printf("%d\n",get(t,x1,y1,x2,y2));
    }
    return 0;
}