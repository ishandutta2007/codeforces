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
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 2e3+10;
int d;
vector<int>e[SIZE];
int a[SIZE],tt,used[SIZE];
pair<int,int>L;
LL dp[SIZE];
void dfs(int x){
    used[x]=tt;
    dp[x]=1;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(used[y]==tt)continue;
        if(MP(a[y],y)<L)continue;
        if(a[y]-L.F>d)continue;
        dfs(y);
        dp[x]*=(1+dp[y]);
        dp[x]%=MOD;
    }
}
int main(){
    int n;
    RII(d,n);
    REP(i,n)RI(a[i]);
    REPP(i,1,n){
        DRII(x,y);
        x--;y--;
        e[x].PB(y);
        e[y].PB(x);
    }
    LL an=0;
    REP(i,n){
        L=MP(a[i],i);
        tt++;
        dfs(i);
        an+=dp[i];
    }
    cout<<an%MOD<<endl;
    return 0;
}