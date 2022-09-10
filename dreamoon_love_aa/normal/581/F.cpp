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
const int SIZE = 5e3+10;
// template end here
vector<int>e[SIZE];
int one,num[SIZE];
int dp[SIZE][2][SIZE];
bool mii(int &x,int v){
    if(x==-1||x>v){
        x=v;
        return 1;
    }
    return 0;
}
void dfs(int x,int lt){
    if(SZ(e[x])==1){
        dp[x][0][0]=0;
        dp[x][1][1]=0;
        num[x]=1;
        return;
    }
    dp[x][0][0]=dp[x][1][0]=0;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(y==lt)continue;
        dfs(y,x);
        for(int j=num[x];j>=0;j--){
            REP(v1,2){
                if(dp[x][v1][j]!=-1){
                    int me=dp[x][v1][j];
                    dp[x][v1][j]=-1;
                    for(int k=num[y];k>=0;k--){
                        REP(v2,2){
                            if(dp[y][v2][k]!=-1)mii(dp[x][v1][j+k],me+dp[y][v2][k]+(v1^v2));
                        }
                    }
                }
            }
        }
        num[x]+=num[y];
    }
}
int main(){
    DRI(n);
    if(n==2)return 0*puts("1");
    MS1(dp);
    REPP(i,1,n){
        DRII(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    int st;
    REPP(i,1,n+1){
        if(SZ(e[i])!=1)st=i;
        else one++;
    }
    dfs(st,st);
    printf("%d",min(dp[st][0][one/2],dp[st][1][one/2]));
    return 0;
}