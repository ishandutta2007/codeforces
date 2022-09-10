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
LL mypow(LL x,LL y){
    x%=MOD;
    LL res=1%MOD;
    while(y){
        if(y&1)res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}
LL an[SIZE];
vector<pair<int,int> >e[SIZE];
LL dp[SIZE],sp[SIZE];
int cnt[SIZE];
void add(LL &x,LL v){
    x=(x+v)%MOD;
}
void dfs1(int x,int lt){
    dp[x]=1;
    sp[x]=1;
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        if(y==lt)continue;
        dfs1(y,x);
        if((dp[y]+1)%MOD!=0){
            sp[x]=sp[x]*(dp[y]+1)%MOD;
        }
        else cnt[x]++;
        dp[x]=dp[x]*(dp[y]+1)%MOD;
    }
}
void dfs2(int x,int lt,LL v){
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        if(y==lt)continue;
        LL me;
        if(cnt[x]>1)me=0;
        else{
            if(cnt[x]==1){
                if((dp[y]+1)%MOD==0)me=sp[x];
                else me=0;
            }
            else{
                me=dp[x]*mypow(dp[y]+1,MOD-2)%MOD;
            }
        }
        an[y]=v*me%MOD;
        an[y]=(an[y]+1)*dp[y]%MOD;
        dfs2(y,x,(me*v+1)%MOD);
    }
}
void add(int x,int y,int v=1){
    e[x].PB(MP(y,v));
    e[y].PB(MP(x,v));
}
int main(){
    DRI(N);
    REPP(i,1,N){
        DRI(x);
        x--;
        add(x,i);
    }
    dfs1(0,-1);
    an[0]=dp[0];
    dfs2(0,-1,1);
    REP(i,N){
        an[i]%=MOD;
        if(an[i]<0)an[i]+=MOD;
        if(i)putchar(' ');
        printf("%I64d",an[i]);
    }
    return 0;
}