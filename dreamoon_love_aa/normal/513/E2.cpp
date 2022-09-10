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
const int INF = 1e9+7;
const int SIZE = 30001;
int a[SIZE];
int sum[SIZE];
int dp[201][2][2];
int pre[2]={-1,1};
int pro[2]={2,-2};
int nxt[2]={-1,1};
int back_mi[SIZE],back_ma[SIZE];
int main(){
    DRII(N,K);
    REP(i,N)RI(a[i+1]);
    REPP(i,1,N+1)sum[i]=sum[i-1]+a[i];
    back_mi[N]=back_ma[N]=sum[N];
    for(int i=N-1;i>=0;i--){
        back_ma[i]=max(back_ma[i+1],sum[i]);
        back_mi[i]=min(back_mi[i+1],sum[i]);
    }
    REP(i,K)REP(j,2)REP(k,2)dp[i][j][k]=-INF;
    int an=0;
    int mi=0,ma=0;
    REPP(i,1,N){
        REP(k1,2)REP(k2,2){
            if(dp[K-2][k1][k2]!=-INF)an=max(an,dp[K-2][k1][k2]+sum[i]*(nxt[k1]+pro[k2])+max(back_ma[i+1]*nxt[k2],back_mi[i+1]*nxt[k2]));
        }
        for(int j=K-2;j>0;j--){
            REP(k1,2)REP(k2,2)if(dp[j][k1][k2]!=-INF)REP(k3,2)dp[j+1][k2][k3]=max(dp[j+1][k2][k3],dp[j][k1][k2]+sum[i]*(pre[k1]+pro[k2]+nxt[k3]));
        }
        if(K==2){
            REP(j,2){
                an=max(an,max(mi*pre[j],ma*pre[j])+sum[i]*pro[j]+max(back_mi[i+1]*nxt[j],back_ma[i+1]*nxt[j]));
            }
        }
        REP(k1,2)REP(k2,2){
            dp[1][k1][k2]=max(dp[1][k1][k2],sum[i]*(pro[k1]+nxt[k2])+max(mi*nxt[k1],ma*nxt[k1]));
        }
        mi=min(mi,sum[i]);
        ma=max(ma,sum[i]);
    }
    printf("%d\n",an);
    return 0;
}