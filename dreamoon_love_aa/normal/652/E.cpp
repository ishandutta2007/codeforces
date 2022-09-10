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
VPII e[SIZE];
int a,b,d[SIZE],No,bk[SIZE],dp[SIZE];
void dfs(int x,int lt){
    d[x]=bk[x]=++No;
    if(x==b)dp[x]|=2;
    bool good=0;
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        int v=e[x][i].S;
        if(y==lt)continue;
        if(d[y]){
            bk[x]=min(bk[x],d[y]);
            if(v)dp[x]|=1;
        }
        else{
            dfs(y,x);
            if(bk[y]<=d[x]){
                if(v)dp[x]|=1;
                dp[x]|=dp[y];
                bk[x]=min(bk[x],bk[y]);
            }
            if(dp[y]>=2)good=1;
            if(v&&dp[y]>=2)dp[x]|=1;
        }
    }
    if(good)dp[x]|=2;
    if(dp[x]==3){
        puts("YES");
        exit(0);
    }
}
int main(){
    DRII(n,m);
    REP(i,m){
        DRIII(x,y,v);
        e[x].PB(MP(y,v));
        e[y].PB(MP(x,v));
    }
    RII(a,b);
    dfs(a,a);
    puts("NO");
    return 0;
}