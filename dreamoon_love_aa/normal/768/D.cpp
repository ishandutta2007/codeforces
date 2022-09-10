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
int ans[1001];
double dp[2][7275],ret[7275];
int k;
int main(){
    int q;
    RII(k,q);
    ans[0]=k;
    int now=0,nxt=1;
    dp[now][1]=1;
    ret[1]=dp[now][k];
    REPP(i,2,7275){
        MS0(dp[nxt]);
        for(int j=1;j<=i&&j<=k;j++){
            dp[nxt][j]=dp[now][j]*j/k+dp[now][j-1]*(k-(j-1))/k;
        }
        swap(now,nxt);
        ret[i]=dp[now][k];
    }
    now=1;
    REPP(i,k,7275){
        while(now<=1000&&ret[i]>=(now-1e-7)/2000){
            ans[now]=i;
            now++;
        }
    }
    REP(i,q){
        DRI(x);
        printf("%d\n",ans[x]);
    }
    return 0;
}