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
const int SIZE = 1e5+10;
int a[SIZE];
VI e[SIZE];
LL an=0;
LL dp[SIZE][4];
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
    used[x]=1;
    dp[x][0]=a[x];
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(used[y])continue;
        dfs(y);
        LL tmp[4]={};

        maa(tmp[0],dp[y][0]+a[x]);
        maa(tmp[1],dp[y][0]+dp[x][0]);
        maa(tmp[2],dp[y][0]+dp[x][3]+a[x]);
        maa(an,dp[y][0]+dp[x][1]);
        maa(an,dp[y][0]+dp[x][2]);
        maa(tmp[3],dp[y][0]);

        maa(tmp[2],dp[y][1]+dp[x][0]);
        maa(an,dp[y][1]+dp[x][1]);
        maa(an,dp[y][1]+dp[x][3]);
        maa(tmp[3],dp[y][1]);
        
        maa(tmp[2],dp[y][2]+a[x]);
        maa(an,dp[y][2]+dp[x][0]);
        
        maa(tmp[2],dp[y][3]+dp[x][0]);
        maa(an,dp[y][3]+dp[x][1]);
        maa(an,dp[y][3]+dp[x][3]);
        maa(tmp[3],dp[y][3]);

        REP(j,4)maa(dp[x][j],tmp[j]);
    }
    REP(i,4)maa(an,dp[x][i]);
}
int main(){
    DRI(n);
    REPP(i,1,n+1)RI(a[i]);
    REPP(i,1,n){
        DRII(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    dfs(1);
    cout<<an<<endl;
    return 0;
}