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
const int INF = 1e9+7;
const int SIZE = 1e6+10;
VI e[SIZE];
bool used[SIZE];
int dp[SIZE][2],num[SIZE];
void dfs(int x,int lv){
    used[x]=1;
    int r=INF,r2=1;
    int sum=0,mi=INF;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(used[y])continue;
        dfs(y,lv^1);
        r=min(r,num[y]-dp[y][1]);
        mi=min(mi,dp[y][0]);
        num[x]+=num[y];
        r2+=dp[y][1]-1;
        sum+=dp[y][0];
    }
    if(r==INF){
        num[x]=1;
        dp[x][0]=dp[x][1]=1;
    }
    else{
        if(!lv){
            dp[x][1]=num[x]-r;
            dp[x][0]=sum;
        }
        else{
            dp[x][1]=r2;
            dp[x][0]=mi;
        }
    }
}
int main(){
    DRI(n);
    REPP(i,1,n){
        DRII(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    dfs(1,0);
    printf("%d %d\n",dp[1][1],dp[1][0]);
    return 0;
}