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
const int SIZE = 5050;
char s[SIZE];
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
    assert(MOD>=SIZE);
    fac[0]=1;
    REPP(i,1,SIZE)fac[i]=fac[i-1]*i%MOD;
    inv[SIZE-1]=mypow(fac[SIZE-1],MOD-2);
    for(int i=SIZE-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%MOD;
}
int lt[SIZE];
int dp[5001][5001],dp0[5001][5001];
void ADD(int &x,LL v){
    x=(x+v)%MOD;
    if(x<0)x+=MOD;
}
int main(){
    build();
    DRI(n);
    RS(s+1);
    int m=1;
    for(int i=2;i<=n;i++){
        if(s[i]!=s[m])s[++m]=s[i];
    }
    {
        int now[26];
        MS1(now);
        REPP(i,1,m+1){
            if(now[s[i]-'a']!=-1){
                lt[i]=now[s[i]-'a'];
            }
            now[s[i]-'a']=i;
        }
    }
    dp[0][0]=1;
    REPP(i,1,m+1){
        dp[i][0]=1;
        REPP(j,1,i+1){
            dp[i][j]=dp[i-1][j];
            dp0[i][j]=dp[i-1][j-1];
            if(lt[i]){
                ADD(dp0[i][j],-dp0[lt[i]][j-1]);
            }
            ADD(dp[i][j],dp0[i][j]);
            ADD(dp[i][j],-dp0[lt[i]][j]);
        }
    }
    int an=0;
    REPP(i,1,m+1){
        if(!dp[m][i])continue;
        ADD(an,dp[m][i]*C(n-1,i-1));
    }
    printf("%d\n",an);
    return 0;
}