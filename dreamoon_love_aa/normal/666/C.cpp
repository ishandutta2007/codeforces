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
const int SIZE = 1e5+10;
const int HALF = 400;
LL pp[SIZE],pp25[SIZE];
int dp[SIZE][HALF];
void pre(){
    pp[0]=pp25[0]=1;
    REPP(i,1,SIZE){
        pp[i]=pp[i-1]*26%MOD;
        pp25[i]=pp25[i-1]*25%MOD;
    }
    REP(i,SIZE){
        dp[i][0]=pp25[i];
        REPP(j,1,HALF){
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]*25LL)%MOD;
        }
    }
    REP(i,SIZE){
        REPP(j,1,HALF){
            dp[i][j]+=dp[i][j-1];
            if(dp[i][j]>=MOD)dp[i][j]-=MOD;
        }
    }
}
LL an[SIZE];
LL fac[SIZE],inv[SIZE];
LL mypow(LL x,LL y){
    LL res=1;
    while(y){
        if(y&1)res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}
LL C(int x,int y){
    if(y<0||y>x)return 0;
    return fac[x]*inv[y]%MOD*inv[x-y]%MOD;
}
void build(){
    fac[0]=1;
    REPP(i,1,SIZE)fac[i]=fac[i-1]*i%MOD;
    inv[SIZE-1]=mypow(fac[SIZE-1],MOD-2);
    for(int i=SIZE-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%MOD;
}
void re(int v){
    MS0(an);
    an[v]=1;
    REPP(i,v+1,SIZE){
        an[i]=(an[i-1]*26+C(i-1,v-1)*pp25[i-v])%MOD;
    }
}
char s[SIZE];
int main(){
    build();
    pre();
    DRI(m);
    RS(s);
    int v=LEN(s);
    if(v>=HALF)re(v);
    while(m--){
        DRI(ty);
        if(ty==2){
            DRI(x);
            if(v<HALF){
                printf("%I64d\n",(pp[x]-dp[x][v-1]+MOD)%MOD);
            }
            else printf("%I64d\n",an[x]);
        }
        else{
            RS(s);
            v=LEN(s);
            if(v>=HALF)re(v);
        }
    }
    return 0;
}