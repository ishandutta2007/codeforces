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
const int SIZE = 8e5+10;
int a[SIZE][2];
int d[SIZE],dn,dp[SIZE];
vector<int>from[SIZE];
int main(){
    DRI(n);
    REP(i,n){
        DRII(x,w);
        a[i][0]=x-w;
        a[i][1]=x+w;
        REP(j,2)d[dn++]=a[i][j];
    }
    sort(d,d+dn);
    dn=unique(d,d+dn)-d;
    REP(i,n){
        int me=lower_bound(d,d+dn,a[i][1])-d;
        int ll=lower_bound(d,d+dn,a[i][0])-d;
        from[me].PB(ll);
    }
    int an=0;
    REP(i,dn){
        if(i)dp[i]=dp[i-1];
        REP(j,SZ(from[i])){
            dp[i]=max(dp[i],dp[from[i][j]]+1);
        }
        an=max(an,dp[i]);
    }
    printf("%d\n",an);
    return 0;
}