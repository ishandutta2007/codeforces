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
const int SIZE = 255;
char s[SIZE][SIZE];
int dp[2][1<<15][2][2];
void ADD(int &x,int v){
    x+=v;
    if(x>=MOD)x-=MOD;
}
int main(){
    DRII(n,m);
    REP(i,n)RS(s[i]);
    if(n<m){
        swap(n,m);
        REP(i,SIZE)REP(j,i)swap(s[i][j],s[j][i]);
    }
    int BB=1<<m;
    int now=0,nxt=1;
    int mask=BB-1;
    dp[now][0][0][0]=1;
    REP(i,n){
        REP(j,m){
            MS0(dp[nxt]);
            if(!j){
                REP(k,BB)REP(k2,2){
                    ADD(dp[now][k][0][k2],dp[now][k][1][k2]);
                    dp[now][k][1][k2]=0;
                }
            }
            if(s[i][j]=='.'){
                REP(k,BB){
                    REP(k2,2){
                        if(((k>>j)&1)|k2){
                            REP(k3,2){
                                ADD(dp[nxt][k][k2][k3],dp[now][k][k2][k3]);
                                ADD(dp[nxt][k|(1<<j)][k2|1][k3],dp[now][k][k2][k3]);
                            }
                        }
                        else{
                            REP(k3,2){
                                if(!k3)ADD(dp[nxt][k][k2][k3+1],dp[now][k][k2][k3]);
                                ADD(dp[nxt][k|(1<<j)][k2|1][k3],dp[now][k][k2][k3]);
                            }
                        }
                    }
                }
            }
            else{
                REP(k,BB){
                    REP(k2,2){
                        REP(k3,2){
                            ADD(dp[nxt][k&(mask^(1<<j))][0][k3],dp[now][k][k2][k3]);
                        }
                    }
                }
            }
            swap(now,nxt);
        }
    }
    int an=0;
    REP(i,BB)REP(j,2)REP(k,2)ADD(an,dp[now][i][j][k]);
    return 0*printf("%d\n",an);
}