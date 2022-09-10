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
const int SIZE = 1e6+10;
// template end here
vector<int>e[SIZE];
int dp[SIZE];
void err(){
    puts("No");
    exit(0);
}
int dfs(int x,int lt){
    int cnt[6]={};
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(lt==y)continue;
        dfs(y,x);
        cnt[dp[y]]++;
    }
    if(cnt[5])err();
    else if(cnt[4]>1)err();
    else if(cnt[4]){
        if(cnt[3]+cnt[2]+cnt[1]||cnt[0]>1)err();
        if(cnt[0]==1)dp[x]=5;
        else dp[x]=4;
    }
    else if(cnt[3]>1)err();
    else if(cnt[3]==1){
        if(cnt[2]+cnt[1]||cnt[0]>2)err();
        if(cnt[0]==2)dp[x]=5;
        else dp[x]=4;
    }
    else if(cnt[2]>2)err();
    else if(cnt[2]==2){
        dp[x]=3;
    }
    else if(cnt[2]==1){
        dp[x]=2;
    }
    else if(cnt[1]){
        dp[x]=2;
    }
    else{
        if(cnt[0]>2)dp[x]=2;
        else if(cnt[0]>1)dp[x]=1;
        else dp[x]=0;
    }
    //printf("dp[%d]=%d\n",x,dp[x]);
    return dp[x];
}
int main(){
    DRI(N);
    REPP(i,1,N){
        DRII(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    dfs(1,1);
    puts("Yes");
    return 0;
}