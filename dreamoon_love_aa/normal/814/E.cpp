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
const int SIZE = 1e6+10;
map<pair<PII,PII>,LL>dp[51];
int a[51];
LL fac[SIZE],inv[SIZE];
void ADD(LL& x,LL v){
    x=(x+v)%MOD;
}
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
int main(){
    build();
    DRI(n);
    REP(i,n)RI(a[i]);
    REPP(i,1,a[0]+1)a[i]--;
    PII O=MP(0,0);
    dp[0][MP(O,O)]=1;
    REPP(p,1,n+1){
        for(auto it=dp[p-1].begin();it!=dp[p-1].end();it++){
            PII pre=it->F.F;
            PII suf=it->F.S;
            //printf("p(%d):(%d,%d),(%d,%d):%lld\n",p,pre.F,pre.S,suf.F,suf.S,it->S);
            if(p<=a[0]){
                REP(i,suf.F+1)for(int j=0;j<=suf.S&&i+j<=a[p];j++){
                    int r=a[p]-i-j;
                    ADD(dp[p][MP(O,MP(suf.F-i+(r==1)+j,suf.S-j+(r==2)))],it->S*C(suf.F,i)%MOD*C(suf.S,j)%MOD);
                }
            }
            else{
                if(pre==O){
                    REP(i,suf.F+1)for(int j=0;j<=suf.S&&i+j<=a[p];j++){
                        int r=a[p]-i-j;
                        if(i+j!=1)continue;
                        if(r==a[p])continue;
                        ADD(dp[p][MP(MP(suf.F-i+j,suf.S-j),MP(r==1,r==2))],it->S*C(suf.F,i)%MOD*C(suf.S,j)%MOD);
                    }
                }
                else{
                    REP(i,suf.F+1)for(int j=0;j<=suf.S&&i+j<=a[p];j++){
                        for(int u=0;u<=pre.F&&i+j+u<=a[p];u++)
                            for(int v=0;v<=pre.S&&i+j+u+v<=a[p];v++){
                                if(u+v!=1)continue;
                                int r=a[p]-i-j-u-v;
                                ADD(dp[p][MP(MP(pre.F-u+v,pre.S-v),MP(suf.F-i+j+(r==1),suf.S-j+(r==2)))],it->S*C(suf.F,i)%MOD*C(suf.S,j)%MOD*C(pre.F,u)%MOD*C(pre.S,v)%MOD);
                            }
                    }
                }
            }
        }
    }
    cout<<dp[n-1][MP(O,O)]<<endl;
    return 0;
}