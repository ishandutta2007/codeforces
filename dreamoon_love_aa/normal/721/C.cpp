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
int INF;
const int SIZE = 5010;
VPII e[SIZE];
int n,m,T;
int dp[SIZE][SIZE];
bool used[SIZE];
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
void dfs(int x){
    if(used[x])return;
    used[x]=1;
    REPP(i,1,n+1)dp[x][i]=INF;
    if(x==n){
        dp[x][1]=0;
        return;
    }
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        dfs(y);
        REPP(j,1,n){
            mii(dp[x][j+1],dp[y][j]+e[x][i].S);
        }
    }
}
void track(int x,int lv){
    printf("%d ",x);
    if(x==n)return;
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        if(dp[y][lv-1]+e[x][i].S==dp[x][lv]){
            track(y,lv-1);
            return;
        }
    }
}
int main(){
    MS1(dp);
    RIII(n,m,T);
    REP(i,m){
        DRIII(x,y,v);
        e[x].PB(MP(y,v));
    }
    INF=T+1;
    dfs(1);
    for(int i=n;i>0;i--){
        if(dp[1][i]<=T){
            printf("%d\n",i);
            track(1,i);
            return 0;
        }
    }
    return 0;
}