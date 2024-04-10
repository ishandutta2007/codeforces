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
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 998244353;
const int SIZE = 2017;
int dp[SIZE][11];
int fac[SIZE];
int C[SIZE][SIZE];
void ADD(int &x,LL v){
    x=(x+v)%MOD;
}
int mod11(int x){
    if(x>=11)x-=11;
    if(x<0)x+=11;
    return x;
}
void solve(VI oe[]){
    int odd_n=SZ(oe[1]);
    int even_n=SZ(oe[0]);
    MS0(dp);
    dp[0][0]=1;
    int need_pos=(odd_n+1)/2;
    REP(i,odd_n){
        for(int j=need_pos;j>=0;j--){
            int tmp[11]={};
            REP(k,11){
                if(!dp[j][k])continue;
                ADD(dp[j+1][mod11(k+oe[1][i])],dp[j][k]);
                ADD(tmp[mod11(k-oe[1][i])],dp[j][k]);
            }
            memcpy(dp[j],tmp,sizeof(int)*11);
        }
    }
    int res[11];
    memcpy(res,dp[need_pos],sizeof(int)*11);
#ifdef HOME
    REP(i,11)printf("%d,",res[i]);
    puts("");
#endif
    MS0(dp);
    dp[0][0]=1;
    REP(i,even_n){
        for(int j=even_n;j>=0;j--){
            int tmp[11]={};
            REP(k,11){
                if(!dp[j][k])continue;
                ADD(dp[j+1][mod11(k+oe[0][i])],dp[j][k]);
                ADD(tmp[mod11(k-oe[0][i])],dp[j][k]);
            }
            memcpy(dp[j],tmp,sizeof(int)*11);
        }
    }
    if(!odd_n){
        printf("%d\n",(int)((LL)dp[even_n][0]*fac[even_n]%MOD));
        return;
    }
    int ans=0;
    REP(i,even_n+1){
        REP(j,11){
            int need_v=(11-j)%11;
            ADD(ans,(LL)res[need_v]*dp[i][j]%MOD*fac[i]%MOD*fac[even_n-i]%MOD*C[(odd_n+2)/2-1+i][i]%MOD*C[(odd_n+1)/2-1+(even_n-i)][even_n-i]%MOD*fac[need_pos]%MOD*fac[odd_n-need_pos]);
        }
    }
    printf("%d\n",ans);
}
int main(){
    REP(i,SIZE){
        C[i][0]=1;
        REPP(j,1,i+1){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
            if(C[i][j]>=MOD)C[i][j]-=MOD;
        }
    }
    fac[0]=1;
    REPP(i,1,SIZE){
        fac[i]=(LL)fac[i-1]*i%MOD;
    }
    char s[12];
    CASET{
        DRI(n);
        VI oe[2];
        REP(i,n){
            RS(s);
            int sn=LEN(s);
            int r=0;
            REP(i,sn){
                int v=s[sn-1-i]-'0';
                if(i&1)r-=v;
                else r+=v;
            }
            r%=11;
            if(r<0)r+=11;
            oe[sn&1].PB(r);
        }
        solve(oe);
    }
    return 0;
}