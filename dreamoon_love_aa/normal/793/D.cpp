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
int dp[82][82][82];
VPII e[82];
bool between(int x,int L,int R){
    if(L>R)swap(L,R);
    return L<x&&x<R;
}
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(y==-1)return;
    if(x==-1||x>y)x=y;
}
int main(){
    DRII(n,K);
    if(K==1)return 0*puts("0");
    DRI(m);
    REP(i,m){
        DRIII(x,y,v);
        e[x].PB(MP(y,v));
    }
    MS1(dp);
    REPP(i,1,n+1){
        dp[1][i][0]=0;
        dp[1][i][n+1]=0;
    }
    REPP(i,1,K){
        REP(j,n+2)REP(k,n+2){
            if(dp[i][j][k]==-1)continue;
            REP(r,SZ(e[j])){
                int y=e[j][r].F;
                int v=e[j][r].S;
                if(between(y,j,k)){
                    mii(dp[i+1][y][j],dp[i][j][k]+v);
                    mii(dp[i+1][y][k],dp[i][j][k]+v);
                }
            }
        }
    }
    int an=-1;
    REP(i,n+2)REP(j,n+2)mii(an,dp[K][i][j]);
    cout<<an;
    return 0;
}