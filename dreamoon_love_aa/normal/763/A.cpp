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
int col[SIZE],cnt[SIZE];
PII dp[SIZE];
VI e[SIZE];
int n;
void dfs(int x,int lt){
    dp[x]=MP(1,col[x]);
    VPII pp;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(y==lt)continue;
        dfs(y,x);
        if(dp[y].S!=dp[x].S)dp[x].S=0;
        dp[x].F+=dp[y].F;
        if(dp[y].S)pp.PB(dp[y]);
    }
    cnt[col[x]]--;
    int r=n-1;
    REP(i,SZ(pp)){
        cnt[pp[i].S]-=pp[i].F;
        r-=pp[i].F;
    }
    if(cnt[col[lt]]==r){
        puts("YES");
        printf("%d\n",x);
        exit(0);
    }
    cnt[col[x]]++;
    REP(i,SZ(pp)){
        cnt[pp[i].S]+=pp[i].F;
    }
}
int main(){
    RI(n);
    REPP(i,1,n){
        DRII(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    REPP(i,1,n+1){
        RI(col[i]);
        cnt[col[i]]++;
    }
    dfs(1,1);
    return 0*puts("NO");
}