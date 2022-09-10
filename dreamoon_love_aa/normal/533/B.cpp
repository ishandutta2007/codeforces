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
const int MOD = 1e9+7;
const int SIZE = 2e5+10;
int p[SIZE],a[SIZE];
vector<int>e[SIZE];
LL an,dp[SIZE][2][2];
pair<int,int>ma_ty[SIZE];
void dfs(int x){
    if(SZ(e[x])==0){
        dp[x][0][0]=0;
        dp[x][0][1]=-1e11;
        dp[x][1][1]=a[x];
    }
    else{
        dp[x][1][1]=a[x];
        LL mi=1e11;
        LL sum=0;
        int eo=0;
        REP(i,SZ(e[x])){
            int y=e[x][i];
            dfs(y);
            sum+=dp[y][ma_ty[y].F][ma_ty[y].S];
            eo^=ma_ty[y].S;
        }
        if(!eo){
            dp[x][1][1]+=sum;
            dp[x][0][0]=sum;
            REP(i,SZ(e[x])){
                int y=e[x][i];
                REP(j,2)REP(k,2){
                    if(j==1&&k==0)continue;
                    if(ma_ty[y].S!=k)mi=min(mi,dp[y][ma_ty[y].F][ma_ty[y].S]-dp[y][j][k]);
                }
            }
            dp[x][0][1]=sum-mi;
        }
        else{
            dp[x][0][1]=sum;
            REP(i,SZ(e[x])){
                int y=e[x][i];
                REP(j,2)REP(k,2){
                    if(j==1&&k==0)continue;
                    if(ma_ty[y].S!=k)mi=min(mi,dp[y][ma_ty[y].F][ma_ty[y].S]-dp[y][j][k]);
                }
            }
            dp[x][0][0]=sum-mi;
            dp[x][1][1]+=sum-mi;
        }
    }
    ma_ty[x]=MP(0,0);
    REP(i,2)REP(j,2){
        if(i==1&&j==0)continue;
        if(dp[x][i][j]>dp[x][ma_ty[x].F][ma_ty[x].S]){
            ma_ty[x]=MP(i,j);
        }
    }
    //REP(i,2)REP(j,2)printf("dp[%d][%d][%d]=%d\n",x,i,j,dp[x][i][j]);
}
int main(){
    DRI(n);
    int st;
    REPP(i,1,n+1){
        RII(p[i],a[i]);
        if(p[i]!=-1)e[p[i]].PB(i);
        else{
            st=i;
        }
    }
    dfs(st);
    printf("%I64d\n",max(dp[st][0][0],max(dp[st][0][1],dp[st][1][1])));
    return 0;
}