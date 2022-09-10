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
const int SIZE = 1e5+10;
LL dp[64][SIZE][2],an[SIZE][2];
int w[SIZE],f[SIZE],nxt[64][SIZE];
int main(){
    int n;
    LL k;
    cin>>n>>k;
    REP(i,n)RI(f[i]);
    REP(i,n)RI(w[i]);
    int now=0;
    REP(i,n){
        dp[now][i][0]=dp[now][i][1]=w[i];
        nxt[now][i]=f[i];
        f[i]=i;
        an[i][1]=w[i];
    }
    REP(ker,60){
        if(!k)break;
        if(k&1){
            REP(i,n){
                an[i][0]+=dp[now][f[i]][0];
                an[i][1]=min(an[i][1],dp[now][f[i]][1]);
            }
            REP(i,n)f[i]=nxt[now][f[i]];
        }
        REP(i,n){
            dp[now+1][i][0]=dp[now][i][0]+dp[now][nxt[now][i]][0];
            dp[now+1][i][1]=min(dp[now][i][1],dp[now][nxt[now][i]][1]);
        }
        REP(i,n)nxt[now+1][i]=nxt[now][nxt[now][i]];
        k>>=1;
        now++;
    }
    REP(i,n)printf("%I64d %I64d\n",an[i][0],an[i][1]);
    return 0;
}