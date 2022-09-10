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
const int SIZE = 1e5+1;
const int MOD = 1e9+7;
vector<int>fac[SIZE];
LL inv[SIZE],pp[SIZE];
LL mypow(LL x,LL y){
    LL res=1;
    while(y){
        if(y&1)res=res*x%MOD;
        x=x*x%MOD;
        y>>=1;
    }
    return res;
}
void init(){
    pp[0]=1;
    REPP(i,1,SIZE)pp[i]=pp[i-1]*i%MOD;
    inv[SIZE-1]=mypow(pp[SIZE-1],MOD-2);
    for(int i=SIZE-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%MOD;
    REPP(i,1,SIZE){
        for(int j=i;j<SIZE;j+=i)fac[j].PB(i);
    }
}
LL C(int x,int y){
    if(y<0||y>x)return 0;
    return pp[x]*inv[y]%MOD*inv[x-y]%MOD;
}
LL dp[SIZE];
int main(){
    init();
    DRI(Q);
    while(Q--){
        DRII(n,k);
        vector<int>consider;
        REP(i,SZ(fac[n])){
            if((LL)fac[n][i]*k<=n)consider.PB(fac[n][i]);
        }
        for(int i=SZ(consider)-1;i>=0;i--){
            dp[i]=C(n/consider[i]-k+(k-1),k-1);
            REPP(j,i+1,SZ(consider)){
                if(consider[j]%consider[i]==0){
                    dp[i]-=dp[j];
                    if(dp[i]<0)dp[i]+=MOD;
                }
            }
        }
        cout<<dp[0]<<endl;
    }
    return 0;
}