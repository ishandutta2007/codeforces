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
int col[SIZE];
vector<pair<int,int> >e[SIZE];
int dp[SIZE][2],far[SIZE];
void dfs1(int x,int lt){
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        if(y==lt)continue;
        dfs1(y,x);
        if(dp[y][0]+e[x][i].S>dp[x][0]){
            dp[x][1]=dp[x][0];
            dp[x][0]=dp[y][0]+e[x][i].S;
        }
        else if(dp[y][0]+e[x][i].S>dp[x][1]){
            dp[x][1]=dp[y][0]+e[x][i].S;
        }
    }
}
void dfs2(int x,int lt,int v){
    far[x]=max(v,dp[x][0]);
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        if(y==lt)continue;
        if(dp[y][0]+e[x][i].S==dp[x][0])dfs2(y,x,max(v,dp[x][1])+e[x][i].S);
        else dfs2(y,x,max(v,dp[x][0])+e[x][i].S);
    }
}
void add(int x,int y,int v){
    e[x].PB(MP(y,v));
    e[y].PB(MP(x,v));
}
int main(){
    DRI(n);
    REPP(i,1,n+1)RI(col[i]);
    REPP(i,1,n){
        DRII(x,y);
        add(x,y,(col[x]==col[y])?0:1);
    }
    dfs1(1,1);
    dfs2(1,1,0);
    int an=far[n];
    REPP(i,1,n)an=min(an,far[i]);
    cout<<an<<endl;
    return 0;
}